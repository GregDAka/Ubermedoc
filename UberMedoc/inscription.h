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
    void on_pushButton2_clicked();

private:
    Ui::Inscription *ui;

    QLineEdit lineEdit;
};

#endif // INSCRIPTION_H
