#include "commande.h"
#include "client.h"
#include <vector>
#include <iostream>
using namespace std;

Commande::Commande(){}

Commande::Commande(Client* c1){
    client = *c1;
    articles = c1->getPanier();
    total = c1->getTotalPanier();
}

Commande::~Commande(){}

void Commande::afficherDetails(){
    cout << endl << "-Details de la commande de " << client.getNom() << " : " << endl;
    if(!articles.empty()){
        for (Medicament* medoc : articles){
            medoc->afficherDetails();
            cout << "--------------------------------"<<endl;
        }
    }else{
        cout << "La commande est vide :/" << endl;
    }
    cout <<  "Total -> " << total << " euro" <<  endl;
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
