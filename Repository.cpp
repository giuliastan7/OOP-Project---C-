#include "Repository.h"
#include "Contract.h"
#include <iostream>
#include <string.h>
#include <fstream>


using namespace std;

Repository::Repository()
{

}

Repository::~Repository()
{
}



void Repository::update(Contract  *contract_vechi,  Contract * contract_nou)
{//inlocuieste c vechi cu un contract  nou
    int ok=0;
    for (int i=0; i<this->contracte.size(); i++)
    {
        if (strcmp(this->contracte[i]->get_id(),contract_vechi->get_id())==0)
        {   ok++;
            delete this->contracte[i];
            this->contracte[i]=contract_nou->clone();
        }
    }
    if(ok==0)
        throw RepositoryException("Contractul  nu a fost gasit! ");
}

vector <Contract*> Repository::getAll()
{
    vector <Contract*> contracteCopie;
    for(int i=0; i<this->contracte.size(); i++)
    {
        contracteCopie.push_back(this->contracte[i]->clone());
    }
    return contracteCopie;
}


int Repository::getSize()
{
    return this->contracte.size();
}
Contract *Repository::getElem(int index)
{
    if (index<0 || index >=this->contracte.size())
    {
        throw RepositoryException("indexul nu e bun ");
    }
    return this->contracte[index]->clone();
    throw RepositoryException("Nu exista acest element ");


}
Contract *Repository::getElemById(char *id)
{
    vector <Contract*> a=getAll();
    for (int i=0; i<getSize(); i++)
        if(strcmp(a[i]->get_id(),id)==0)
            return a[i]->clone();
    throw RepositoryException("Nu exista elemente cu id-ul dat ");
}


void Repository::add(Contract *a)
{
    this->contracte.push_back(a->clone());
}
void Repository::stergereRepo(Contract *a)
{

    for (int i = 0; i < this->contracte.size(); i++)
    {
        //if (*this->produse[i] == *p)
        if (**(this->contracte.begin() + i) == *a)
        {
            delete this->contracte[i];
            this->contracte.erase(this->contracte.begin() + i);
            i--;
        }
    }
}

vector <Contract*> Repository::getAllAdulti(char *firma, int &dim)
{
    int ok=0;
    vector <Contract*> contracteCopie;
    for(int i=0; i<this->contracte.size(); i++)
    {
        if(this->contracte[i]->get_id()[0]=='A')
            if(strcmp(this->contracte[i]->get_firma(),firma)==0)
            {
                contracteCopie.push_back(this->contracte[i]->clone());
                ok++;
            }
    }
    dim=ok;
    return contracteCopie;
    throw RepositoryException("Nu exista acest tip de contract! ");
}


void Repository::sortareDupaPuncte()
{
    Contract *aux;
    for (int i=0; i<this->contracte.size()-1; i++)
    {for(int j=i+1; j<this->contracte.size(); j++)
            if(this->contracte[i]->get_puncte_nominalizare()>this->contracte[j]->get_puncte_nominalizare())
            {
                aux=this->contracte[i]->clone();
                delete this->contracte[i];
                this->contracte[i]=this->contracte[j]->clone();
                delete this->contracte[j];

                this->contracte[j]=aux->clone();

            }
    }


}