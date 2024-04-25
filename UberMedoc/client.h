#include <string>
#include "medicament.h"
#include "commande.h"
#include <vector>
using namespace std;
#ifndef CLIENT_H
#define CLIENT_H

#include "utilisateur.h"

class Client : public Utilisateur
{
    private:
        vector<Medicament*> panier;
        double solde;

    public:
        Client();
        Client(string nomU, string prenomU, string adresseU, string mailU, string mdpU);
        ~Client();
        void afficherDetails();
        void inscrire();
        void ajouterSolde();
        void ajouterAuPanier(Medicament*);
        void retirerDuPanier(Medicament*);
        Commande passerCommande();
};

#endif // CLIENT_H
