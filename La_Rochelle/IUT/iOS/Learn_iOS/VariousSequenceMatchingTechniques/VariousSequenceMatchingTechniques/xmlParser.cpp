/*!
  \author Bastien Meunier
  \date 20/01/2015
*/

#include "xmlParser.h"
using namespace inout;

void *XMLParser::readFile(void *document)
{

    
    int type = -1;
    std::vector<model::Sequence*> * s = new std::vector<model::Sequence*>();
    rapidxml::xml_document<>  *docr = (rapidxml::xml_document<char> *)document;
    if(docr->first_node("Sequences")== 0)
    {
        delete s;
        exc::SequenceMatchingException::genererException("XML Reading error : Invalid file format",ERREUR_FILE,__LINE__);
    }


    // Take the type
    rapidxml::xml_node<> * type_node;
    type_node = docr->first_node("Type");
    if(type_node==0)
    {
        delete s;
        exc::SequenceMatchingException::genererException("XML Reading error : Invalid type tag ",ERREUR_FILE,__LINE__);
    }
    // Take the type attribute
    rapidxml::xml_attribute<> * type_attr = type_node->first_attribute("id");
    if(type_attr==0)
    {
        delete s;
        exc::SequenceMatchingException::genererException("XML Reading error : Invalid type tag ",ERREUR_FILE,__LINE__);
    }

    type = atoi(type_attr->value());
    // Take the First sequence
    rapidxml::xml_node<> * seq_node;
    seq_node = docr->first_node("Sequence");
    if(seq_node == 0)
    {
        delete s;
        exc::SequenceMatchingException::genererException("XML Reading error : Invalid format ",ERREUR_FILE,__LINE__);
    }
    do
    {

        // Create sequence
        model::Sequence * seq = new model::Sequence();

        rapidxml::xml_attribute<> * id_attr = seq_node->first_attribute("idS");
        if(id_attr==0)
        {
            delete seq;
            delete s;
            exc::SequenceMatchingException::genererException("XML Reading error : Invalid type tag ",ERREUR_FILE,__LINE__);
        }
        string sid(id_attr->value(),id_attr->value_size());
        seq->setUid(sid);
        // Iterate elements
        rapidxml::xml_node<> * elt_node;
        elt_node = seq_node->first_node("Element");
        if(elt_node == 0)
        {
            delete s;
            delete seq;
            exc::SequenceMatchingException::genererException("XML Reading error : Invalid type tag ",ERREUR_FILE,__LINE__);
        }
        if(type==CHARACTER)
        {
            do
            {
                // Iterate element
                rapidxml::xml_attribute<> * id_attr = elt_node->first_attribute("id");
                model::Character * cha = new model::Character;
                cha->setUid(id_attr->value());
                rapidxml::xml_attribute<> * val_attr = elt_node->first_attribute("value");
                cha->setValue(val_attr->value()[0]);
                seq->addElement(cha);
                elt_node = elt_node->next_sibling();
            }
            while(elt_node != 0);
        }
        else if(type == NUMERIC)
        {
            do
            {
                // Iterate element
                rapidxml::xml_attribute<> * id_attr = elt_node->first_attribute("id");
                rapidxml::xml_attribute<> * val_attr = elt_node->first_attribute("value");
                if(id_attr == 0 || val_attr == 0)
                {
                    delete s;
                    delete seq;
                    exc::SequenceMatchingException::genererException("XML Reading error : Invalid type tag ",ERREUR_FILE,__LINE__);
                }
                model::Numeric* nu = new model::Numeric;
                string fid(id_attr->value(),id_attr->value_size());
                nu->setUid(fid);
                string fn(val_attr->value(),val_attr->value_size());
                nu->setValue((float) atof(fn.c_str()));
                seq->addElement(nu);
                elt_node = elt_node->next_sibling();
            }
            while(elt_node != 0);
        }
        else if(type == VECTOR)
        {

            do
            {
                // Iterate element

                rapidxml::xml_node<> * vec_node;
                vec_node = elt_node->first_node("VectorElement");
                if(vec_node ==0)
                {
                    delete seq;
                    delete s;
                    exc::SequenceMatchingException::genererException("XML Reading error : Invalid type tag ",ERREUR_FILE,__LINE__);
                }

                rapidxml::xml_attribute<> * id_attr = elt_node->first_attribute("id");
                if(id_attr == 0 )
                {
                    delete s;
                    delete seq;
                    exc::SequenceMatchingException::genererException("XML Reading error : Invalid type tag ",ERREUR_FILE,__LINE__);
                }
                model::CharacteristicVector* vec = new model::CharacteristicVector;
                vec->setUid(id_attr->value());
                do
                {
                    // Iterate vector
                    rapidxml::xml_attribute<> * vecval_attr = vec_node->first_attribute("id");
                    if(vecval_attr == 0 )
                    {
                        delete s;
                        delete seq;
                        delete vec;
                        exc::SequenceMatchingException::genererException("XML Reading error : Invalid type tag ",ERREUR_FILE,__LINE__);
                    }
                    string vv = string(vecval_attr->value(),vecval_attr->value_size());
                    vec->addValue((float) atof(vv.c_str()));
                    vec_node = vec_node->next_sibling();
                }
                while(vec_node != 0);
                seq->addElement(vec);
                elt_node = elt_node->next_sibling();
            }
            while(elt_node != 0);
        }
        else
        {
            delete seq;
            delete s;
            exc::SequenceMatchingException::genererException("XML Reading error : Invalid type tag ",ERREUR_FILE,__LINE__);
        }
        // Iterate
        s->push_back(seq);
        seq_node = seq_node->next_sibling();
    }
    while(seq_node != 0);

    docr->clear();

    delete docr;

    return s;
}