#ifndef ADMINAPP_H
#define ADMINAPP_H

#include "qlabel.h"
#include <QWidget>
#include <qpushbutton.h>

namespace Ui {
class AdminApp;
}

class AdminApp : public QWidget
{
    Q_OBJECT

public:
    explicit AdminApp(QWidget *parent = nullptr);
    ~AdminApp();
    void onListViewClicked(const QModelIndex &index) ;
    void modifMedocSelec(std::string medocselec) ;

private slots:
     void on_pushButton_clicked();
     void on_pushButton_3_clicked();
     void on_pushButton_4_clicked();

private:
    Ui::AdminApp *ui;

    QPushButton* pushButton;
    QPushButton* pushButton_3;
    QPushButton* pushButton_4;
    std::string recupClic ;
    QLabel* label_4 ;
    QLabel* label_3 ;
};

#endif // ADMINAPP_H
