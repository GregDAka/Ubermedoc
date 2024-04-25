#include "client.h"
#include "utilisateur.h"
#include "client.h"
#include "medicament.h"
#include <iostream>
using namespace std;

Client::Client(string nomU, string prenomU, string adresseU, string mailU, string mdpU)
    : Utilisateur(nomU, prenomU, adresseU, mailU, mdpU){}


Client::~Client(){}

void Client::afficherDetails(){
    Utilisateur::afficherDetails();
    cout << "Panier de " << nom << ": "<< endl;
    if(!panier.empty()){
        for (Medicament* medoc : panier){
            medoc->afficherDetails();
            cout << "--------------------------------"<<endl;
        }
    }else{
        cout << "Votre panier est vide :/" << endl;
    }

}

void Client::inscrire(){
    //code here
}

void Client::ajouterAuPanier(Medicament* medoc){
    panier.push_back(medoc);
}

void Client::retirerDuPanier(Medicament* medoc){
    int i = 0;
    for (Medicament* med : panier){
        if (med->getRef() == medoc->getRef()){
            panier.erase(panier.begin() + i);
        }
        i++;
    }
}

//Commande Client::passerCommande(){}

