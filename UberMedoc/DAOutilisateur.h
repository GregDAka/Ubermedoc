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

    Client inscriptionUtilisateur(std::string nom, std::string prenom,std::string adresse,std::string mail,std::string mdp, QSqlDatabase db);
};

#endif // DAOUTILISATEUR_H
