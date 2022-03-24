#include "RepoFile.h"
#include <fstream>
#include "Contract.h"
#include "Repository.h"
#include <cstring>
#include <iostream>
#include "Contract_adulti.h"
#include "Contract_copii.h"
#include "Util.h"
using namespace std;

void RepoFile::saveToFile()
{
    ofstream f(this->fileName);

    if (f.is_open())
    {
        for (Contract* contract:this->contracte)
        {
            f << contract->toString(1)<< endl;

        }
    }

}

void RepoFile::emptyRepo()
{
    ofstream f(this->fileName);
    f.close();


}
RepoFile::RepoFile()
{

}
RepoFile::RepoFile(string fileName)
{

    this->fileName = fileName;
    this->loadFromFile();



}

RepoFile::~RepoFile()
{
}

void RepoFile::setFileName(string fileName)
{
    this->fileName = fileName;
}

void RepoFile::addRepo(Contract *c)
{
    Repository::add(c);
    this->saveToFile();
}


void RepoFile::update(Contract* cVechi,  Contract* cNou)
{
    Repository::update(cVechi, cNou);
    this->saveToFile();
}

void RepoFile::stergere(Contract* c)
{
    Repository::stergereRepo(c);
    this->saveToFile();
}

void RepoFile::loadFromFile()
{
    ifstream f(this->fileName);
    if (f.is_open())
    {
        int i=0;
        string linie;
        string delim = " ";

        while (getline(f, linie))
        {

            int id[20];
            char nume_voluntar[20];
            double puncte_nominalizare;

            int pos = linie.find(delim);
            strcpy_s(reinterpret_cast<char *>(id), linie.substr(0, pos).length() + 1, linie.substr(0, pos).c_str());
            linie = linie.erase(0, pos + 1);
            if (strcmp(reinterpret_cast<const char *>(id), "") != 0)
            {
                pos = linie.find(delim);
                strcpy_s(nume_voluntar, linie.substr(0, pos).length()+1, linie.substr(0, pos).c_str());
                linie = linie.erase(0, pos + 1);

                char puncteCh[20];
                pos = linie.find(delim);
                strcpy_s(puncteCh, linie.substr(0, pos).length() + 1, linie.substr(0, pos).c_str());
                puncte_nominalizare=stod(puncteCh);
                if (id[0]=='N')
                {
                    //citire contract simplu

                    Contract *contract = new Contract(reinterpret_cast<char *>(id), nume_voluntar, puncte_nominalizare);

                    this->contracte.push_back(contract);

                }
                else if(id[0]=='S')
                {
                    int scoala[20];
                    ///citire contract copil
                    linie=linie.erase(0,pos+1);

                    pos=linie.find(delim);
                    strcpy_s(reinterpret_cast<char *>(scoala), linie.substr(0, pos).length() + 1, linie.substr(0, pos).c_str());
                    Contract_copii *contract= new Contract_copii(reinterpret_cast<char *>(id), nume_voluntar, puncte_nominalizare,
                                                                 reinterpret_cast<char *>(scoala));
                    this->contracte.push_back(contract);

                }
                else if(id[0]=='P')
                {
                    ///citire contract adult
                    char firma[20];
                    linie=linie.erase(0,pos+1);

                    pos=linie.find(delim);
                    strcpy_s(firma,linie.substr(0,pos).length()+1, linie.substr(0,pos).c_str());

                    Contract_adulti *contract=new Contract_adulti(reinterpret_cast<char *>(id), nume_voluntar, puncte_nominalizare, firma);
                    this->contracte.push_back(contract);

                }





            }



        }

        f.close();
    }
}
