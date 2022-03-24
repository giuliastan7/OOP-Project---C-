#include "Service.h"
#include "Validator.h"
#include "ServiceException.h"
#include "RepositoryException.h"
class Ui{
private:
    Service service;
    Validator validator;
public:
    Ui();
    Ui(class Service, class Validator);
    ~Ui();
    void show_menu();
    void citesteContracte();
    void arataContracte();
    void stergeContract();
    void updateContract();
    void afisareContractDupaFirma();
    void afisare5nominalizari();
    void sortareDupaPuncte();
};