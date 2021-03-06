/*!
  \author Abdourahman Aden Hassan
  \date 20/12/2013
 */
#include "characteristicvector.h"
#include "typeinfo"
#include "Exc.h"
#include "math.h"

using namespace model;
CharacteristicVector::CharacteristicVector()
{
    Element::quidEid = "";
    vCVlist = new vector<float>();
}



CharacteristicVector::CharacteristicVector(CharacteristicVector const & copy)

{
    Element::quidEid = copy.quidEid;
    vCVlist = new vector<float>();
    int it = 0;
    int max = copy.vCVlist->size();
    while(it<max)
    {
        vCVlist->insert(vCVlist->begin(),copy.vCVlist->at(it));
        it = it + 1;
    }
}

CharacteristicVector::~CharacteristicVector()
{
    delete vCVlist;
}

float CharacteristicVector::getAt(unsigned int id)
{
    if(id>vCVlist->size()){
        exc::SequenceMatchingException::genererException("Size error",PARAMETRE_INVALIDE,__LINE__);
    }
    return vCVlist->at(id);
}

void CharacteristicVector::addValue(float elt)
{
    vCVlist->push_back(elt);
}

void CharacteristicVector::removeValue(unsigned int index)
{
    if(index>=vCVlist->size()){
        exc::SequenceMatchingException::genererException("Size error",PARAMETRE_INVALIDE,__LINE__);
    }
    vCVlist->erase(vCVlist->begin()+index);
}

void CharacteristicVector::setValue(unsigned int index, float value)
{
    if(index>=vCVlist->size()){
        exc::SequenceMatchingException::genererException("Size error",PARAMETRE_INVALIDE,__LINE__);
    }
    vCVlist->at(index) = value;
}

int CharacteristicVector::getSize()
{
    return vCVlist->size();
}

float CharacteristicVector::distance(Element* eOD1, Element* eOD2)
{
    CharacteristicVector a;
    if(typeid(*eOD1)!=typeid(*eOD2) || typeid(*eOD2)!=typeid(a)){
        exc::SequenceMatchingException::genererException("Typing error",PARAMETRE_INVALIDE,__LINE__);
    }
    CharacteristicVector *c1 = (CharacteristicVector*)eOD1;
    CharacteristicVector *c2 = (CharacteristicVector*)eOD2;
    if(c1->vCVlist->size()!= c2->vCVlist->size()){
        exc::SequenceMatchingException::genererException("Size error",PARAMETRE_INVALIDE,__LINE__);
    }
    float ret = 0.0;
    if(c1->vCVlist->size() != 0){
        int it = 0;
        int size = c1->vCVlist->size();
        while(it<size){
            ret= ret + powf((float)c1->vCVlist->at(it)-(float)c2->vCVlist->at(it),2);
            it = it+1;
        }
    }
    return sqrt(ret);
}

string CharacteristicVector::toString()
{

    stringstream ss;
    ss << "[";
    unsigned int it = 0;
    while(it<vCVlist->size())
    {
        ss <<"["<<vCVlist->at(it)<<"] ";
        it = it +1;
    }
    ss << "]";

    return ss.str();
}

Element *CharacteristicVector::copy()
{

    CharacteristicVector *a = new CharacteristicVector();
    a->setUid(this->getUid());
    int it = 0;
    while(it<this->getSize())
    {
        a->addValue(this->getAt(it));
        it = it + 1;
    }
    return a;
}
