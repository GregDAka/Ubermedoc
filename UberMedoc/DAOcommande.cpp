#include "DAOcommande.h"
#include "client.h"
#include <QSqlDatabase>
#include <QtSql>


    /*
    faire une requete pour récupérer le id du client depuis la bdd -> fait
    créer une commande avec le id du client et le statut (à voir) -> fait
    faire une requete pour récupérer le id de la commande(select max(idcommande) sur commande où idUtil == idClient ) -> fait
    parcourir le panier et pour chaque médicament créer une ligne dans ligne commande avec le id de la command, la reference du medoc, et la quantite
    */

void DAOcommande::recupCommande(QSqlDatabase db){ // ???

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

