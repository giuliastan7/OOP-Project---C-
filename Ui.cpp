#include <iostream>
#include "Ui.h"
#include "Contract.h"
#include "Contract_adulti.h"
#include "Contract_copii.h"
#include "Service.h"
#include <string.h>
using namespace std;

Ui::Ui()
{

}
Ui::Ui(class Service service, class Validator validator)
{
    this->service=service;
    this->validator=validator;
}

Ui::~Ui()
{

}
void Ui::show_menu() {
    while (true) {
        int optiune;
        cout << "1-Introduceti un contract nou  " << endl
             << "2- AFISATI TOATE CONTRACTELE" << endl
             << "3- STERGETI un contract" << endl
             << "4- AFISATI contractele angajatilor de la o anumita firma data de la tastatura" << endl
             << "5- PASTRATI doar contractele cu cel putin 5 nominalizari" << endl
             << "6- SORTATI contractele in ordine crescatoare dupa numarul de puncte de nominalizare +  afisare ulterioara"
             << endl
             << "7-IESIRE PROGRAM FORTATA" << endl;

        cout << "introdu optiunea: " << endl;
        cin >> optiune;
        if (optiune == 7)
            break;
        switch (optiune) {
            case 1: {

                citesteContracte();
                break;
            }
            case 2: {
                arataContracte();
                break;
            }
            case 3: {
                stergeContract();
                break;
            }
            case 4: {
                afisareContractDupaFirma();
                break;
            }

            case 5: {
                afisare5nominalizari();
                break;
            }
            case 6: {
                sortareDupaPuncte();
                break;
            }



        }
    }
}

void Ui::sortareDupaPuncte()
{
    service.sortareDupaPuncte();
}
void Ui::afisare5nominalizari()
{
    try
    {
        service.pastreazaMinim5Nominalizari();
    }
    catch(ServiceException se)
    {
        cout<<" EROARE: "<<endl;
        cout<<se.what()<<endl;
    }
    catch (RepositoryException re)
    {
        cout<<" EROARE: "<<endl;
        cout<<re.what()<<endl;
    }

}
void Ui::afisareContractDupaFirma()
{
    char firma[20];
    cout<<"Introduceti firma: "<<endl;
    cin.ignore();
    cin>>firma;
    int dim;
    vector <Contract*> a=service.getAllAdulti(firma,dim);
    for (int i=0; i<dim; i++)
        cout<<a[i]->toString(2)<<" "<<endl;




}
/*
void Ui::updateContract()
{

    char id[20];
    cout<<"introduceti id-ul elementului de modificat: "<<endl;
    cin.ignore();
    cin>>id;
    int ok=1;
    Contract *a;
    try
    {
        a=service.getById(id);
    }
    catch(ServiceException se)
    {
        ok=0;
        cout<<" EROARE: "<<endl;
        cout<<se.what()<<endl;
    }
    catch (RepositoryException re)
    {
        ok=0;
        cout<<" EROARE: "<<endl;
        cout<<re.what()<<endl;
    }
    if(ok==1)
    {
        char nume_voluntar[20];
        char numar_puncte_no[20];
        double numar_puncte_nominalizare;
        cout<<"numele voluntarului : "<<endl;
        cin.ignore();
        cin>>nume_voluntar;
        if(strcmp(nume_voluntar,"nu")==0)
            strcpy(nume_voluntar,a->get_nume_voluntar());
        cout<<"numar puncte nominalizare  : "<<endl;
        cin.ignore();
        cin>>numar_puncte_no;
        if(strcmp(numar_puncte_no,"nu")==0)
            numar_puncte_nominalizare=a->get_puncte_nominalizare();
        else
            numar_puncte_nominalizare=atof(numar_puncte_no);

        if(id[0]=='C')
        {
            char scoala[20];
            cout<<"scoala: "<<endl;
            cin>>scoala;
            Contract_copii *ab_s=new Contract_copii(id,nume_voluntar,numar_puncte_nominalizare,scoala);
            try
            {
                service.update(ab_s,a);
            }
            catch(ServiceException se)
            {
                cout<<" EROARE: "<<endl;
                cout<<se.what()<<endl;
            }
            catch (RepositoryException re)
            {
                cout<<" EROARE: "<<endl;
                cout<<re.what()<<endl;
            }
        }
        else if(id[0]=='a')
        {
            char firma[20];
            cout<<"firma: "<<endl;
            cin>>firma;
            Contract_copii *ab_p=new Contract_copii(id,nume_voluntar,numar_puncte_nominalizare,firma);
            try
            {
                service.update(ab_p,a);
            }
            catch(ServiceException se)
            {
                cout<<" EROARE: "<<endl;
                cout<<se.what()<<endl;
            }
            catch (RepositoryException re)
            {
                cout<<" EROARE: "<<endl;
                cout<<re.what()<<endl;
            }
        }
        else
        {
            Contract *ab_n=new  Contract(id,nume_voluntar,numar_puncte_nominalizare);
            try
            {
                service.update(ab_n,a);
            }
            catch(ServiceException se)
            {
                cout<<" EROARE: "<<endl;
                cout<<se.what()<<endl;
            }
            catch (RepositoryException re)
            {
                cout<<" EROARE: "<<endl;
                cout<<re.what()<<endl;
            }
        }
    }
    ok=1;

}
 */
void Ui::arataContracte()
{
    vector <Contract*> a=service.getAll();
    for (int i=0; i<service.getSize(); i++)
        cout<<a[i]->toString(2)<<" "<<endl;

}
void Ui::stergeContract()
{
    char id[20];
    cout<<"introduceti id-ul Contractului de sters: "<<endl;
    cin.ignore();
    cin>>id;
    try
    {
        service.stergeById(id);
    }
    catch(ServiceException se)
    {
        cout<<" EROARE: "<<endl;
        cout<<se.what()<<endl;
    }
    catch (RepositoryException re)
    {
        cout<<" EROARE: "<<endl;
        cout<<re.what()<<endl;
    }
}

void Ui::citesteContracte()
{
    char id[20],nume_voluntar[20];
    double puncte_nominalizare;
    cout<<"id: "<<endl;
    cin.ignore();
    cin>>id;
    cout<<"nume_voluntar: "<<endl;
    cin.ignore();
    cin>>nume_voluntar;
    cout<<"puncte_nominalizare: "<<endl;
    cin.ignore();
    cin>>puncte_nominalizare;
    Contract *test=new Contract(id,nume_voluntar,puncte_nominalizare);
    int valinit=validator.validare_contract(test);
    if(valinit!=4)

        if(id[0]=='N')
        {
            Contract *a=new Contract(id,nume_voluntar,puncte_nominalizare);
            int val=validator.validare_contract(a);
            if (val==1)
                service.add_contract_n(id,nume_voluntar,puncte_nominalizare);
            if (val==2)
                cout<<"Numarul de puncte trebuie sa fie pozitiv "<<endl;
            if(val==3)
                cout<<"Numele exista in baza de date"<<endl;
            if(val==0)
                cout<<"id-ul trebuie sa fie unic"<<endl;


        }
        else if(id[0]=='C')
        {
            char scoala[20];
            cout<<"scoala: "<<endl;
            cin>>scoala;
            Contract_copii *a=new Contract_copii(id,nume_voluntar,puncte_nominalizare,scoala);

            int val=validator.validare_contract(a);
            if (val==1)
                service.add_contract_c(id,nume_voluntar,puncte_nominalizare,scoala);

            if (val==2)
                cout<<"Numarul de puncte trebuie sa fie pozitiv "<<endl;
            if(val==3)
                cout<<"Numele-ul exista in baza de date"<<endl;
            if(val==0)
                cout<<"id-ul trebuie sa fie unic"<<endl;
        }
        else
        {
            char firma[20];
            cout<<"firma: "<<endl;
            cin>>firma;

            Contract_adulti *a=new Contract_adulti(id,nume_voluntar,puncte_nominalizare,firma);

            int val=validator.validare_contract(a);
            if (val==1)
                service.add_contract_a(id,nume_voluntar,puncte_nominalizare,firma);
            if (val==2)
                cout<<"Numarul de puncte trebuie sa fie pozitiv "<<endl;
            if(val==3)
                cout<<"Numele-ul exista in baza de date"<<endl;
            if(val==0)
                cout<<"id-ul trebuie sa fie unic"<<endl;

        }
    else
        cout<<"Id ul trebuie sa inceapa cu C N sau A"<<endl;

}
