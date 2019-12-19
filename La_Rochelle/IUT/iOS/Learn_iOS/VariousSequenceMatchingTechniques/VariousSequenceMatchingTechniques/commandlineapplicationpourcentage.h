/*!
  \author Abdourahman Aden Hassan
          Bastien Meunier
  \date 05/01/2014
        20/01/2015
  \package commandline
  \class CommandLineApplicationClassMatchnig
  \brief Class for checking the error rate of the algorithm
*/
#ifndef COMMANDLINEAPPLICATIONCLASSMATCHING_H
#define COMMANDLINEAPPLICATIONCLASSMATCHING_H

#include "CommandLine.h"

namespace commandline{
class CommandLineApplicationClassMatchnig : public CommandLine
{
public:
    CommandLineApplicationClassMatchnig(int argc, char *argv[]) : CommandLine(argc,argv){};
    /*!
     * \brief run
     * Fonction qui effectue les traitements demandés
     * cf help
     */
    void run();
};
}
#endif // COMMANDLINEAPPLICATION_H
