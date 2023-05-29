#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H
#include <iostream>
#include <vector>

class DocumentManager {
    public:

std::vector<int> patrons;
std::vector<int> docID;
std::vector<std::string> docname;
std::vector<int> doclicense_limit;
std::vector<int> borrowed;

void addDocument(std::string name, int id, int license_limit);

void addPatron(int patronID);

int search(std::string name); // returns docid if name is in the document collection or 0 if the name is not in the collection

bool borrowDocument(int docid, int patronID);  // returns true if document is borrowed, false if it can not be borrowed (invalid patronid or the number of copies current borrowed has reached the license limit)

void returnDocument(int docid, int patronID);
};

#endif
