#include "Contract.h"
#include "Contract_copii.h"
#include "Contract_adulti.h"
#include "Contract.h"
#include <iostream>
#include "RepoFile.h"
#include "Service.h"
#include "ServiceException.h"

using namespace std;
Service::Service()
{

}
Service::Service (RepoFile repo_nou)
{
    this->repository=repo_nou;


}
Service::~Service()
{

}

void Service::setRepo(RepoFile repo_nou)
{
    this->repository=repo_nou;
}

RepoFile Service::getRepo()
{
    return this->repository;
}
vector <Contract*> Service::getAll()
{
    return this->repository.getAll();
}

vector <Contract*> Service::getAllAdulti(char *firma, int &dim)
{
    return this->repository.getAllAdulti(firma,dim);
    throw ServiceException ("Nu exista contracte cu aceasta firma ");
}

int Service::getSize()
{
    return this->repository.getSize();
}
void Service::add_contract_n(char * id, char *nume_voluntar, double puncte_nominalizare)
{
    Contract *a= new Contract(id,nume_voluntar,puncte_nominalizare);
    this->repository.addRepo(a);
}

void Service::add_contract_c(char * id, char *nume_voluntar, double puncte_nominalizare, char *scoala)
{
    Contract_copii *a= new Contract_copii(id,nume_voluntar,puncte_nominalizare, scoala);
    this->repository.addRepo(a);
}
void Service::add_contract_a(char * id, char *nume_voluntar, double puncte_nominalizare, char *firma)
{
    Contract_adulti *a= new Contract_adulti(id,nume_voluntar,puncte_nominalizare,firma);
    this->repository.addRepo(a);
}
Contract * Service::getById(char *id)
{
    return this->repository.getElemById(id);
}
void Service::stergeById(char *id)
{
    Contract *a=getById(id);
    this->repository.stergere(a);
}
void Service::update(Contract *co_nou, Contract *co_vechi)
{
    this->repository.update(co_nou,co_vechi);
}

int Service::sunt5nominalizari(Contract *a)
{
    int ok=0;
    if (a->get_puncte_nominalizare() >= 5)ok=1;

    return ok;
}
void Service::pastreazaMinim5Nominalizari()
{
    vector <Contract*> a=getAll();
    int i=0;
    int dim=getSize();
    while(i<dim)
    {
        if(sunt5nominalizari(a[i])==0)
        {
            stergeById(a[i]->get_id());
        }
        i++;
    }


}

void Service::sortareDupaPuncte()
{
    this->repository.sortareDupaPuncte();
}
