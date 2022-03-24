
#pragma once

#include "Contract_copii.h"
#include "Contract.h"

#include <string.h>
#include <iostream>

using namespace std;

Contract_copii::Contract_copii():Contract()
{
    this->scoala=nullptr;
}
Contract_copii::Contract_copii(char*id, char*nume_voluntar, double puncte_nominalizare, char *scoala ):Contract(id, nume_voluntar,puncte_nominalizare)
{
    if (scoala == nullptr )
    {
        this->scoala= nullptr;
    }
    else
    {
        this->scoala=new char[ strlen (scoala)+1];
        strcpy_s(this->scoala, strlen(scoala)+1, scoala);
    }
}
Contract_copii::Contract_copii( Contract_copii *a):Contract(a)
{
    if (a->scoala == nullptr )
    {
        this->scoala= nullptr;
    }
    else
    {
        this->scoala=new char[ strlen (a->scoala)+1];
        strcpy_s(this->scoala, strlen(a->scoala)+1, a->scoala);
    }
}
Contract_copii::~Contract_copii()
{
    if(this->scoala)
    {delete this->scoala;
        this->scoala=nullptr;}
}

char *Contract_copii::get_scoala()
{
    return this->scoala;
}
void Contract_copii::set_scoala(const char *scoala)
{
    if (this->scoala)
    {
        delete[]this->scoala;
    }
    if (scoala== NULL)
    {
        this->scoala= NULL;
    }
    else
    {
        this->scoala = new char[strlen(scoala + 1)];
        strcpy_s(this->scoala, strlen(scoala) + 1, scoala);
    }
}
Contract_copii *Contract_copii::operator=( Contract_copii *a)
{
    if (a!=this)
    {
        Contract::operator=(a);
        this->set_scoala(a->scoala);

    }
    return this;
}
bool Contract_copii::operator==( Contract_copii *a)
{
    return (Contract::operator==(a) && strcmp(this->scoala,a->scoala)==0);
}

string Contract_copii::toString(int ok)
{ string scoala;

    scoala+=this->scoala;
    if (ok==1)
        return Contract::toString(ok)+" "+scoala;
    else
        return Contract::toString(ok)+" scoala: "+scoala;
}
void Contract_copii::nominalizare()
{
    this->puncte_nominalizare=this->puncte_nominalizare+5;
}
Contract_copii* Contract_copii::clone()
{
    return new Contract_copii(this->id, this->nume_voluntar, this->puncte_nominalizare, this->scoala);
}
