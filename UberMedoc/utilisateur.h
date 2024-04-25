#include <string>
using namespace std;
#ifndef UTILISATEUR_H
#define UTILISATEUR_H

class Utilisateur
{
    protected:
        string nom;
        string prenom;
        string adresse;
        string mail;
        string mdp;
    public:
        Utilisateur();
        Utilisateur(string nomU, string prenomU, string adresseU, string mailU, string mdpU);
        ~Utilisateur();
        bool connexion(string email, string motdepasse);
        void deconnexion(); // Deconnexion serait en réalité juste l'appel au destructeur ???
        virtual void afficherDetails();
        string getNom();
        string getPrenom();
        string getMail();
        string getAdresse();
        string getMdp();
};

#endif // UTILISATEUR_H
