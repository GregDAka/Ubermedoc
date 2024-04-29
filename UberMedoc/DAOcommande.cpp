#include "DAOcommande.h"
#include <iostream>
#include "client.h"
#include <QSqlDatabase>
#include <QtSql>

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

void createCommande(int idClient, QSqlDatabase db) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO commande (idUtilisateur) VALUES (:idClient)");
    query.bindValue(":idClient", idClient);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'insertion de la commande :" << query.lastError().text();
        return;
    }

    qDebug() << "Nouvelle commande insérée avec succès ";
}

int getIdCommande(int idClient, QSqlDatabase db){
    QSqlQuery query(db);
    query.prepare("SELECT max(idCommande) FROM commande WHERE idUtilisateur = :idClient");
    query.bindValue(":idClient", idClient);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError().text();
        return -1;
    }

    if (query.next()) {
        return query.value(0).toInt();
    } else {
        qDebug() << "Aucune commande trouvée pour l'ID client spécifié";
        return -1;
    }
}

