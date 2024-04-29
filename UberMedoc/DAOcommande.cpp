#include "DAOcommande.h"
#include <iostream>
using namespace std ;

vector<pair<string, int>> DAOcommande::recupCommande(string mail, int numCommande, QSqlDatabase db){

    QSqlQuery query(db); // On fait une requête qui récupère la commande voulu (idCommande passé en parametre) pour l'utilisateur connecté
    query.prepare("SELECT medicament.nom, quantite "
                  "FROM commande "
                  "INNER JOIN utilisateur USING(idUtilisateur) "
                  "JOIN ligne_commande USING(idCommande) "
                  "JOIN medicament USING(reference) "
                  "WHERE adrMail = :mail AND idCommande = :numcommande");

    QString qMail = QString::fromStdString(mail);
    query.bindValue(":mail", qMail);

    QString qNum = QString::number(numCommande);
    query.bindValue(":numcommande", qNum);

    // Si la requête s'éxécute on stock les résultats dans une liste.
    vector<pair<string, int>> listeMedocCommande ;
    if(query.exec()) {
        while(query.next()){
            string nomMedoc = query.value(0).toString().toStdString();
            int quantite = query.value(1).toInt();
            listeMedocCommande.push_back({nomMedoc,quantite}) ;
        }
        return listeMedocCommande ;
    }
    return listeMedocCommande ;
}
