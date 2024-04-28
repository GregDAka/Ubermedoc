#ifndef INSCRIPTION_H
#define INSCRIPTION_H

#include <QWidget>

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

private:
    Ui::Inscription *ui;
};

#endif // INSCRIPTION_H
