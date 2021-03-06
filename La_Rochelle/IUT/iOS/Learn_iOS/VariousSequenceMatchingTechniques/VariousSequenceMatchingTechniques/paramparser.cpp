/*!
  \author Bastien Meunier
  \date 20/01/2015
*/

#include "paramparser.h"
#include "Exc.h"
#include <typeinfo>
#include "rapidxml-1.13/rapidxml_utils.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"
using namespace inout;
using namespace std;

void * ParamParser::readFile(void *document)
{
    char * filename = (char *)document;
    rapidxml::xml_document<> docr;
    std::ifstream ifs(filename);
    if(!ifs.is_open())
    {
        exc::SequenceMatchingException::genererException("XML Reading error : Unable to open the file",ERREUR_FILE,__LINE__);
    }
    vector<char> buffer((istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());
    buffer.push_back('\0');
    docr.parse<0>(&buffer[0]);

    std::vector<calc::Parametrage*> * s = new std::vector<calc::Parametrage*>();

    rapidxml::xml_node<> * list_node;
    if((list_node = docr.first_node("Lists"))== 0)
    {
        exc::SequenceMatchingException::genererException("XML Reading error : Invalid file format",ERREUR_FILE,__LINE__);
    }
    // Take the root
    rapidxml::xml_node<> * comp_node;
    comp_node = list_node->first_node("Comparaison");
    if(comp_node == 0)
    {
        exc::SequenceMatchingException::genererException("XML Reading error : Invalid file format",ERREUR_FILE,__LINE__);
    }
    do
    {
        // Création objets parametrage
        calc::Parametrage * par = 0;
        int vecsize = 0;
        int it1 = 0;
        int itvec = 0;
        // Création noeuds des attributs
        rapidxml::xml_attribute<> * id1_comp_attr = comp_node->first_attribute("size1");
        int size1Par = atoi(id1_comp_attr->value());
        rapidxml::xml_attribute<> * id2_comp_attr = comp_node->first_attribute("size2");
        int size2Par = atoi(id2_comp_attr->value());
        rapidxml::xml_attribute<> * isVector_comp_attr = comp_node->first_attribute("isVector");

        int isVector = atoi(isVector_comp_attr->value());
        if(isVector==1)
        {
            rapidxml::xml_attribute<> * vecsize_comp_attr = comp_node->first_attribute("sizeVector");
            vecsize = atoi(vecsize_comp_attr->value());
            par = new calc::Parametrage(size1Par,size2Par,vecsize);
        }
        else
        {
            par = new calc::Parametrage(size1Par,size2Par);
        }

        // Weight distance
        rapidxml::xml_attribute<> * wd_comp_attr = comp_node->first_attribute("weightDistance");
        float weightDistanceValue = (float) atof(wd_comp_attr->value());
        par->setDistanceWeight(weightDistanceValue);

		//Levenshtein Param
		rapidxml::xml_node<> * levenshtein_node = comp_node->first_node("LevenshteinParam");
		if(levenshtein_node != 0){
			rapidxml::xml_attribute<> * addcost_lev_attr = levenshtein_node->first_attribute("addCost");
			float addCost = (float) atof(addcost_lev_attr->value());
			rapidxml::xml_attribute<> * delcost_lev_attr = levenshtein_node->first_attribute("delCost");
			float delCost = (float) atof(delcost_lev_attr->value());
			rapidxml::xml_attribute<> * transcost_lev_attr = levenshtein_node->first_attribute("transCost");
			float transCost = (float) atof(transcost_lev_attr->value());
			par->setLevenshteinCost(addCost,delCost,transCost);
		}

		//CDP Param
		rapidxml::xml_node<> * cdp_node = comp_node->first_node("CdpParam");
		if(cdp_node != 0){
			rapidxml::xml_attribute<> * threshold_cdp_attr = cdp_node->first_attribute("threshold");
			float threshold = (float) atof(threshold_cdp_attr->value());
			par->setThreshold(threshold);
		}

		//MVM Param
		rapidxml::xml_node<> * mvm_node = comp_node->first_node("MvmParam");
		if(cdp_node != 0){
			rapidxml::xml_attribute<> * divelastic_mvm_attr = mvm_node->first_attribute("divElast");
			float elastic = (float) atof(divelastic_mvm_attr->value());
			par->setMvMDivElastic(elastic);
		}

		//FSM Param
		rapidxml::xml_node<> * fsm_node = comp_node->first_node("FsmParam");
		if(fsm_node != 0){
			rapidxml::xml_attribute<> * elasticity_fsm_attr = fsm_node->first_attribute("Elasticity");
			int elasticity = (int) atoi(elasticity_fsm_attr->value());
			par->setiPFsmElesticity(elasticity);
			rapidxml::xml_attribute<> * weight_fsm_attr = fsm_node->first_attribute("W");
			float weight = (float) atof(weight_fsm_attr->value());
			par->setfPFsmWeight(weight);
			rapidxml::xml_attribute<> * skipCost_fsm_attr = fsm_node->first_attribute("SkipCost");
			float skipCost = (float) atof(skipCost_fsm_attr->value());
			par->setfPFsmSkipCost(skipCost);
			rapidxml::xml_attribute<> * smallSkipCost_fsm_attr = fsm_node->first_attribute("SmallSkipCost");
			float smallSkipCost = (float) atof(smallSkipCost_fsm_attr->value());
			par->setfPFsmSmallSkipCost(smallSkipCost);
		}

		//Weight values
		rapidxml::xml_node<> * wv_node = comp_node->first_node("weightNode");
		if(wv_node != 0)
		{
			// Créer vecteur 1
			rapidxml::xml_node<> * sw1_node;
			sw1_node = wv_node->first_node("sequenceWeight1");
			if(sw1_node != 0)
			{
				delete par;
				exc::SequenceMatchingException::genererException("XML Reading error : Invalid file format",ERREUR_FILE,__LINE__);
			}
			rapidxml::xml_node<> * v1_node;
			v1_node = sw1_node->first_node("sequenceElement");
			if(v1_node == 0)
			{
				delete par;
				exc::SequenceMatchingException::genererException("XML Reading error : Invalid file format",ERREUR_FILE,__LINE__);
			}
			while(it1<size1Par)
			{
				rapidxml::xml_attribute<> * w1_attr = v1_node->first_attribute("value");
				float vals1 = (float) atof(w1_attr->value());
				par->setS1Weight(it1,vals1);
				it1 = it1 + 1;
				v1_node->next_sibling();
			}
			// Creer vecteur 2
			rapidxml::xml_node<> * sw2_node;
			sw2_node = wv_node->first_node("sequenceWeight2");
			if(sw2_node == 0)
			{
				delete par;
				exc::SequenceMatchingException::genererException("XML Reading error : Invalid file format",ERREUR_FILE,__LINE__);
			}
			rapidxml::xml_node<> * v2_node;
			v2_node = sw2_node->first_node("sequenceElement");
			if(v2_node == 0)
			{
				delete par;
				exc::SequenceMatchingException::genererException("XML Reading error : Invalid file format",ERREUR_FILE,__LINE__);
			}
			it1 = 0;
			while(it1<size2Par)
			{
				rapidxml::xml_attribute<> * w2_attr = v2_node->first_attribute("value");
				float vals2 = (float) atof(w2_attr->value());
				par->setS2Weight(it1,vals2);
				it1 = it1 + 1;
				v2_node = v2_node->next_sibling();
			}
			// Creer vecteur carac
			if(isVector == 1)
			{
				rapidxml::xml_node<> * vec_w;
				vec_w = wv_node->first_node("vectorWeights");
				if(vec_w == 0)
				{
					delete par;
					exc::SequenceMatchingException::genererException("XML Reading error : Invalid file format",ERREUR_FILE,__LINE__);
				}
				rapidxml::xml_node<> * vec_node;
				vec_node = vec_w->first_node("sequenceVectorElement");
				if(vec_node == 0)
				{
					delete par;
					exc::SequenceMatchingException::genererException("XML Reading error : Invalid file format",ERREUR_FILE,__LINE__);
				}
				while(itvec<vecsize && vec_node != 0)
				{
					rapidxml::xml_attribute<> * vec_attr = v1_node->first_attribute("value");
					float vecv = (float) atof(vec_attr->value());
					par->setVecCaracWeight(itvec,vecv);
					itvec = itvec + 1;
				}
			}
			// Créer vecteur matrice
			int itSeq1 = 0;
			int itSeq2 = 0;
			rapidxml::xml_node<> * sm_node;
			sm_node = wv_node->first_node("sequenceMatrix");
			if(sm_node == 0)
			{
				delete par;
				exc::SequenceMatchingException::genererException("XML Reading error : Invalid file format",ERREUR_FILE,__LINE__);
			}
			rapidxml::xml_node<> * mat_node;
			mat_node = sm_node->first_node("sequenceMatrixElement");
			if(mat_node == 0)
			{
				delete par;
				exc::SequenceMatchingException::genererException("XML Reading error : Invalid file format",ERREUR_FILE,__LINE__);
			}
			while(itSeq1<size1Par&& mat_node != 0)
			{

				while(itSeq2 < size2Par && mat_node != 0)
				{

					// Ajout matrice element
					rapidxml::xml_attribute<> * vec_attr = mat_node->first_attribute("value");
					float vecm = (float) atof(vec_attr->value());
					par->setMatrixWeight(itSeq1,itSeq2,vecm);
					mat_node = mat_node->next_sibling();
					itSeq2 = itSeq2 + 1;
				}
				itSeq1 = itSeq1 +1;
				itSeq2 = 0;
			}
		}
        s->push_back(par);
        // Next
        comp_node = comp_node->next_sibling();
    }
    while(comp_node != 0);
    return (void *)s;
}

void inout::ParamParser::createPattern(std::vector<model::Sequence *> * list1, std::vector<model::Sequence *> * list2, char *filename)
{
    int seq1Nb = list1->size();
    int seq2Nb = list2->size();
    int itSeq1 = 0;
    int itSeq2 = 0;
    int iVecCarSize = 0;
    rapidxml::xml_document<>  docr;
    // root declaration
    rapidxml::xml_node<>* decl = docr.allocate_node(rapidxml::node_declaration);
    decl->append_attribute(docr.allocate_attribute("version", "1.0"));
    decl->append_attribute(docr.allocate_attribute("encoding", "utf-8"));
    docr.append_node(decl);
    // root node Params
    //rapidxml::xml_node<>* params_root = docr.allocate_node(rapidxml::node_element, "Parametres");
    //docr.append_node(params_root);
    // root node Lists
    rapidxml::xml_node<>* lists_root = docr.allocate_node(rapidxml::node_element, "Lists");
    docr.append_node(lists_root);
    int itComparaisons = 0;
    if(seq1Nb<1 || seq2Nb<1)
    {
        exc::SequenceMatchingException::genererException("Pattern creating error : Invalid size ",ERREUR_FILE,__LINE__);
    }
    // Parcours liste 1
    while(itSeq1 < seq1Nb)
    {
        // Taille  Sequences > 0
        int seq1Size = ((model::Sequence *)list1->at(itSeq1))->getSize();
        int seq2Size = ((model::Sequence *)list2->at(itSeq2))->getSize();
        if(seq1Size<=0 || seq2Size<0)
        {
            exc::SequenceMatchingException::genererException("Pattern creating error : Invalid size ",ERREUR_FILE,__LINE__);
        }
        // Parcours liste 2
        while(itSeq2<seq2Nb)
        {
            // Creation elements
            rapidxml::xml_node<>* comparaison_root = docr.allocate_node(rapidxml::node_element, "Comparaison");
            stringstream ss;
            ss << itComparaisons;
            char * snumber = new char[ss.str().size()+1];
            snumber[ss.str().size()] = '\0';
            sprintf(snumber,"%d",itComparaisons);
            comparaison_root->append_attribute(docr.allocate_attribute("number", snumber));
            lists_root->append_node(comparaison_root);
            listPoubelle.push_back(snumber);
            // Taille  Sequences > 0
            seq2Size = ((model::Sequence *)list2->at(itSeq2))->getSize();
            ss.flush();
            ss<<seq1Size;
             char * snumber2 = new char[ss.str().size()+1];
            sprintf(snumber2,"%d",seq1Size);
            comparaison_root->append_attribute(docr.allocate_attribute("size1",snumber2));
            listPoubelle.push_back(snumber2);

            ss.flush();
            ss<<seq2Size;
            snumber2 = new char[ss.str().size()+1];
            sprintf(snumber2,"%d",seq2Size);
            comparaison_root->append_attribute(docr.allocate_attribute("size2", snumber2));
            listPoubelle.push_back(snumber2);
            ss.flush();
            ss<<1;
            snumber2 = new char[ss.str().size()+1];
            sprintf(snumber2,"%d",1);
            comparaison_root->append_attribute(docr.allocate_attribute("weightDistance", snumber2));
            listPoubelle.push_back(snumber2);

            if(seq2Size<=0)
            {
                exc::SequenceMatchingException::genererException("Pattern creating error : Invalid size ",ERREUR_FILE,__LINE__);
            }
            // Même type
            if(typeid(*(((model::Sequence *)list1->at(itSeq1))->getElement(0)))!= typeid(*(((model::Sequence *)list2->at(itSeq2))->getElement(0))))
            {
                exc::SequenceMatchingException::genererException("Pattern creating error : Invalid type ",ERREUR_FILE,__LINE__);
            }

            model::Element * elet = (((model::Sequence *)list2->at(itSeq2))->getElement(0));
            model::CharacteristicVector * cv = new model::CharacteristicVector();
            // Vecteur carac même taille
            if(typeid(*elet)== typeid(*cv))
            {
                if(((model::CharacteristicVector *)((model::Sequence *)list2->at(itSeq2))->getElement(0))->getSize()
                        != ((model::CharacteristicVector *)((model::Sequence *)list1->at(itSeq1))->getElement(0))->getSize())
                {
                    delete cv;
                    exc::SequenceMatchingException::genererException("Pattern creating error : Invalid characteristic vector size ",ERREUR_FILE,__LINE__);
                }

                iVecCarSize = ((model::CharacteristicVector *)((model::Sequence *)list2->at(itSeq2))->getElement(0))->getSize();

                ss.flush();
                ss<<1;
                char * snumber2 = new char[ss.str().size()+1];
                sprintf(snumber2,"%d",1);
                comparaison_root->append_attribute(docr.allocate_attribute("isVector", snumber2));
                listPoubelle.push_back(snumber2);
                ss.flush();
                ss<<iVecCarSize;
                snumber2 = new char[ss.str().size()+1];
                sprintf(snumber2,"%d",iVecCarSize);
                comparaison_root->append_attribute(docr.allocate_attribute("sizeVector", snumber2));
                listPoubelle.push_back(snumber2);


                //Weights veccar


                rapidxml::xml_node<>* vec_weights_root = docr.allocate_node(rapidxml::node_element, "vectorWeights");
                comparaison_root->append_node(vec_weights_root);
                int itVec = 0;
                while(itVec<iVecCarSize)
                {

                    rapidxml::xml_node<>* vec_weights_val = docr.allocate_node(rapidxml::node_element, "sequenceVectorElement");
                    ss.flush();
                    ss<<itVec;
                    char * snumber2 = new char[ss.str().size()+1];
                    sprintf(snumber2,"%d",itVec);
                    vec_weights_val->append_attribute(docr.allocate_attribute("id", snumber2));
                    listPoubelle.push_back(snumber2);
                    ss.flush();
                    ss<<1;
                    snumber2 = new char[ss.str().size()+1];
                    sprintf(snumber2,"%d",1);
                    vec_weights_val->append_attribute(docr.allocate_attribute("value", snumber2));
                    listPoubelle.push_back(snumber2);
                    vec_weights_root->append_node(vec_weights_val);
                    itVec = itVec+1;
                }
            }
            else{
                ss.flush();
                ss<<0;
                char * snumber2 = new char[ss.str().size()+1];
                sprintf(snumber2,"%d",0);
                comparaison_root->append_attribute(docr.allocate_attribute("isVector", snumber2));
                listPoubelle.push_back(snumber2);

            }
            delete cv;

            //Weights seq 1 seq 2 distance

            rapidxml::xml_node<>* w_distance_root = docr.allocate_node(rapidxml::node_element, "weigtDistance");
            ss.flush();
            ss<<1;
            snumber2 = new char[ss.str().size()+1];
            sprintf(snumber2,"%d",1);
            snumber2[ss.str().size()] = '\0';
            w_distance_root->append_attribute(docr.allocate_attribute("value", snumber2));
            listPoubelle.push_back(snumber2);
            comparaison_root->append_node(w_distance_root);

            rapidxml::xml_node<>* w_seq1_root = docr.allocate_node(rapidxml::node_element, "sequenceWeight1");
            comparaison_root->append_node(w_seq1_root);
			char * sid1 = new char[((model::Sequence *)list1->at(itSeq1))->getUid().size()+1];
			sprintf(sid1,"%s",((model::Sequence *)list1->at(itSeq1))->getUid().c_str());
            listPoubelle.push_back(sid1);
            w_seq1_root->append_attribute(docr.allocate_attribute("id",sid1));

            rapidxml::xml_node<>* w_seq2_root = docr.allocate_node(rapidxml::node_element, "sequenceWeight2");
			char * sid2 = new char[((model::Sequence *)list2->at(itSeq2))->getUid().size()+1];
			sprintf(sid2,"%s",((model::Sequence *)list2->at(itSeq2))->getUid().c_str());
            w_seq2_root->append_attribute(docr.allocate_attribute("id",sid2));
            listPoubelle.push_back(sid2);
            comparaison_root->append_node(w_seq2_root);

            int itSW1 = 0;
            while(itSW1<seq1Size)
            {

                rapidxml::xml_node<>* w_seqelt_root = docr.allocate_node(rapidxml::node_element, "sequenceElement");
                ss.flush();
                ss<<itSW1;
                char * snumber2 = new char[ss.str().size()+1];
                sprintf(snumber2,"%d",itSW1);
                w_seqelt_root->append_attribute(docr.allocate_attribute("id", snumber2));
                listPoubelle.push_back(snumber2);
                ss.flush();
                ss<<1;
                snumber2 = new char[ss.str().size()+1];
                sprintf(snumber2,"%d",1);
                w_seqelt_root->append_attribute(docr.allocate_attribute("value", snumber2));
                listPoubelle.push_back(snumber2);
                w_seq1_root->append_node(w_seqelt_root);
                itSW1 = itSW1+1;
            }

            int itSW2 = 0;
            while(itSW2<seq2Size)
            {
                rapidxml::xml_node<>* w_seqelt_root = docr.allocate_node(rapidxml::node_element, "sequenceElement");
                ss.flush();
                ss<<itSW2;
                char * snumber2 = new char[ss.str().size()+1];
                sprintf(snumber2,"%d",itSW2);
                w_seqelt_root->append_attribute(docr.allocate_attribute("id", snumber2));
                listPoubelle.push_back(snumber2);
                ss.flush();
                ss<<1;
                snumber2 = new char[ss.str().size()+1];
                sprintf(snumber2,"%d",1);
                w_seqelt_root->append_attribute(docr.allocate_attribute("value", snumber2));
                listPoubelle.push_back(snumber2);
                w_seq2_root->append_node(w_seqelt_root);
                itSW2 = itSW2+1;
            }

            itSW1 = 0;
            itSW2 = 0;

            rapidxml::xml_node<>* w_seqmat_root = docr.allocate_node(rapidxml::node_element, "sequenceMatrix");
            comparaison_root->append_node(w_seqmat_root);

            while(itSW1<seq1Size)
            {
                while(itSW2<seq2Size)
                {
                    rapidxml::xml_node<>* w_seqmatelt_root = docr.allocate_node(rapidxml::node_element, "sequenceMatrixElement");
                    ss.flush();
                    ss<<itSW1;
                    char * snumber2 = new char[ss.str().size()+1];
                    sprintf(snumber2,"%d",itSW1);
                    w_seqmatelt_root->append_attribute(docr.allocate_attribute("i", snumber2));
                    listPoubelle.push_back(snumber2);
                    ss.flush();
                    ss<<itSW2;
                    snumber2 = new char[ss.str().size()+1];
                    sprintf(snumber2,"%d",itSW2);
                    w_seqmatelt_root->append_attribute(docr.allocate_attribute("j", snumber2));
                    listPoubelle.push_back(snumber2);
                    ss.flush();
                    ss<<1;
                    snumber2 = new char[ss.str().size()+1];
                    sprintf(snumber2,"%d",1);
                    w_seqmatelt_root->append_attribute(docr.allocate_attribute("value", snumber2));
                    listPoubelle.push_back(snumber2);
                    w_seqmat_root->append_node(w_seqmatelt_root);
                    itSW2 = itSW2 + 1;
                }
                itSW2 = 0;
                itSW1 = itSW1 + 1;
            }

            itSeq2 = itSeq2 + 1;
            itComparaisons = itComparaisons+1;
        }
        itSeq2 = 0;
        itSeq1 = itSeq1 +1;
    }
    std::ofstream myfile(filename);
    if(!myfile.is_open())
    {

        exc::SequenceMatchingException::genererException("Pattern creating error : Unable to save the file",ERREUR_FILE,__LINE__);
    }
    myfile<<docr;
    myfile.close();
    docr.clear();


}
