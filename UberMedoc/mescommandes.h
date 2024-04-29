#ifndef MESCOMMANDES_H
#define MESCOMMANDES_H

#include "qlabel.h"
#include <QWidget>
#include <QPushButton>
#include "client.h"
namespace Ui {
class MesCommandes;
}

class MesCommandes : public QWidget
{
    Q_OBJECT

public:
    explicit MesCommandes(Client* cl, QWidget *parent = nullptr);
    ~MesCommandes();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

private:
    Ui::MesCommandes *ui;

    Client* m_client;

    QLabel* label;
    QLabel* label_2;

    QPushButton* pushButton_2;
    QPushButton* pushButton_5;
    QPushButton* pushButton_3;
    QPushButton* pushButton_4;


};

#endif // MESCOMMANDES_H
