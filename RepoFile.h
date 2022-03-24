#pragma once
#include "Repository.h"
#include "RepoFile.h"

class RepoFile : public Repository {
private:
    string fileName;
public:
    RepoFile();
    RepoFile(string fileName);
    ~RepoFile();

    void setFileName(string fileName);

    void addRepo(Contract * );
    //  void addRepo(AbonamentStudent * );

    void update(Contract* ,  Contract* );
    void stergere(Contract* );

    void loadFromFile();
    void saveToFile();

    void emptyRepo();
};
