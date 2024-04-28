#ifndef DAOMEDICAMENT_H
#define DAOMEDICAMENT_H

#include "medicament.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class DAOmedicament{
    public :
    /**
     * @brief ajouterMedoc, ajoute un médicament à la base de donnée.
     */
    void ajouterMedoc(string nom, double prix,QSqlDatabase db) ;

    /**
     * @brief ObjetMedoc methode qui recherche dans la BD un médicament et qui créer un objet de ce même médicament.
     * @return Renvoie un médicament.
     */
    Medicament* ObjetMedoc(string nom,QSqlDatabase db) ;
};

#endif // DAOMEDICAMENT_H
