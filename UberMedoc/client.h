#include <string>
#include "medicament.h"
#include <map>
#ifndef CLIENT_H
#define CLIENT_H
#include "utilisateur.h"

class Client : public Utilisateur
{
    private:
        map<Medicament*, int> panier;
        double solde = 0.0;
        double totalPanier = 0.0;

    public:
        Client();
        Client(string nomU, string prenomU, string adresseU, string mailU, string mdpU);
        ~Client();
        void afficherDetails();
        void ajouterSolde(double);
        void retirerSolde(double);
        void ajouterAuPanier(Medicament*);
        void viderPanier();
        map<Medicament*, int> getPanier();
        double getTotalPanier();
        double getSolde();
};

#endif // CLIENT_H
