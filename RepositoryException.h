//
// Created by giulia on 5/24/2021.
//

#ifndef PROIECTOOP_REPOSITORYEXCEPTION_H
#define PROIECTOOP_REPOSITORYEXCEPTION_H

#endif //PROIECTOOP_REPOSITORYEXCEPTION_H


#pragma once
#include<string>
#include<stdexcept>

class RepositoryException : public runtime_error
{
private:
    string message;
public:
    RepositoryException(string msg) :runtime_error(msg), message(msg) {};
    ~RepositoryException() {};

    string what() {
        return this->message;
    }
};
