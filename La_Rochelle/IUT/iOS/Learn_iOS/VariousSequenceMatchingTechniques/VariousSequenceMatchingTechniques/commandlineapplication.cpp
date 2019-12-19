/*!
  \author Abdourahman Aden Hassan
  \date 05/01/2014
  \modified Bastien Meunier
  \date 20/01/2015
*/
#include "commandlineapplication.h"
#include "Exc.h"
#include <cstring>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <omp.h>
using namespace commandline;

void CommandLineApplication::run()
{
    checkParams();
    bool ok = false;
    bool isCorr = false;
    float cost1 = 1;
    float cost2 = 1;
    float cost3 = 1;
    bool isParamFile = false;
	string file1 = "";
	char* fileTarget;
	char* filereference;
	string type = "";
	bool directoryResult = false;
    std::vector<model::Sequence*> * sq1 = NULL;
    std::vector<model::Sequence*> * sq2 = NULL;
    std::vector<calc::Parametrage*> * par = 0;

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

			filereference = lops1;
			fileTarget = lops2;
            ok = true;
            isCorr = true;
			//cout << "Parsed finished" << endl;
        }
        else if(strcmp((const char *)loperator,(const char *)_method)==0)
        {
            // Méthode
            char * lops1 =  vCLAoperandes.at(0);
            vCLAoperandes.erase(vCLAoperandes.begin());
            if(strcmp((const char *)lops1,_m1)==0)
            {
                typealgo = 0;
                type = "lev";
            }
            else if(strcmp((const char *)lops1,_m2)==0)
            {
                typealgo = 1;
                type = "lcs";
            }

            else if(strcmp((const char *)lops1,_m3)==0)
            {
                typealgo = 2;
                type = "dtw";
            }

            else if(strcmp((const char *)lops1,_m4)==0)
            {
                typealgo = 3;
                type = "mvm";
            }
			 else if(strcmp((const char *)lops1,_m5)==0)
            {
                typealgo = 4;
                type = "cdp";
            }
			else if(strcmp((const char *)lops1,_m6)==0)
            {
                typealgo = 5;
                type = "fsm";
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
			inout::SequenceParser* s1 = 0;
			inout::SequenceParser* s2 = 0;
			void * q1;
			void * q2;
			int numProcess = omp_get_num_procs();
			#pragma omp parallel sections num_threads(numProcess)
			{
				#pragma omp section
				{
					//if(strstr(filereference,".csv") == NULL){
						s1 = new inout::EXTParser();
						if(par != 0 && !par->empty())
							s1->vecteur = par->at(0)->getVecCaracSize();
						q1 = s1->readFile(filereference);
					/*}else{
						s1 = new inout::CSVParser();
						q1 = s1->readFile(filereference);
					}*/
					s1 = new inout::XMLParser();
					sq1 = (std::vector<model::Sequence*> *)s1->readFile(q1);
				}
				#pragma omp section
				{
					//if(strstr(fileTarget,".csv") == NULL){
						s2 = new inout::EXTParser();
						if(par != 0 && !par->empty())
							s2->vecteur = par->at(0)->getVecCaracSize();
						q2 = s2->readFile(fileTarget);
				/*	}else{
						s2 = new inout::CSVParser();
						q2 = s2->readFile(fileTarget);
					}*/
					s2 = new inout::XMLParser();
					sq2 = (std::vector<model::Sequence*> *)s2->readFile(q2);
				}
			}
			//sq1 : reference
			//sq2 : cible

			size1 = sq1->size();
			size2 = sq2->size();
            // Correspondance
            int it1 = 0;
            int it2 = 0;
			vector<string> tabS;
			string str;
			//int numProcess = omp_get_num_procs();
			// << numProcess << endl;
			{
				for(it1 = 0; it1 <size1;it1++)
				{
					str = "";
					#pragma omp parallel for ordered schedule(dynamic) num_threads(numProcess)
					for(it2 = 0; it2 <size2;it2++)
					{
						calc::Correspondance *cor;

						if(typealgo == 0)
						{
							if(isParamFile)
							{
								cor = new calc::LevenstheinCorrespondance(par->at(0));
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
								cor = new calc::LCScorrespondance(par->at(0));
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
								cor = new calc::DTWCorrespondance(par->at(0));
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
								cor = new calc::MvmCorrespondance(par->at(0));
							}
							else
							{
								cor = new calc::MvmCorrespondance();
							}
						}
						else if(typealgo == 4){
							if(isParamFile)
							{
								cor = new calc::CDPCorrespondance(par->at(0));
							}
							else
							{
								cor = new calc::CDPCorrespondance();
							}
						}
						else {
							if(isParamFile)
							{
								cor = new calc::FSMCorrespondance(par->at(0));
							}
							else
							{
								cor = new calc::FSMCorrespondance();
							}
						}
						inout::CommandLineOutput c(sq2->at(it2),sq1->at(it1),cor);

						#pragma omp ordered
						str += c.showInFormat();
						delete cor;
					}
					tabS.push_back(str);
				}
			}

			int it = 0;

			if(!directoryResult){
                file1 = fileTarget;
                string file2 = filereference;

				unsigned found = file1.find_last_of("/\\");
				string fileTname = file1.substr(found+1);
				file1 = file1.substr(0,found);

				found = fileTname.find_last_of(".");
				fileTname = fileTname.substr(0,found);

				found = file2.find_last_of("/\\");
                string fileRname = file2.substr(found+1);
				found = fileRname.find_last_of(".");
				fileRname = fileRname.substr(0,found);

				#if defined  _WIN32 || defined _WIN64
                    file1 += "\\resultat"+fileRname+"_"+fileTname+"_"+type+"\\";
                #elif defined __linux__
                       file1 += "/resultat"+fileRname+"_"+fileTname+"_"+type+"/";
                #endif
			}

            #if defined _WIN32 || defined _WIN64
                if(file1.at(file1.size()-1) != '\\')
                    file1 += "\\";
                _mkdir(file1.c_str());
            #elif defined __linux__
                if (file1.at(file1.size()-1) != '/')
                    file1 += "/";
                mkdir(file1.c_str(),0777);
            #endif

			//cout << "Calcul finished, result will be in: " << file1 << endl;
			for(it = 0 ; it<size1;it++)
			{
				string result = file1 + std::to_string(it+1) + ".txt";
				std::ofstream outfile (result);
				outfile << tabS.at(it) << std::endl;
				outfile.close();
			}
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
