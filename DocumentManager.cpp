#include "DocumentManager.h"

void DocumentManager::addDocument(std::string name, int id, int license_limit){
 docID.push_back(id);
 docname.push_back(name);
 doclicense_limit.push_back(license_limit);
 borrowed.push_back(0);
}

void DocumentManager::addPatron(int patronID){
 patrons.push_back(patronID);
}

bool DocumentManager::borrowDocument(int docid, int patronID){
    for (int i=0; i<patrons.size(); i++){
        if (patrons[i]==patronID){
            for (int i=0; i<docID.size(); i++){
                if (docid==docID[i]){
                    if (borrowed[i]<doclicense_limit[i]){
                       borrowed[i]=borrowed[i]+1;
                       return true;
                    }
                }
                
            }
            
        }
    }
    return false;
}


void DocumentManager::returnDocument(int docid, int patronID){
 for (int i=0; i<patrons.size(); i++){
        if (patrons[i]==patronID){
            for (int i=0; i<docID.size(); i++){
                if (docid==docID[i]){
                    if (borrowed[i]>0){
                       borrowed[i]=borrowed[i]-1;
                    }
                }
            }
            
        }
    }
}

int DocumentManager::search(std::string name) // returns docid if name is in the document collection or 0 if the name is not in the collection
{
    for (int i=0; i<docname.size(); i++){
        if (name==docname[i]){
            return docID[i];
        }
    }
    return 0;
}
