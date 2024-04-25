#include <string>
#include "medicament.h"
#include <vector>
using namespace std;
#ifndef CLIENT_H
#define CLIENT_H

#include "utilisateur.h"

class Client : public Utilisateur
{
    private:
        vector<Medicament*> panier;
        double solde = 0.0;
        double totalPanier = 0.0;

    public:
        Client();
        Client(string nomU, string prenomU, string adresseU, string mailU, string mdpU);
        ~Client();
        void afficherDetails();
        void inscrire();
        void ajouterSolde(double);
        void ajouterAuPanier(Medicament*);
        void retirerDuPanier(Medicament*);
        vector<Medicament*> getPanier();
        double getTotalPanier();
};

#endif // CLIENT_H
