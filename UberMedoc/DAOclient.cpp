#include "DAOclient.h"
#include <string>

using namespace std ;

Utilisateur* DAOclient::connexionUtilisateur(std::string mail, std::string mdp, QSqlDatabase db){
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
            // string numTel = query.value(3).toString().toStdString();
            bool estAdmin = query.value(4).toBool();
            string adrMail = query.value(5).toString().toStdString();
            string mdp = query.value(6).toString().toStdString();
            string adresse = query.value(7).toString().toStdString();

            if (estAdmin){
                int a = 1 ;
            }
            else {
                return new Client(nom,prenom,adresse,adrMail,mdp) ;
            }
        }
    }
    return nullptr;
}
