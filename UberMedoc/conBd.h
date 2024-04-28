#include <QSqlDatabase>
#include <QSqlError>
#include <QString>
#include <QDebug>
#include <QtSql>
#include <iostream>

#ifndef CONBD_H
#define CONBD_H

static bool connexionBD(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("ubermedoc");
    db.setUserName("root");
    db.setPassword("");

    if(db.open()){
        std::cout<<"Connexion reussi"<<std::endl ;
        return true ;
    } else {
        std::cerr << "Connexion echouee : " << db.lastError().text().toStdString() << std::endl;
        return false ;
    }

}

#endif // CONBD_H
