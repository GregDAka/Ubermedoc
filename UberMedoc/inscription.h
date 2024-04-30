#ifndef INSCRIPTION_H
#define INSCRIPTION_H
#include <QWidget>
#include <QLineEdit>

namespace Ui {
class Inscription;
}

class Inscription : public QWidget
{
    Q_OBJECT

public:
    explicit Inscription(QWidget *parent = nullptr);
    ~Inscription();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();



private:
    Ui::Inscription *ui;

    QLineEdit* lineEdit;
    QLineEdit* lineEdit_2;
    QLineEdit* lineEdit_3;
    QLineEdit* lineEdit_4;
    QLineEdit* lineEdit_5;
};

#endif // INSCRIPTION_H
