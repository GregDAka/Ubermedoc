#include "commande.h"
#include "client.h"
#include <vector>
#include <iostream>
using namespace std;

Commande::Commande(){}

Commande::Commande(Client* c1){
    client = *c1;
    total = c1->getTotalPanier();
    livraison = client.getPanier().size();// petit hack le temps de livraison égale au nombre d'article (on verra un vrai random plus tard)
    c1->viderPanier();
}

Commande::~Commande(){}

void Commande::afficherDetails(){
    cout << endl << "-Details de la commande de " << client.getNom() << " : " << endl;
    if(!getArticles().empty()){
        for (const auto& entry : getArticles()) {
            entry.first->afficherDetails();
            cout << "Quantite : " << entry.second << endl
                 << "--------------------------------"<<endl;
        }
        cout <<  "Total -> " << total << " euro" <<  endl
             << "Livraison dans " << livraison << " jour(s)" << endl;
    }else{
        cout << "La commande est vide :/" << endl;
    }

}


map<Medicament*, int> Commande::getArticles(){
    return client.getPanier();
}
