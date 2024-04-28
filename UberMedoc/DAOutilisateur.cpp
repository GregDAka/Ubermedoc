#include "DAOutilisateur.h"
#include <string>
#include <iostream>

using namespace std ;

Utilisateur* DAOutilisateur::connexionUtilisateur(std::string mail, std::string mdp, QSqlDatabase db){
    QSqlQuery query(db); // Connexion normalement déjà établie, lors de l'éxécution de conBd, on a créer db variable eterne utilisable partout.
    query.prepare("SELECT * FROM utilisateur WHERE adrMail = :mail AND mdp = :mdp");
    // On prépare la requête car sinon les :mail et :mdp ne seront pas reconnu comme argument de la fonction utilisable dans la requête

    // On doit convertir nos String en Qstring pour pouvoir BIND nos arguments de fonction.
    QString qMail = QString::fromStdString(mail);
    QString qMdp = QString::fromStdString(mdp);

    query.bindValue(":mail", qMail);
    query.bindValue(":mdp", qMdp);

    if (query.exec()) {
        // On admet qu'il ne peut pas y avoir deux utilisateurs avec la même adresse mail dans la base de donnée.
        while (query.next()) {
            // A la base query.value est de type QVarient, pour pouvoir les utiliser dans nos constructeurs on doit convertire les variables dans les bons types.
            string nom = query.value(1).toString().toStdString(); // converti en QString puis en String
            string prenom = query.value(2).toString().toStdString();
            bool estAdmin = query.value(3).toBool();
            string adrMail = query.value(4).toString().toStdString();
            string mdp = query.value(5).toString().toStdString();
            string adresse = query.value(6).toString().toStdString();

            if (estAdmin){
                return new Administrateur(nom,prenom,adresse,adrMail,mdp);
            }
            else {
                return new Client(nom,prenom,adresse,adrMail,mdp) ;
            }
        }
    }
    return nullptr;
}


Client DAOutilisateur::inscriptionUtilisateur(string nom, string prenom, string adresse, string mail, string mdp, QSqlDatabase db) {

    QSqlQuery requeteVerif(db);
    requeteVerif.prepare("SELECT COUNT(*) FROM utilisateur WHERE adrMail = :mail");

    QString qMailcheck = QString::fromStdString(mail);
    requeteVerif.bindValue(":mail", qMailcheck);

    if (!requeteVerif.exec()) {
        std::cerr << "Erreur lors de l'exécution de la requête de vérification : " << requeteVerif.lastError().text().toStdString() << std::endl;
        return Client();
    }

    requeteVerif.next(); // Récupère le premier résultat (le nombre d'occurrences)
    int count = requeteVerif.value(0).toInt(); // Récupère le nombre d'occurrences

    if (count > 0) {
        std::cout << "L'adresse e-mail est deja utilisee." << std::endl;
        return Client();
    }

    QSqlQuery query(db);
    query.prepare("INSERT INTO utilisateur (nom, prenom, adrMail, mdp, adresse) VALUES (:nom, :prenom, :mail, :mdp, :adresse)");

    QString qNom = QString::fromStdString(nom);
    QString qPrenom = QString::fromStdString(prenom);
    QString qMail = QString::fromStdString(mail);
    QString qAdresse = QString::fromStdString(adresse);
    QString qMdp = QString::fromStdString(mdp);

    query.bindValue(":nom", qNom);
    query.bindValue(":prenom", qPrenom);
    query.bindValue(":mail", qMail);
    query.bindValue(":mdp", qMdp);
    query.bindValue(":adresse", qAdresse);

    if (!query.exec()) {
        std::cerr << "Erreur d'insertion des donnees : " << query.lastError().text().toStdString() << std::endl;
        return Client();
    }

    return Client(nom, prenom, adresse, mail, mdp);
}




