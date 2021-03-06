/*!
  \author Abdourahman Aden Hassan
  \date 24/12/2013
  \author Bastien Meunier
  \date 21/01/2015
 */
#include "commandlineoutput.h"
#include "Exc.h"
#include "typeinfo"
#include "cstdlib"
#include <cfloat>

#include <typeinfo>


using namespace inout;
using namespace std;
string CommandLineOutput::formattageLevensthein(calc::ResultatCorrespondance *r)
{
    stringstream res;
    res<<"Result \nDistance = "<<r->distance<<endl;
    stringstream ss1;
    stringstream ss2;
    stringstream ss;
    unsigned int it = 0;
    unsigned int tailleMaxSeq1 = tailleMaxElement(sCLOseq1)+1;
    unsigned int tailleMaxSeq2 = tailleMaxElement(sCLOseq2)+1;

    while(it<r->correspondanceT1->size())
    {
        // CAS TRANSEQ
        if(r->correspondanceT1->at(it)>=TRANSEQ)
        {
            ss << EGAL<<getSpace(max(tailleMaxSeq2,tailleMaxSeq1)-1);
            ss1 <<sCLOseq1->getElement(r->correspondanceT1->at(it)-TRANSEQ)->toString()<<getSpace(max(tailleMaxSeq2,tailleMaxSeq1)-sCLOseq1->getElement(r->correspondanceT1->at(it)-TRANSEQ)->toString().size());
            ss2 <<sCLOseq2->getElement(r->correspondanceT2->at(it)-TRANSEQ)->toString()<<getSpace(max(tailleMaxSeq2,tailleMaxSeq1)-sCLOseq2->getElement(r->correspondanceT2->at(it)-TRANSEQ)->toString().size());
        }
        else if(r->correspondanceT1->at(it)>=TRANS)
        {
            ss <<SUB<<getSpace(max(tailleMaxSeq2,tailleMaxSeq1)-1);
            ss1<<sCLOseq1->getElement(r->correspondanceT1->at(it)-TRANS)->toString()<<getSpace(max(tailleMaxSeq2,tailleMaxSeq1)-sCLOseq1->getElement(r->correspondanceT1->at(it)-TRANS)->toString().size());
            ss2<<sCLOseq2->getElement(r->correspondanceT2->at(it)-TRANS)->toString()<<getSpace(max(tailleMaxSeq2,tailleMaxSeq1)-sCLOseq2->getElement(r->correspondanceT2->at(it)-TRANS)->toString().size());
        }
        else if(r->correspondanceT1->at(it)>=DEL || r->correspondanceT2->at(it)>=DEL )
        {
            ss<<SUPPRESS<<getSpace(max(tailleMaxSeq2,tailleMaxSeq1)-1);
            if(r->correspondanceT1->at(it)>=DEL){
                ss1<<sCLOseq1->getElement(r->correspondanceT1->at(it)-DEL)->toString()<<getSpace(max(tailleMaxSeq2,tailleMaxSeq1)-sCLOseq1->getElement(r->correspondanceT1->at(it)-DEL)->toString().size());
                ss2<<NO<<getSpace(max(tailleMaxSeq2,tailleMaxSeq1)-1);
            }
            else{
                ss1<<NO<<getSpace(max(tailleMaxSeq2,tailleMaxSeq1)-1);
                ss2<<sCLOseq2->getElement(r->correspondanceT2->at(it)-DEL)->toString()<<getSpace(max(tailleMaxSeq2,tailleMaxSeq1)-sCLOseq2->getElement(r->correspondanceT2->at(it)-DEL)->toString().size());
            }
        }
        else if(r->correspondanceT1->at(it)>=ADD || r->correspondanceT2->at(it)>=ADD )
        {
            ss<<ADDING<<getSpace(max(tailleMaxSeq2,tailleMaxSeq1)-1);
            if(r->correspondanceT1->at(it)>=ADD){

                ss1<<sCLOseq1->getElement(r->correspondanceT1->at(it)-ADD)->toString()<<getSpace(max(tailleMaxSeq2,tailleMaxSeq1)-sCLOseq1->getElement(r->correspondanceT1->at(it)-ADD)->toString().size());
                ss2<<NO<<getSpace(max(tailleMaxSeq2,tailleMaxSeq1)-1);
            }
            else{

                ss1<<NO<<getSpace(max(tailleMaxSeq2,tailleMaxSeq1)-1);
                ss2 <<sCLOseq2->getElement(r->correspondanceT2->at(it)-ADD)->toString()<<getSpace(max(tailleMaxSeq2,tailleMaxSeq1)-sCLOseq2->getElement(r->correspondanceT2->at(it)-ADD)->toString().size());
            }
        }
        it = it+1;
    }
    res<<"Correspondance \n"<<std::endl;
    res<<ss1.str()<<std::endl;
    res<<ss.str()<<std::endl;
    res<<ss2.str()<<std::endl;
    return string(res.str());
}


string CommandLineOutput::formattageLCS(calc::ResultatCorrespondance *r)
{
    stringstream ret;
    ret<<"Result \nDistance = "<<r->distance<<endl;
    stringstream ss1;
    stringstream ssq1;
    stringstream ssq2;
    stringstream ss2;
    stringstream seq;
    seq<<"{";
    unsigned int it = 0;
    unsigned int tailleMaxSeq1 = tailleMaxElement(sCLOseq1)+1;
    unsigned int tailleMaxSeq2 = tailleMaxElement(sCLOseq2)+1;
    while(it<r->correspondanceT1->size())
    {
        ss1<<sCLOseq1->getElement(it)->toString()<<getSpace(max(tailleMaxSeq2,tailleMaxSeq1)-sCLOseq1->getElement(it)->toString().size());
        if(r->correspondanceT1->at(it)==1)
        {
            ssq1<< sCLOseq1->getElement(it)->toString()<<getSpace(max(tailleMaxSeq2,tailleMaxSeq1)-sCLOseq1->getElement(it)->toString().size());
            seq<<sCLOseq1->getElement(it)->toString()<<" ";
        }
        else
        {
            ssq1<< "-"<<getSpace(max(tailleMaxSeq2,tailleMaxSeq1)-1);
        }
        it = it + 1;
    }
    it = 0;
    while(it<r->correspondanceT2->size())
    {
        ss2<<sCLOseq2->getElement(it)->toString()<<getSpace(max(tailleMaxSeq2,tailleMaxSeq1)-sCLOseq2->getElement(it)->toString().size());
        if(r->correspondanceT2->at(it)==1)
        {
            ssq2<< sCLOseq2->getElement(it)->toString()<<getSpace(max(tailleMaxSeq2,tailleMaxSeq1)-sCLOseq2->getElement(it)->toString().size());
        }
        else
        {
            ssq2<<"-"<<getSpace(max(tailleMaxSeq2,tailleMaxSeq1)-1);
        }
        it = it + 1;
    }
    ret<<"Correspondance \n"<<std::endl;
    ret<<ss1.str()<<std::endl;
    ret<<ssq1.str()<<std::endl;
    ret<<ssq2.str()<<std::endl;
    ret<<ss2.str()<<std::endl;
    ret<<"Longest common sequence : "<<seq.str()<<"}"<<std::endl;
    return (string(ret.str()));
}


string CommandLineOutput::formattageType1(calc::ResultatCorrespondance *r)
{
    stringstream ret;
    ret<<"Result \nDistance = "<<r->distance<<endl;
    ret<<"Correspondance \n"<<std::endl;
    int it1 = 0;
    int it2 = 0;
    unsigned int tailleMaxSeq1 = tailleMaxElement(sCLOseq1)+1;
    unsigned int tailleMaxSeq2 = tailleMaxElement(sCLOseq2)+1;
	string *** tabS = new string**[sCLOseq1->getSize()];
    it1 = 0;
    while(it1<sCLOseq1->getSize())
    {
        tabS[it1] = new string*[sCLOseq2->getSize()];
        it1 = it1 + 1;
    }
    it1 = 0;
    while(it1<sCLOseq1->getSize())
    {
        while(it2<sCLOseq2->getSize())
        {
            tabS[it1][it2] = new string("-"+getSpace(max(tailleMaxSeq2,tailleMaxSeq1)-1));
            it2 = it2 + 1;
        }
        it2 = 0;
        it1 = it1 + 1;
    }
    unsigned int itC = 0;
    while(itC<r->correspondanceT1->size())
    {
        delete(tabS[r->correspondanceT1->at(itC)][r->correspondanceT2->at(itC)]);
        tabS[r->correspondanceT1->at(itC)][r->correspondanceT2->at(itC)] = new string("x"+getSpace(max(tailleMaxSeq2,tailleMaxSeq1)-1));
        itC = itC + 1;
    }
    it1 = 0;
    it2 = 0;
    ret<<getSpace(max(tailleMaxSeq2,tailleMaxSeq1));
    while(it1<sCLOseq2->getSize())
    {
        ret<<sCLOseq2->getElement(it1)->toString()<<getSpace(max(tailleMaxSeq2,tailleMaxSeq1)-sCLOseq2->getElement(it1)->toString().size());
        it1 = it1 + 1;
    }
    ret<<""<<std::endl;
    it1 = 0;
    it2 = 0;
    while(it1<sCLOseq1->getSize())
    {
        stringstream ss2;
        ss2 << sCLOseq1->getElement(it1)->toString()<<getSpace(max(tailleMaxSeq2,tailleMaxSeq1)-sCLOseq1->getElement(it1)->toString().size());
        while(it2<sCLOseq2->getSize())
        {
            ss2<<*tabS[it1][it2];
            it2 = it2 + 1;
        }
        ret<<ss2.str()<<std::endl;
        it2 = 0;
        it1 = it1 + 1;
    }
    // delete tab
    it1 = 0;
    it2 = 0;
    while(it1<sCLOseq1->getSize())
    {
        while(it2<sCLOseq2->getSize())
        {
            delete tabS[it1][it2];
            it2 = it2 +1;
        }
        delete tabS[it1];
        it1 = it1 + 1;
        it2 = 0;
    }
    delete tabS;
    return string(ret.str());
}

string CommandLineOutput::formattageType2(calc::ResultatCorrespondance *r)
{
    stringstream ret;
    ret<<r->distance<<": ";
    unsigned int it1 = 0;
    while(it1 < r->correspondanceT2->size())
    {
		if(it1 != 0)
			ret<<",";
		ret << r->correspondanceT2->at(it1) <<"->"<<r->correspondanceT1->at(it1);
        it1 = it1 + 1;
    }
    return string(ret.str());
}

unsigned int CommandLineOutput::tailleMaxElement(model::Sequence *s)
{
    unsigned int it = 0;
    unsigned int tailleMax = 0;
    while(it<(unsigned int)s->getSize())
    {
        unsigned int size = s->getElement(it)->toString().size();
        if(size>tailleMax){
            tailleMax = size;
        }
        it = it + 1;
    }
    return tailleMax;
}

string CommandLineOutput::getSpace(unsigned int size)
{
    stringstream ss;
    unsigned int it = 0;
    while(it<size)
    {
        ss<<" ";
        it = it + 1;
    }
    return ss.str();
}



inout::CommandLineOutput::CommandLineOutput(model::Sequence *s1, model::Sequence *s2, calc::Correspondance *c)
{
    sCLOseq1 = s1;
    sCLOseq2 = s2;
    cCLOcor = c;
}

void CommandLineOutput::show()
{
    std::cout<<format()<<std::endl;
}

string CommandLineOutput::showInFormat()
{
	stringstream ret;
	ret<<format()<<endl;
	return (string)(ret.str());
}
string CommandLineOutput::format()
{
    stringstream ret;
    vector<calc::ResultatCorrespondance > *vRc = 0;
	unsigned i = 0;
    if(typeid(*cCLOcor)==typeid(calc::LevenstheinCorrespondance))
    {
		vRc = cCLOcor->correspondre(sCLOseq1,sCLOseq2);
		for(i=0;i < vRc->size();i++)
			ret<< formattageLevensthein(&(vRc->at(i)))<<endl;
    }
    else if(typeid(*cCLOcor)==typeid(calc::LCScorrespondance))
    {
		vRc = cCLOcor->correspondre(sCLOseq1,sCLOseq2);
		for(i=0;i < vRc->size();i++)
			ret<< formattageLCS(&(vRc->at(i)))<<endl;
    }
    else if(typeid(*cCLOcor)==typeid(calc::DTWCorrespondance))
    {
		vRc = cCLOcor->correspondre(sCLOseq1,sCLOseq2);
       for(i=0;i < vRc->size();i++)
			ret<< formattageType2(&(vRc->at(i)))<<endl;
    }
    else if(typeid(*cCLOcor)==typeid(calc::MvmCorrespondance))
    {
        // Inversion MVM
        if(sCLOseq1->getSize()<sCLOseq2->getSize())
        {
            model::Sequence * sTemp = sCLOseq1;
            sCLOseq1 = sCLOseq2;
            sCLOseq2 = sTemp;
        }
		vRc = cCLOcor->correspondre(sCLOseq1,sCLOseq2);
        for(i=0;i < vRc->size();i++)
			ret<< formattageType2(&(vRc->at(i)))<<endl;
    }
	 else if(typeid(*cCLOcor)==typeid(calc::CDPCorrespondance))
    {
		vRc = cCLOcor->correspondre(sCLOseq1,sCLOseq2);
        for(i=0;i < vRc->size();i++)
			ret<< formattageType2(&(vRc->at(i)))<<endl;
	}
	else if(typeid(*cCLOcor)==typeid(calc::FSMCorrespondance))
    {
		vRc = cCLOcor->correspondre(sCLOseq1,sCLOseq2);
        for(i=0;i < vRc->size();i++)
			ret<< formattageType2(&(vRc->at(i)))<<endl;
	}
	while(!vRc->empty()){
		vRc->pop_back();
	}
	delete vRc;
    return string(ret.str());
}

float CommandLineOutput::getResult()
{
    vector<calc::ResultatCorrespondance > *vRc = 0;
    if(typeid(*cCLOcor)==typeid(calc::LevenstheinCorrespondance))
    {
        vRc = cCLOcor->correspondre(sCLOseq1,sCLOseq2);
    }
    else if(typeid(*cCLOcor)==typeid(calc::LCScorrespondance))
    {
        vRc = cCLOcor->correspondre(sCLOseq1,sCLOseq2);
    }
    else if(typeid(*cCLOcor)==typeid(calc::DTWCorrespondance))
    {
        vRc = cCLOcor->correspondre(sCLOseq1,sCLOseq2);
    }
    else if(typeid(*cCLOcor)==typeid(calc::MvmCorrespondance))
    {
        // Inversion MVM
        if(sCLOseq1->getSize()>sCLOseq2->getSize())
        {
            model::Sequence * sTemp = sCLOseq1;
            sCLOseq1 = sCLOseq2;
            sCLOseq2 = sTemp;
        }
        vRc = cCLOcor->correspondre(sCLOseq1,sCLOseq2);
    }
	 else if(typeid(*cCLOcor)==typeid(calc::CDPCorrespondance))
    {
		vRc = cCLOcor->correspondre(sCLOseq1,sCLOseq2);
	}

	 else if(typeid(*cCLOcor)==typeid(calc::FSMCorrespondance))
    {
		vRc = cCLOcor->correspondre(sCLOseq1,sCLOseq2);
	}
	float minD = FLT_MAX;
	for(unsigned int i = 0; i < vRc->size();i++){
		if(vRc->at(i).distance <= minD)
			minD = vRc->at(i).distance;
	}
	while(!vRc->empty()){
		vRc->pop_back();
	}
	delete vRc;
    return minD;
}
