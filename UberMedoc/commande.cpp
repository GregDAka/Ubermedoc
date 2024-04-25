#include "commande.h"
#include <vector>
#include <iostream>
using namespace std;

Commande::Commande(){}

Commande::~Commande(){};

void Commande::afficherDetails(){
    if(!articles.empty()){
        for (Medicament* medoc : articles){
            medoc->afficherDetails();
            cout << "--------------------------------"<<endl;
        }
    }else{
        cout << "La commande est vide :/" << endl;
    }
    cout <<  "-> " << total << endl;
}

void Commande::ajouterMedicament(Medicament* medoc){
    articles.push_back(medoc);
}

void Commande::retirerMedicament(Medicament* medoc){
    int i = 0;
    for (Medicament* med : articles){
        if (med->getRef() == medoc->getRef()){
            articles.erase(articles.begin() + i);
        }
        i++;
    }
}
