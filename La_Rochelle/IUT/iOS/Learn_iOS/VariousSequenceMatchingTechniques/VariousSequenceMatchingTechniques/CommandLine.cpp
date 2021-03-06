/*!
  \author Abdourahman Aden Hassan
  \date 05/01/2014
  \modified Bastien Meunier
  \date 20/01/2015
*/
#include "CommandLine.h"
#include "Exc.h"
#include <cstring>
#include <cstdlib>
#include <cfloat>
#include <string.h>
#include <stdio.h>
#include <omp.h>
using namespace commandline;



CommandLine::CommandLine(int argc, char *argv[])
{
    iCLAargv = argc;
    cCLAargv = argv;
}


void CommandLine::checkParams()
{
    vCLAoperandes.clear();
    vCLAoperateurs.clear();
    if(iCLAargv<3)
    {
        exc::SequenceMatchingException::genererException("Invalid parameters",PARAMETRE_INVALIDE,__LINE__);
    }
    int it = 0;
    int nbseq = 0;
    while(it<iCLAargv)
    {
        // Check patron
        if(strcmp(cCLAargv[it],_patron)==0)
        {
            if(iCLAargv != 5 || it != 1)
            {
                exc::SequenceMatchingException::genererException("Invalid parameters",PARAMETRE_INVALIDE,__LINE__);
            }
            nbseq = nbseq+1;
            vCLAoperateurs.push_back(cCLAargv[it]);
            vCLAoperandes.push_back(cCLAargv[it+1]);
            vCLAoperandes.push_back(cCLAargv[it+2]);
            vCLAoperandes.push_back(cCLAargv[it+3]);
        }
        // Check sequences
		else  if(strcmp(cCLAargv[it],_seq)==0)
        {
            if((it+2)>=iCLAargv)
            {
                exc::SequenceMatchingException::genererException("Invalid parameters",PARAMETRE_INVALIDE,__LINE__);
            }
            nbseq = nbseq+1;
            vCLAoperateurs.push_back(cCLAargv[it]);
            vCLAoperandes.insert(vCLAoperandes.begin(),cCLAargv[it+1]);
            vCLAoperandes.insert(vCLAoperandes.begin(),cCLAargv[it+2]);
        }
        // Check algo
		else if(strcmp(cCLAargv[it],_method)==0)
        {
            if((it+1)>=iCLAargv)
            {
                exc::SequenceMatchingException::genererException("Invalid parameters",PARAMETRE_INVALIDE,__LINE__);
            }
            if(strcmp(cCLAargv[it+1],_m1)!=0 && strcmp(cCLAargv[it+1],_m2)!=0 && strcmp(cCLAargv[it+1],_m3)!=0 && strcmp(cCLAargv[it+1],_m4)!=0 && strcmp(cCLAargv[it+1],_m5)!=0 && strcmp(cCLAargv[it+1],_m6)!=0)
            {
                exc::SequenceMatchingException::genererException("Invalid parameters",PARAMETRE_INVALIDE,__LINE__);
            }
            vCLAoperateurs.push_back(cCLAargv[it]);
            vCLAoperandes.insert(vCLAoperandes.begin(),cCLAargv[it+1]);
        }
        // Check seq param
        else if(strcmp(cCLAargv[it],_param)==0)
        {
            if((it+1)>=iCLAargv)
            {
                exc::SequenceMatchingException::genererException("Invalid parameters",PARAMETRE_INVALIDE,__LINE__);
            }
            vCLAoperateurs.push_back(cCLAargv[it]);
            vCLAoperandes.insert(vCLAoperandes.begin(),cCLAargv[it+1]);
        }
        // Check costs
		else if(strcmp(cCLAargv[it],_cost)==0)
        {
            if((it+3)>=iCLAargv)
            {
                exc::SequenceMatchingException::genererException("Invalid parameters",PARAMETRE_INVALIDE,__LINE__);
            }
            if(it-1<0)
            {
                exc::SequenceMatchingException::genererException("Invalid parameters",PARAMETRE_INVALIDE,__LINE__);
            }
            if(strcmp(cCLAargv[it-1],_m1)!=0)
            {
                exc::SequenceMatchingException::genererException("Invalid parameters",PARAMETRE_INVALIDE,__LINE__);
            }
            vCLAoperateurs.push_back(cCLAargv[it]);
            vCLAoperandes.insert(vCLAoperandes.begin(),cCLAargv[it+1]);
            vCLAoperandes.insert(vCLAoperandes.begin(),cCLAargv[it+2]);
            vCLAoperandes.insert(vCLAoperandes.begin(),cCLAargv[it+3]);
        }
		//check output directory
		else if(strcmp(cCLAargv[it],_dir)==0)
		{
			if((it+1)>=iCLAargv)
            {
                exc::SequenceMatchingException::genererException("Invalid parameters",PARAMETRE_INVALIDE,__LINE__);
            }
            vCLAoperateurs.push_back(cCLAargv[it]);
            vCLAoperandes.insert(vCLAoperandes.begin(),cCLAargv[it+1]);
		}

		/*else if(strcmp(cCLAargv[it],"-pourcentage")!=0)
		{
			exc::SequenceMatchingException::genererException("Invalid parameters",PARAMETRE_INVALIDE,__LINE__);
		}*/
        it = it + 1;
    }
    if(nbseq == 0)
    {
        exc::SequenceMatchingException::genererException("Invalid parameters",PARAMETRE_INVALIDE,__LINE__);
    }
}

