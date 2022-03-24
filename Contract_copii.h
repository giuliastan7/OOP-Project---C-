#pragma once
#include "Contract.h"
class Contract_copii : public Contract{
private:
    char *scoala;
public:
    Contract_copii();
    Contract_copii(char*id, char*nume_voluntar, double puncte_nominalizare, char *scoala );
    Contract_copii( Contract_copii *contract);
    ~Contract_copii();

    char *get_scoala();

    void set_scoala(const char *scoala);

    virtual Contract_copii *operator=( Contract_copii *);
    virtual bool operator == ( Contract_copii *);

    virtual string toString(int);
    virtual void nominalizare();
    virtual Contract_copii *clone();


};
