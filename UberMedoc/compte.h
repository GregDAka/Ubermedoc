#ifndef COMPTE_H
#define COMPTE_H

#include "qlabel.h"
#include "qpushbutton.h"
#include <QWidget>
#include "client.h"
namespace Ui {
class Compte;
}

class Compte : public QWidget
{
    Q_OBJECT

public:
    explicit Compte(Client* m_client, QWidget *parent = nullptr);
    ~Compte();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();

private:
    Ui::Compte *ui;

    Client* m_client;

    QLabel* label;
    QLabel* label_2;

    QPushButton* pushButton;
    QPushButton* pushButton_2;
    QPushButton* pushButton_5;
    QPushButton* pushButton_4;
};

#endif // COMPTE_H
