#include "DAOmedicament.h"
#include <iostream>

using namespace std ;

void DAOmedicament::ajouterMedoc(string nom, double prix,QSqlDatabase db){

    // On fait une requête qui nous servira à vérifier si le médicament est déjà dans la BD
    QSqlQuery requeteVerif(db);
    requeteVerif.prepare("SELECT COUNT(*) FROM medicament WHERE nom = :nom");

    QString qNomCheck = QString::fromStdString(nom);
    requeteVerif.bindValue(":nom", qNomCheck);

    if (!requeteVerif.exec()) {
        std::cerr << "Erreur lors de l'exécution de la requête de vérification : " << requeteVerif.lastError().text().toStdString() << std::endl;
    }

    requeteVerif.next();
    int count = requeteVerif.value(0).toInt();

    // Si le médicament est déjà dans la BD, on ne l'ajoute pas.
    if (count > 0) {
        std::cout << "Ce medicament est deja disponible a la vente." << std::endl;
    } else { // Sinon on ajoute le médicament.
        QSqlQuery query(db);
        query.prepare("INSERT INTO medicament(nom,prix) VALUES(:nom,:prix)");

        QString qNom = QString::fromStdString(nom);
        QString qPrix = QString::number(prix);

        query.bindValue(":nom", qNom);
        query.bindValue(":prix",qPrix);

        if (!query.exec()) {
            std::cerr << "Erreur d'insertion des donnees : " << query.lastError().text().toStdString() << std::endl;
        }
    }
}

Medicament* DAOmedicament::ObjetMedoc(string nom,QSqlDatabase db){
    // On vérifie si le médicament recherché est dans la BD
    QSqlQuery query(db);
    query.prepare("SELECT COUNT(*) FROM medicament WHERE nom = :nom");

    QString qNom = QString::fromStdString(nom);
    query.bindValue(":nom", qNom);

    if (!query.exec()) {
        std::cerr << "Erreur lors de l'exécution de la requête de verification : " << query.lastError().text().toStdString() << std::endl;
    }

    query.next();
    int count = query.value(0).toInt();

    if (count == 0) { // Si aucun médicament n'est trouvé à ce nom dans la BD on envoie une erreur.
        std::cout << "Ce medicament n'est pas présent dans la base de donnee." << std::endl;
    } else { // Sinon on créer l'objet car on a trouvé le médicament dans la BD.

        query.prepare("SELECT * FROM medicament WHERE nom = :nom");
        QString qNom = QString::fromStdString(nom);
        query.bindValue(":nom", qNom);

        if (!query.exec()) {
            std::cerr << "Erreur lors de l'exécution de la requête de verification : " << query.lastError().text().toStdString() << std::endl;
        }

        else {
            while (query.next()) { // On fait les convertions en TYPE voulu car le type de base est Qstring.
                int refO = query.value(0).toInt();
                string nomO = query.value(1).toString().toStdString(); // nécéssaire pour convertir en String.
                double prixO = query.value(2).toDouble();
                return new Medicament(refO,nomO,prixO) ;
            }
        }

    }
    cout<<"Pas d'objet cree"<<endl ;
    return new Medicament() ;
}


