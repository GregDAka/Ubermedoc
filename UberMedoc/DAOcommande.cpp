#include "DAOcommande.h"
#include "client.h"
#include <QSqlDatabase>
#include <QtSql>


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

void createLigneCommande(int idCommande, int ref, int quant, QSqlDatabase db){
    QSqlQuery query(db);
    query.prepare("INSERT INTO ligne_commande (idCommande,reference,quantite) VALUES (:idCommande,:ref,:quant)");
    query.bindValue(":idCommande",idCommande);
    query.bindValue(":ref",ref);
    query.bindValue(":quant",quant);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'insertion de la commande :" << query.lastError().text();
        return;
    }

    qDebug() << "Nouvelle commande insérée avec succès ";
}










