#pragma once
#include "Contract.h"
class Contract_adulti : public Contract{
private:
    char *firma;
public:
    Contract_adulti();
    Contract_adulti(char*id, char*nume_voluntar, double puncte_nominalizare, char *firma );
    Contract_adulti( Contract_adulti *contract);
    ~Contract_adulti();

    char *get_firma();

    void set_firma(const char *firma);

    Contract_adulti * operator=( Contract_adulti *);
    bool operator == ( Contract_adulti *);

    virtual void nominalizare();
    virtual string toString(int);
    virtual Contract_adulti *clone();


};