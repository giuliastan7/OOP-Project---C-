
#pragma once

#include "Contract_copii.h"
#include "Contract_adulti.h"
#include "Service.h"

class Validator{
private:
    Service service;
public:
    Validator();
    Validator(class Service);
    ~Validator();
    int validare_contract( Contract *);

    int validare_contract( Contract_copii *);
    int validare_contract( Contract_adulti *);

};
