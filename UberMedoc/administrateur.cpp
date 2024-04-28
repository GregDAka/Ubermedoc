#include "administrateur.h"
#include "utilisateur.h"
#include <string>
#include <iostream>
using namespace std;

Administrateur::Administrateur() {}
Administrateur::~Administrateur() {}

Administrateur::Administrateur(string nomU, string prenomU, string adresseU, string mailU, string mdpU)
    : Utilisateur(nomU, prenomU, adresseU, mailU, mdpU) {}


void Administrateur::afficherDetails(){
    cout << "ADMINISTRATEUR : " << endl;
    Utilisateur::afficherDetails();
}
