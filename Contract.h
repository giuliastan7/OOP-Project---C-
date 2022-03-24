#pragma once
#include <ostream>
#include <istream>
using namespace std;
class Contract
{
protected:
    char *id;
    char *nume_voluntar;
    double puncte_nominalizare;
public:
    Contract();
    Contract(char * id, char * nume_voluntar, double puncte_nominalizare);
    Contract(Contract *contract);
    ~Contract();

    char *get_id();
    char *get_nume_voluntar();
    double get_puncte_nominalizare();

    void set_id(const char *id);
    void set_nume_voluntar(const char *nume_voluntar);
    void set_puncte_nominalizare(double puncte_nominalizare);



    virtual Contract *clone();
    virtual Contract operator=(Contract *);

    virtual bool operator == ( Contract *);
    virtual bool operator == ( Contract &);


    //friend ostream &operator<<(ostream&, const Abonament &);

    virtual string toString(int );
    virtual  char *get_scoala();
    virtual  char *get_firma();
    virtual void nominalizare();





};
