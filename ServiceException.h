//
// Created by giulia on 5/24/2021.
//

#ifndef PROIECTOOP_SERVICEEXCEPTION_H
#define PROIECTOOP_SERVICEEXCEPTION_H

#endif //PROIECTOOP_SERVICEEXCEPTION_H


#pragma once
#include<string>
#include<stdexcept>

class ServiceException : public runtime_error
{
private:
    string message;
public:
    ServiceException(string msg) :runtime_error(msg), message(msg) {};
    ~ServiceException() {};

    string what() {
        return this->message;
    }
};

