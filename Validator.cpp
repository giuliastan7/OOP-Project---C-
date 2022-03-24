//
// Created by giulia on 5/24/2021.
//

#include "Validator.h"

#include "Service.h"
#include "Validator.h"
#include "string.h"
#include"Contract.h"
#include <iostream>

using namespace std;
Validator::Validator()
{

}
Validator::Validator(Service service)
{
    this->service=service;
}
Validator::~Validator()
{

}
int Validator::validare_contract(Contract *contract )
{

    vector <Contract*> a=service.getAll();
    for (int i=0;i<service.getSize();i++)
    {
        if(strcmp(a[i]->get_id(),contract->get_id())==0)
        {
            return 0;
        }
        if(strcmp(a[i]->get_nume_voluntar(),contract->get_nume_voluntar())==0)
        {
            return 3;
        }

    }
    if (contract->get_puncte_nominalizare()<0)
    {
        return 2;
    }
    if(contract->get_id()[0]!='N'&&contract->get_id()[0]!='C'&&contract->get_id()[0]!='A')
        return 4;
    return 1;

}
int Validator::validare_contract(Contract_copii *contract )
{
    //validate id
    vector <Contract*> a=service.getAll();
    for (int i=0;i<service.getSize();i++)
    {
        if(strcmp(a[i]->get_id(),contract->get_id())==0)
        {
            return 0;
        }
        if(strcmp(a[i]->get_nume_voluntar(),contract->get_nume_voluntar())==0)
        {
            return 3;
        }

    }
    if (contract->get_puncte_nominalizare()<0)
    {
        return 2;
    }
    return 1;

}
int Validator::validare_contract(Contract_adulti *contract )
{
    //validate id
    vector <Contract*> a=service.getAll();
    for (int i=0;i<service.getSize();i++)
    {
        if(strcmp(a[i]->get_id(),contract->get_id())==0)
        {
            return 0;
        }
        if(strcmp(a[i]->get_nume_voluntar(),contract->get_nume_voluntar())==0)
        {
            return 3;
        }

    }
    if (contract->get_puncte_nominalizare()<0)
    {
        return 2;
    }
    return 1;

}
