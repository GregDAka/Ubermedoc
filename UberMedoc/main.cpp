#include "mainwindow.h"
#include <iostream>
using namespace std;
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    cout << "Aller les canailles, gabriel est le meilleur" << endl;
    return a.exec();
}
