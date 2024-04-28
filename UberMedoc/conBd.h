#ifndef CONBD_H
#define CONBD_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QString>
#include <QDebug>
#include <iostream>

// db est une variable externe, donc elle peu être utiliser partout dans le code ou connexionBD() peu être utilisé.
extern QSqlDatabase db;

bool connexionBD();

#endif // CONBD_H
