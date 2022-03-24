#include <iostream>
#include "Ui.h"
#include "RepoFile.h"
#include "Service.h"
#include "Teste.h"

using namespace std;

int main()
{
    RepoFile repo("date.in.txt");
    Service service(repo);
    Validator validator(service);

    //teste_all();

    Ui ui(service,validator);

    ui.show_menu();

    return 0;
}

