/*!
  \modified Bastien Meunier
  \date 20/01/2015
*/

#include "sequenceparser.h"
#include "Exc.h"
#ifdef TARGET_OS_MAC
// Linux Includes Here
  #include "uuid/uuid.h"
#elif defined __linux__
// Linux Includes Here
  #include "uuid/uuid.h"
#endif
using namespace inout;

SequenceParser::SequenceParser()
{
    vecteur = 1;
}

SequenceParser::~SequenceParser()
{
    // On vide la poubelle
    unsigned int itLP = 0;
    while(itLP<listPoubelle.size())
    {
        free(listPoubelle.at(itLP));
        itLP = itLP + 1;
    }

}

int SequenceParser::checkDocument(vector<string> list)
{
    int it = 0;
    bool validity = true;
    int type = -1;
    // Check minimal size
    if(list.size()<7)
    {
        exc::SequenceMatchingException::genererException("CSV Reading error : invalid size",ERREUR_FILE,__LINE__);
    }
    // Check 1st elements
    if(validity)
    {
        if(list.at(0).find("SEQUENCE")==string::npos || list.at(1).find("TYPE")==string::npos )
        {
            exc::SequenceMatchingException::genererException("CSV Reading error : no SEQUENCE or TYPE keywords",ERREUR_FILE,__LINE__);
        }
    }
    // Check type
    if(validity)
    {
        if(list.at(2).find("Character")!=string::npos)
        {
            type = CHARACTER;
        }
        if(list.at(2).find("Numeric")!=string::npos)
        {
            type = NUMERIC;
        }
        if(list.at(2).find("Vector")!=string::npos)
        {
            type = VECTOR;
        }
        if(type !=CHARACTER && type != NUMERIC && type !=VECTOR)
        {
            exc::SequenceMatchingException::genererException("CSV Reading error : no type KEYWORD",ERREUR_FILE,__LINE__);
        }
    }
    // Check begin end
    if(validity)
    {
        if(list.at(4).find("BEGIN")==string::npos)
        {
            exc::SequenceMatchingException::genererException("CSV Reading error : no BEGIN",ERREUR_FILE,__LINE__);
        }
        if(list.at(5).find("NEXT")!=string::npos)
        {
            exc::SequenceMatchingException::genererException("CSV Reading error : NEXT shouldn't be here",ERREUR_FILE,__LINE__);
        }
        if(list.at(list.size()-1).find("END")==string::npos)
        {
            exc::SequenceMatchingException::genererException("CSV Reading error : no END",ERREUR_FILE,__LINE__);
        }
    }
    it = 5;
    int end = list.size()-2;
    regex_t s;
    regex_t nots;
    regex_t letter;
    regex_t num;
    if(regcomp(&letter,"^[a-zA-Z]?$", REG_ICASE | REG_EXTENDED))
    {
        exc::SequenceMatchingException::genererException("Unable to compile the regexp",ERREUR_FILE,__LINE__);
    }
    if(regcomp(&num,"^[-+]{,1}[0-9]*[.|,]{,1}[0-9]+$", REG_ICASE | REG_EXTENDED))
    {
        exc::SequenceMatchingException::genererException("Unable to compile the regexp",ERREUR_FILE,__LINE__);
    }
    unsigned int lim = 1000;
    int cas = 0;
    string sseparator = "NEXT";
    // Check numeric
    if(type == NUMERIC)
    {

        if(regcomp(&s,"^[-+]{,1}[0-9]*[.|,]{,1}[0-9]+$", REG_ICASE | REG_EXTENDED))
        {
            exc::SequenceMatchingException::genererException("Unable to compile the regexp",ERREUR_FILE,__LINE__);
        }
        if(regcomp(&nots,"^[a-zA-Z]+$", REG_ICASE | REG_EXTENDED))
        {
            exc::SequenceMatchingException::genererException("Unable to compile the regexp",ERREUR_FILE,__LINE__);
        }
    }
    // Check caracter
    if(type == CHARACTER)
    {
        lim = 1;
        if(regcomp(&s,"^[a-zA-Z]?$", REG_ICASE | REG_EXTENDED))
        {
            exc::SequenceMatchingException::genererException("Unable to compile the regexp",ERREUR_FILE,__LINE__);
        }
        if(regcomp(&nots,"^[-+]{,1}[0-9]*[.|,]{,1}[0-9]+$", REG_ICASE | REG_EXTENDED))
        {
            exc::SequenceMatchingException::genererException("Unable to compile the regexp",ERREUR_FILE,__LINE__);
        }
    }

    while(validity && it<end)
    {
        if(type == VECTOR)
        {
            bool ok = false;
            if(cas == CASSEP)
            {
                if(list.at(it).compare("V")==0 && list.at(it).compare("ENDV")!=0)
                {
                    cas = CASVAL;
                    ok = true;
                }
                if(cas == CASSEP && list.at(it).find("END")==string::npos && list.at(it).find("NEXT")==string::npos)
                {
                    exc::SequenceMatchingException::genererException("CSV Reading error : invalid separator",ERREUR_FILE,__LINE__);
                }
                if(list.at(it).find("NEXT")!=string::npos && (it==(end+1) || list.at(it+1).find("V")==string::npos) )
                {
                    exc::SequenceMatchingException::genererException("CSV Reading error : invalid separator NEXT",ERREUR_FILE,__LINE__);
                }
            }
            if(cas== CASVAL && !ok)
            {
                if(regexec(&letter,list.at(it).c_str(), 0, NULL, 0) == 0 || regexec(&num,list.at(it).c_str(), 0, NULL, 0)!= 0)
                {
                    exc::SequenceMatchingException::genererException("CSV Reading error : invalid type (vector element value)",ERREUR_FILE,__LINE__);

                }
                else{
                    if(list.at(it+1).compare("ENDV")!=0)
                    {
                        cas = CASVAL;
                    }
                    else
                    {
                        cas = CASSEP;
                    }
                    ok = true;
                }
            }
        }
        else
        {

            if(regexec(&s,list.at(it).c_str(), 0, NULL, 0)!=0 || regexec(&nots,list.at(it).c_str(), 0, NULL, 0)==0 ||list.at(it).size()>lim)
            {
                if(list.at(it).compare(sseparator)!=0)
                    exc::SequenceMatchingException::genererException("CSV Reading error : invalid value types (character, numeric)",ERREUR_FILE,__LINE__);
            }
        }

        it = it + 1;
    }
    if(type==CHARACTER || type==NUMERIC)
    {
        regfree(&s);
        regfree(&nots);
    }
    regfree(&num);
    regfree(&letter);
    return type;
}
