#include <stdio.h>
#include "InOut.h"
#include "UnitTest.h"
#include "CommandLine.h"
#include "commandlineapplication.h"
#include "commandlineapplicationpourcentage.h"
#include "Exc.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <string.h>
using namespace std;
int main(int argc, char *argv[])
{
	clock_t begin = clock();
	commandline::CommandLine *c;
	if(argc > 2 && strcmp((const char *)argv[1],"-pourcentage")==0)
        c = new commandline::CommandLineApplicationClassMatchnig(argc,argv);
    else
        c = new commandline::CommandLineApplication(argc,argv);
    try{
		c->run();
    }
    catch(exc::SequenceMatchingException & e)
    {
        std::cout<<e.what()<<std::endl;
        std::cout<<"Gestion des paramètres toolbox :\n\narguments :\n\n-sequences <fichier1.csv> <fichier2.csv>\n\nPermet d indiquer les séquences d entrée\n\n-method lvn|lcd|dtw|mvmm|cdp\n\nPermet d indiquer la méthode à utiliser\n\n-patron <name> <fichier1.csv> <fichier2.csv>\n\nPermet de créer un patron\n\n-sequences <fichier1.csv> <fichier2.csv> -param <fichier.xml>\n\nPermet d utiliser un fichier de paramètres créé auparavant\n\n-method lvn  --costs 1 1 1\n\nCout d ajout suppression substitution levensthein"<<std::endl;
    }

//	int test = 0;
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << "Fini avec " << elapsed_secs << " secondes" << endl;
    return 0;
}
