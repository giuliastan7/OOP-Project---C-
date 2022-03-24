//
// Created by giulia on 5/17/2021.
//

#ifndef PROIECTOOP_REPOSITORY_H
#define PROIECTOOP_REPOSITORY_H


#pragma once
#include "Contract.h"
#include "Contract_copii.h"
#include "vector"
#include "RepositoryException.h"
#include "vector"
class Repository
{
protected:
    vector<Contract*> contracte;

public:
    Repository();
    ~Repository();
    void update( Contract *,  Contract * );
    vector<Contract*> getAll();
    int getSize();
    Contract* getElem(int index);
    Contract* getElemById(char *);
    void add(Contract *c);
    void stergereRepo(Contract *c);
    void empty();
    vector <Contract*> Repository::getAllAdulti(char *firma, int &dim);
    void sortareDupaPuncte();

};


#endif //PROIECTOOP_REPOSITORY_H
