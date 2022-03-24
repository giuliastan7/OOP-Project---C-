#pragma once
#include "Util.h"
#include "Contract.h"
#include <string.h>
#include <iostream>


using namespace std;

Contract::Contract()
{
    this->id=nullptr;
    this->nume_voluntar=nullptr;
    this->puncte_nominalizare=0.0;
}
Contract::Contract(char *id, char *nume_voluntar, double puncte_nominalizare)
{
    if (id == nullptr )
    {
        this->id= nullptr;
    }
    else
    {
        this->id=new char[ strlen (id)+1];
        strcpy_s(this->id, strlen(id)+1, id);

    }
    if (nume_voluntar == nullptr )
    {
        this->nume_voluntar= nullptr;
    }
    else
    {
        this->nume_voluntar=new char[ strlen (nume_voluntar)+1];
        strcpy_s(this->nume_voluntar, strlen(nume_voluntar)+1, nume_voluntar);

    }
    this->puncte_nominalizare = puncte_nominalizare;
}
Contract::Contract( Contract* contract)
{
    if (contract->id == nullptr )
    {
        this->id= nullptr;
    }
    else
    {
        this->id=new char[ strlen (contract->id)+1];
        strcpy_s(this->id, strlen(contract->id)+1, contract->id);

    }
    if (contract->nume_voluntar == nullptr )
    {
        this->nume_voluntar= nullptr;
    }
    else
    {
        this->nume_voluntar=new char[ strlen (contract->nume_voluntar)+1];
        strcpy_s(this->nume_voluntar, strlen(contract->nume_voluntar)+1, contract->nume_voluntar);

    }
    this->puncte_nominalizare = contract->puncte_nominalizare;
}
Contract::~Contract()
{
     if(this->id)
         {delete this->id;
     this->id=nullptr;}
     if (this->nume_voluntar)
     {
         delete this->nume_voluntar;
         this->nume_voluntar = nullptr;

     }


}

char *Contract::get_id()
{
    return this->id;

}
char *Contract::get_nume_voluntar()
{
    return this->nume_voluntar;

}
double Contract::get_puncte_nominalizare()
{
    return this->puncte_nominalizare;

}
void Contract::set_id(const char *id)
{
    if (this->id)
    {
        delete[]this->id;
    }
    if (id == NULL)
    {
        this->id = NULL;
    }
    else
    {
        this->id = new char[strlen(id) + 1];
        strcpy_s(this->id, strlen(id) + 1, id);
    }
}

void Contract::set_nume_voluntar(const char *nume_voluntar)
{
    if (this->nume_voluntar)
    {
        delete[]this->nume_voluntar;
    }
    if (nume_voluntar == NULL)
    {
        this->nume_voluntar = NULL;
    }
    else
    {
        this->nume_voluntar = new char[strlen(nume_voluntar) + 1];
        strcpy_s(this->nume_voluntar, strlen(nume_voluntar) + 1, nume_voluntar);
    }
}

void Contract::set_puncte_nominalizare(double puncte_nominalizare)
{
    this->puncte_nominalizare=puncte_nominalizare;
}
Contract Contract::operator=(Contract * contract)
{
    this->set_nume_voluntar(contract->nume_voluntar);
    this->set_id(contract->id);
    this->puncte_nominalizare=contract->puncte_nominalizare;
return *this;
}


bool Contract::operator ==( Contract *contract)
{
    int val=strcmp(this->id,contract->id) ;
//&& strcmp(this->cnp,abonament.cnp )==0 && this->puncte==abonament.puncte;
    if (val==0)
        return 1;
    else
        return 0;
}
bool Contract::operator ==( Contract& p)
{
    return strcmp(this->id, p.id)==0 && strcmp(this->nume_voluntar,p.nume_voluntar)==0 && this->puncte_nominalizare == p.puncte_nominalizare;
}


Contract* Contract::clone()
{
    return new Contract(this->id, this->nume_voluntar, this->puncte_nominalizare);
}
string Contract::toString(int x)
{
    string id, nume_voluntar;
    id+=this->id;
    nume_voluntar+=this->nume_voluntar;
    if (x==1)
        return id+" "+nume_voluntar+" "+convertDoubleToString(this->puncte_nominalizare);
    else
        return "id: "+id+" nume_voluntar: "+nume_voluntar+" puncte_nominalizare: "+convertDoubleToString(this->puncte_nominalizare);

}

void Contract::nominalizare()
{
    this->puncte_nominalizare=this->puncte_nominalizare+5;
}


char *Contract::get_scoala()
{
return nullptr;
}

char *Contract::get_firma()
{
return nullptr;
}
