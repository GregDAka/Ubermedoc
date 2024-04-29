#include "client.h"
#include "utilisateur.h"
#include "client.h"
#include "medicament.h"
#include <iostream>
using namespace std;

Client::Client(){}

Client::Client(string nomU, string prenomU, string adresseU, string mailU, string mdpU)
    : Utilisateur(nomU, prenomU, adresseU, mailU, mdpU){}


Client::~Client(){}

void Client::afficherDetails(){
    Utilisateur::afficherDetails();
    cout << "Solde : " << solde << endl
        << "Panier de " << nom << ": "<< endl;
    if(!panier.empty()){
        for (const auto& entry : panier) {
            entry.first->afficherDetails();
            cout << "Quantite : " << entry.second << endl
                << "--------------------------------"<<endl;
        }
        cout << "Total : " << totalPanier << " euro" << endl;
    }else{
        cout << "Votre panier est vide :/" << endl;
    }

}

void Client::inscrire(){
    //code here
}

void Client::ajouterAuPanier(Medicament* medoc){
    bool present = false;
    for (const auto& entry : panier) {
        if (entry.first->getRef() == medoc->getRef()){
            present = true;
            medoc = entry.first;
        }
    }
    present ? panier[medoc] += 1 : panier[medoc] = 1;
    totalPanier += medoc->getPrix();
}

void Client::retirerDuPanier(Medicament* medoc){
    int i = 0;
    for (const auto& entry : panier) {
        if (entry.first->getRef() == medoc->getRef()){
            if (entry.second == 1){
                panier.erase(entry.first);
            }
            else{
                panier[entry.first] -= 1;
            }
            totalPanier -= medoc->getPrix();
        }
        i++;
    }
}

void Client::ajouterSolde(double valeur){
    solde += valeur;
}

map<Medicament*, int> Client::getPanier(){
    return panier;
}

double Client::getTotalPanier(){
    return totalPanier;
}

void Client::viderPanier(){
    panier.clear();
    totalPanier = 0;
}

double Client::getSolde(){
    return solde;
}

void Client::retirerSolde(double valeur){
    solde -= valeur;
}
