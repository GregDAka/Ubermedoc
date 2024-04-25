#include <vector>
#include "medicament.h"
#include "client.h"
using namespace std;
#ifndef COMMANDE_H
#define COMMANDE_H

class Commande
{
    private:
        vector<Medicament*> articles;
        double total;
        Client client;

    public:
        Commande();
        Commande(Client*);
        ~Commande();
        void afficherDetails();
        void ajouterMedicament(Medicament*);
        void retirerMedicament(Medicament*);
        double getTotal();
};

#endif // COMMANDE_H
