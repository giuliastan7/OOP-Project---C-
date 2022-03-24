//
// Created by giulia on 5/25/2021.
//


#include "Contract.h"
#include "Contract_copii.h"
#include "Contract_adulti.h"
#include "RepoFile.h"
#include "Repository.h"
#include "Service.h"
#include "Validator.h"
#include <string.h>
#include <assert.h>
#include <iostream>

using namespace std;
void testContract()
{   // test obiect contract
    // teste repo
    Repository repo_test;

    //constructori cu parametrii
    Contract *a1=new Contract ("N1","Marius",12);
    Contract  *a2=new Contract ("N2","Elena",13);
    Contract  *a3=new Contract ("N3","Cornelia",5);
    Contract_copii *a4=new Contract_copii("C1","Andrei",33.5,"Elf");

    //test gett-eri
    assert(strcmp(a1->get_id(),"N1")==0);
    assert(strcmp(a1->get_nume_voluntar(),"Marius")==0);
    assert(a1->get_puncte_nominalizare()==12);

    //test sett-eri
    a1->set_puncte_nominalizare(137);
    assert(a1->get_puncte_nominalizare()==137);

    //constructor de copiere
    Contract *a5=new Contract (a3);
    assert(strcmp(a5->get_id(),"N3")==0);


    repo_test.add(a1);
    repo_test.add(a2);
    repo_test.add(a3);
    repo_test.add(a4);
    repo_test.add(a5);

    //test getById
    ///Contract  *a6 = repo_test.getElemById("N2");
    ///assert(strcmp(a2->get_id(),a6->get_id())==0);

    //gett-eri
    assert(repo_test.getSize()==5);
    //assert(strcmp(repo_test.getElem(0)->getId(),a1->getId())==0);

    //test get all
    vector <Contract *> a=repo_test.getAll();
    //assert(strcmp(a[0]->getId(),a1->getId())==0);

    //test get elem
    //assert(strcmp(repo_test.getElem(1)->get_id(),a2->get_id())==0);

    //test stergere
    repo_test.stergereRepo(a1);
    assert(repo_test.getSize()==4);

    //test update
    //repo_test.update(a3,a4);
   // vector <Abonament*> anou=repo_test.getAll();
    //assert(strcmp(anou[2]->getId(),anou[3]->getId())==0);

    //test validate
    //a2->validate();
    //assert(a2->getPuncte()==120.5);

    //test sortare dupa puncte
   // int dim=0;
    //vector <Abonament*> studenti=repo_test.getAllStudent("UBB",dim);
    //assert(dim==3);

    //test sortare dupa puncte
    //repo_test.sortareDupaPuncte();
    //studenti=repo_test.getAll();
   // assert(strcmp(studenti[0]->getId(),a2->getId())==0);



}


void teste_all() {

    testContract();
}