#pragma once
#include "RepoFile.h"
#include "Contract.h"
#include "Contract_copii.h"
#include "Contract_adulti.h"
class Service
{
private:
    RepoFile repository;
public:
    Service();
    Service(RepoFile repository);
    ~Service();

    RepoFile getRepo();
    void setRepo(RepoFile repo_nou);
    int getSize();

    vector <Contract*> getAll();
    vector <Contract*> getAllAdulti(char *, int &);

    void add_contract_n(char *,char*,double);
    void add_contract_c(char *,char*,double, char *);
    void add_contract_a(char *,char*,double, char *);

    void stergeById(char *);
    Contract* getById(char *);
    void update(Contract*, Contract*);
    void pastreazaMinim5Nominalizari();
    int sunt5nominalizari(Contract * );
    void sortareDupaPuncte();





};
