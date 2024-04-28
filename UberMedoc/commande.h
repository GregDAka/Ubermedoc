#include <map>
#include "medicament.h"
#include "client.h"
using namespace std;
#ifndef COMMANDE_H
#define COMMANDE_H

class Commande
{
    private:
        double total;
        Client client;
        int livraison;

    public:
        Commande();
        Commande(Client*);
        ~Commande();
        void afficherDetails();
        double getTotal();
        map<Medicament*, int> getArticles();
};

#endif // COMMANDE_H
