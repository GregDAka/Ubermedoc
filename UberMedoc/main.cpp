#include "mainwindow.h"
#include <iostream>
using namespace std;
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    cout << "Aller les canailles, gabriel n'est pas le meilleur" << endl;
    return a.exec();
}
