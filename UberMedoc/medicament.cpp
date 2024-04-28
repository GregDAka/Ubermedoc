#include "medicament.h"
#include <iostream>
using namespace std;


Medicament::Medicament(){}

Medicament::Medicament(int refM, string nomM, double prixM){
    ref = refM ;
    nom = nomM;
    prix = prixM;
}

Medicament::~Medicament(){};

void Medicament::afficherDetails(){
    cout <<endl<< "Ref : " << ref << endl
         << "Nom :" << nom << endl
         << "Prix :" << prix << endl;
}

int Medicament::getRef(){
    return ref;
}

string Medicament::getNom(){
    return nom;
}

double Medicament::getPrix(){
    return prix;
}
