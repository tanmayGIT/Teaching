/*!
  \author Abdourahman Aden Hassan
          Bastien Meunier
  \date 05/01/2014
        20/01/2015
  \package commandline
  \class CommandeLine abstract
  \brief Class for runing the program
 */
#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include "InOut.h"
#include "Calc.h"
#define _seq "-sequences"
#define _method "-method"
#define _m1 "-lvn"
#define _m2 "-lcs"
#define _m3 "-dtw"
#define _m4 "-mvm"
#define _m5 "-cdp"
#define _m6 "-fsm"
#define _patron "-patron"
#define _param "-param"
#define _cost "--costs"
#define _dir "-resultat"
#if defined __linux__ || TARGET_OS_MAC
#include <sys/stat.h>
#else
// #include <direct.h>
#endif

namespace commandline{
class CommandLine
{
protected:

    int iCLAargv; /*! < the number of input parameter */
    char ** cCLAargv; /*! < the input parameters */
    vector<char *> vCLAoperateurs; /*! < the type of parameter */
    vector<char *> vCLAoperandes; /*! < the values of parameter */

    /*!
     * \brief checkParams
     * Check if the input parameters are in a correct format
     */
    void checkParams();

public:

    /*! \brief Constructor
    */
    CommandLine(int argc, char *argv[]);
    /*!
     * \brief run
     * run the program
     */
    virtual void run() = 0;
};
}
#endif
