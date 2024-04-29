#ifndef PANIER_H
#define PANIER_H

#include "qpushbutton.h"
#include <QWidget>

namespace Ui {
class Panier;
}

class Panier : public QWidget
{
    Q_OBJECT

public:
    explicit Panier(QWidget *parent = nullptr);
    ~Panier();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();

private:
    Ui::Panier *ui;

    QPushButton* pushButton;
    QPushButton* pushButton_2;
    QPushButton* pushButton_4;
    QPushButton* pushButton_5;
    QPushButton* pushButton_6;
    QPushButton* pushButton_7;
    QPushButton* pushButton_8;
};

#endif // PANIER_H
