/*!
  \author Abdourahman Aden Hassan
  \date 05/01/2014
  \modified Bastien Meunier
  \date 20/01/2015
*/
#include "commandlineapplicationpourcentage.h"
#include "Exc.h"
#include <cstring>
#include <cstdlib>
#include <cfloat>
#include <string.h>
#include <stdio.h>
#include <omp.h>
using namespace commandline;

void CommandLineApplicationClassMatchnig::run()
{
    checkParams();
    bool ok = false;
    bool isCorr = false;
    float cost1 = 1;
    float cost2 = 1;
    float cost3 = 1;
    bool isParamFile = false;
	string file1 = "";
	bool directoryResult = false;
    std::vector<model::Sequence*> * sq1 = NULL;
    std::vector<model::Sequence*> * sq2 = NULL;
    std::vector<calc::Parametrage*> * par = 0;
	vector<string> classSeq1;
	vector<string> classSeq2;
	int size1 = 0;
	int size2 = 0;
    char *lopname = NULL;
    int typealgo = 0;
    while(vCLAoperateurs.size()>0)
    {
        char * loperator = vCLAoperateurs.at(vCLAoperateurs.size()-1);
        if(strcmp((const char *)loperator,(const char *)_patron)==0)
        {
            // Fichiers de Patron
            lopname =  vCLAoperandes.at(0);
            vCLAoperandes.erase(vCLAoperandes.begin());
            char * lops1 =  vCLAoperandes.at(0);
            vCLAoperandes.erase(vCLAoperandes.begin());
            char * lops2 =  vCLAoperandes.at(0);
            vCLAoperandes.erase(vCLAoperandes.begin());
			inout::SequenceParser* s = 0;
            void * q1 = 0;
            void * q2 = 0;
            try{
				s = new inout::CSVParser();
				q1 = s->readFile(lops1);
                q2 = s->readFile(lops2);
            }
            catch(exception e)
            {
                std::cout<<e.what()<<std::endl;
            }

			s = new inout::XMLParser();
            sq1 = (std::vector<model::Sequence*> *)s->readFile(q1);
            sq2 = (std::vector<model::Sequence*> *)s->readFile(q2);

            ok = true;
        }
        else if(strcmp((const char *)loperator,(const char *)_seq)==0)
        {
            // Fichiers de sequence
            char * lops1 =  vCLAoperandes.at(0);
            vCLAoperandes.erase(vCLAoperandes.begin());
            char * lops2 =  vCLAoperandes.at(0);
            vCLAoperandes.erase(vCLAoperandes.begin());
			if(!directoryResult)
				file1 = (string) lops1;

			inout::SequenceParser* s1 = 0;
			inout::SequenceParser* s2 = 0;
			void * q1;
			void * q2;
			int numProcess = omp_get_num_procs();
			#pragma omp parallel sections num_threads(numProcess)
			{
				#pragma omp section
				{
					//if(strstr(lops1,".csv") == NULL){
						s1 = new inout::EXTParserClassMatchnig();
						q1 = s1->readFile(lops1);
						classSeq1 = s1->classes;
				/*	}else{
						s1 = new inout::CSVParser();
						q1 = s1->readFile(lops1);
					}*/
					s1 = new inout::XMLParser();
					sq1 = (std::vector<model::Sequence*> *)s1->readFile(q1);
				}
				#pragma omp section
				{
				//	if(strstr(lops2,".csv") == NULL){
						s2 = new inout::EXTParserClassMatchnig();
						q2 = s2->readFile(lops2);
						classSeq2 = s2->classes;
				/*	}else{
						s2 = new inout::CSVParser();
						q2 = s2->readFile(lops2);
					}*/
					s2 = new inout::XMLParser();
					sq2 = (std::vector<model::Sequence*> *)s2->readFile(q2);
				}
			}
            ok = true;
            isCorr = true;
			//cout << "Parse finished" << endl;
        }
        else if(strcmp((const char *)loperator,(const char *)_method)==0)
        {
            // Méthode
            char * lops1 =  vCLAoperandes.at(0);
            vCLAoperandes.erase(vCLAoperandes.begin());
            if(strcmp((const char *)lops1,_m1)==0)
            {
                typealgo = 0;
            }
            else if(strcmp((const char *)lops1,_m2)==0)
            {
                typealgo = 1;
            }

            else if(strcmp((const char *)lops1,_m3)==0)
            {
                typealgo = 2;
            }

            else if(strcmp((const char *)lops1,_m4)==0)
            {
                typealgo = 3;
            }
			 else if(strcmp((const char *)lops1,_m5)==0)
            {
                typealgo = 4;
            }
            else if(strcmp((const char *)lops1,_m6)==0)
            {
                typealgo = 5;
            }

        }
        else if(strcmp((const char *)loperator,(const char *)_param)==0)
        {
            // Param
            char * lops1 =  vCLAoperandes.at(0);
            vCLAoperandes.erase(vCLAoperandes.begin());
            inout::ParamParser parp;
            par = (std::vector<calc::Parametrage*> *)parp.readFile(lops1);
            isParamFile = true;
        }
		else if(strcmp((const char *)loperator,(const char *)_dir)==0)
        {
            // Directory of resultat
            char * lops1 =  vCLAoperandes.at(0);
            vCLAoperandes.erase(vCLAoperandes.begin());
            directoryResult = true;
			file1 = lops1;
        }
        else if(strcmp((const char *)loperator,(const char *)_cost)==0)
        {
            // Cost
            char * lops1 =  vCLAoperandes.at(0);
            vCLAoperandes.erase(vCLAoperandes.begin());

            char * lops2 =  vCLAoperandes.at(0);
            vCLAoperandes.erase(vCLAoperandes.begin());

            char * lops3 =  vCLAoperandes.at(0);
            vCLAoperandes.erase(vCLAoperandes.begin());
            cost1 = (float) atof(lops1);
            cost2 = (float) atof(lops2);
            cost3 = (float) atof(lops3);

        }

        vCLAoperateurs.pop_back();
    }
    if(ok)
    {
        if(!isCorr)
        {
            // Creation patron
            inout::ParamParser p;
            p.createPattern(sq1,sq2,lopname);
        }
        else
        {
			//sq1 = cible
			//sq2 = reference

			size1 = sq1->size();
			size2 = sq2->size();
            // Correspondance
            int it1 = 0;
            int it2 = 0;
			vector<float> tabS;

			int numProcess = omp_get_num_procs();
			{
				for(it1 = 0; it1 <size1;it1++)
				{

					#pragma omp parallel for ordered schedule(dynamic) num_threads(numProcess)
					for(it2 = 0; it2 <size2;it2++)
					{
						calc::Correspondance * cor = 0;

						if(typealgo == 0)
						{
							if(isParamFile)
							{
								cor = new calc::LevenstheinCorrespondance(par->at(it1));
							}
							else
							{
								cor = new calc::LevenstheinCorrespondance(cost1,cost2,cost3);
							}
						}
						else if(typealgo == 1)
						{
							if(isParamFile)
							{
								cor = new calc::LCScorrespondance(par->at(it1));
							}
							else
							{
								cor = new calc::LCScorrespondance();
							}
						}
						else if(typealgo == 2)
						{
							if(isParamFile)
							{
								cor = new calc::DTWCorrespondance(par->at(it1));
							}
							else
							{
								cor = new calc::DTWCorrespondance();
							}
						}
						else if(typealgo == 3)
						{
							if(isParamFile)
							{
								cor = new calc::MvmCorrespondance(par->at(it1));
							}
							else
							{
								cor = new calc::MvmCorrespondance();
							}
						}
						else if(typealgo == 4){
							if(isParamFile)
							{
								cor = new calc::CDPCorrespondance(par->at(it1));
							}
							else
							{
								cor = new calc::CDPCorrespondance();
							}
						}
						else {
							if(isParamFile)
							{
								cor = new calc::FSMCorrespondance(par->at(it1));
							}
							else
							{
								cor = new calc::FSMCorrespondance();
							}
						}
						inout::CommandLineOutput c(sq2->at(it2),sq1->at(it1),cor);

						#pragma omp ordered
						tabS.push_back(c.getResult());
						delete cor;
					}

				}
			}

			it1 = 0;
			it2 = 0;
			int it = 0;
			int  correct = 0;
			float best = FLT_MAX;
			string predicted = "";
			//cout << "Calcul finished "<< endl;
			//cout << tabS.size() << endl << size1*size2 << endl;
			for(it1 = 0 ; it1<size1;it1++)
			{
				best = FLT_MAX;
				predicted = "";
				//cout << "classe ref: " << classSeq1.at(it1) << endl;
				for(it2 = 0; it2 < size2; it2++)
				{
                    if(best > tabS.at(it))
					{
						best = tabS.at(it);
						predicted = classSeq2.at(it2);
					//	cout << predicted << endl;
					}
					it++;
				}
				if(strcmp(predicted.c_str(),classSeq1.at(it1).c_str()) == 0)
					correct++;
			}
			unsigned found = file1.find_last_of("/\\");
            file1 = file1.substr(0,found);
            found = file1.find_last_of("/\\");
            file1 = file1.substr(found+1);
            float erreur = (float) (1.00*(size1 - correct)/(size1));
			cout << file1 << ": " << erreur << endl;
        }
        int it = 0;
        int it2 = 0;
        while(it<size1)
        {
            delete sq1->at(it);
            it = it + 1;
        }
        while(it2<size2)
        {
            delete sq2->at(it2);
            it2 = it2 + 1;
        }
        if(par!=0)
        {
            unsigned int itp = 0;
            while(itp<par->size())
            {
                delete par->at(itp);
                itp = itp +1;
            }
            delete par;
        }
        delete sq1;
        delete sq2;
    }

}
