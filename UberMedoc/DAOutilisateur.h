#ifndef DAOUTILISATEUR_H
#define DAOUTILISATEUR_H
#include <string>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "utilisateur.h"
#include "client.h"
#include "administrateur.h"

class DAOutilisateur{
public :
    /**
     * @brief Cette fonction permet de vérifier la connexion d'un utilisateur en cherchant dans la base de donnée si l'adresse mail et
     * le mot de passe sont présent dans la BD et si ils correspondent
     * @param mail , c'est le parametre MAIL récupérer dans la fenêtre de saisie de la page connexion
     * @param mdp , c'est le parametre NOM récupérer dans la fenêtre de saisie de la page connexion
     */
    Utilisateur* connexionUtilisateur(std::string mail, std::string mdp, QSqlDatabase db);

    /**
     * @brief inscriptionUtilisateur permet à un nouvel utilisateur de se créer un compte, si l'adresse mail est déjà utilisé alors l'inscription échoue et renvoie un Client vide.
     * @param nom
     * @param prenom
     * @param adresse
     * @param mail
     * @param mdp
     * @param db Base de donnée créer lors de l'appel de la fonction connexionBd.
     * @return Renvoie un client, qui sera ensuite utilisé comme l'utilisateur du logiciel, si erreur, un client vide est renvoyé.
     */
    Client* inscriptionUtilisateur(std::string nom, std::string prenom,std::string adresse,std::string mail,std::string mdp, QSqlDatabase db);

    int getIdClientDAO(std::string mail,QSqlDatabase db);

    bool estAdmin(std::string mail, std::string mdp,QSqlDatabase db);


};

#endif // DAOUTILISATEUR_H
