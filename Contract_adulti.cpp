#pragma once

#include "Contract_adulti.h"
#include "Contract.h"

#include <string.h>
#include <iostream>

using namespace std;

Contract_adulti::Contract_adulti():Contract()
{
    this->firma=nullptr;
}
Contract_adulti::Contract_adulti(char*id, char*nume_voluntar, double puncte_nominalizare, char *firma):Contract(id, nume_voluntar,puncte_nominalizare)
{
    if (firma == nullptr )
    {
        this->firma= nullptr;
    }
    else
    {
        this->firma=new char[ strlen (firma)+1];
        strcpy_s(this->firma, strlen(firma)+1, firma);
    }
}
Contract_adulti::Contract_adulti( Contract_adulti *a):Contract(a)
{
    if (a->firma == nullptr )
    {
        this->firma= nullptr;
    }
    else
    {
        this->firma=new char[ strlen (a->firma)+1];
        strcpy_s(this->firma, strlen(a->firma)+1, a->firma);
    }
}
Contract_adulti::~Contract_adulti()
{
    if(this->firma)
    {delete this->firma;
        this->firma=nullptr;}
}

char *Contract_adulti::get_firma() {
    return this->firma;
}
void Contract_adulti::set_firma(const char *firma)
{
    if (this->firma)
    {
        delete[]this->firma;
    }
    if (firma == NULL)
    {
        this->firma = NULL;
    }
    else
    {
        this->firma = new char[strlen(firma) + 1];
        strcpy_s(this->firma, strlen(firma) + 1, firma);
    }
}
Contract_adulti *Contract_adulti::operator=(Contract_adulti *a)
{
    if (a!=this)
    {
        Contract::operator=(a);
        this->set_firma(a->firma);

    }
    return this;
}
bool Contract_adulti::operator==( Contract_adulti *a)
{
    return (Contract::operator==(a) && strcmp(this->firma,a->firma)==0);
}


Contract_adulti* Contract_adulti::clone()
{
    return new Contract_adulti(this->id, this->nume_voluntar, this->puncte_nominalizare, this->firma);
}

string Contract_adulti::toString(int ok)
{   string firme;
    firme+=this->firma;
    if (ok==1)
        return Contract::toString(ok)+" "+firme;
    else
        return Contract::toString(ok)+" firma: "+firme;
}
void Contract_adulti::nominalizare()
{
    this->puncte_nominalizare=this->puncte_nominalizare+2;
}