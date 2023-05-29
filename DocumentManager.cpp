#include "DocumentManager.h"

void DocumentManager::addDocument(std::string name, int id, int license_limit){
    
    //name
    
    DocumentManager* pCrawl =this;
    
    for (int level = 0; level < name.size(); level++) 
    {
        // Converts name current character into index
        // use only 'a' through 'z' and lower case
        int index = (int)name[level] - (int)'a'; 
        if (pCrawl->children[index]==nullptr){
            pCrawl->children[index] = new DocumentManager;
        }
        pCrawl = pCrawl->children[index];
    }
 
    // mark last node as leaf
    pCrawl->isWordEnd = true;
    pCrawl->docid = id;
    pCrawl->limit =license_limit;
    //
    
    
}

void DocumentManager::addPatron(int patronID){
 patrons.push_back(patronID);
}

bool DocumentManager::borrowDocument(int docid, int patronID){
    for (int i=0; i<patrons.size(); i++){
        if (patrons[i]==patronID){
            return true;
        }
    }
    
    return false;
    
    
}


void DocumentManager::returnDocument(int docid, int patronID){
    
    
}


int DocumentManager::search(std::string name) // returns docid if name is in the document collection or 0 if the name is not in the collection
{
        DocumentManager* pCrawl = this;
    for (char c : name) 
    {
        int ind = (int)c - (int)'a';
        pCrawl = pCrawl->children[ind];
    }
    if (pCrawl->isWordEnd==true){
        return docid;
    }

    return 0;
}
