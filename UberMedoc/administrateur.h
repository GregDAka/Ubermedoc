#include "utilisateur.h"
#include <string>

#ifndef ADMINISTRATEUR_H
#define ADMINISTRATEUR_H

class Administrateur : public Utilisateur
{
    private:

    public:

        Administrateur();
        Administrateur(string nomU, string prenomU, string adresseU, string mailU, string mdpU);
        ~Administrateur();
        void afficherDetails();

};

#endif // ADMINISTRATEUR_H
