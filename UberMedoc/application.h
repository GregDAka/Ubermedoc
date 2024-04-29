#ifndef APPLICATION_H
#define APPLICATION_H

#include <QWidget>
#include <QPushButton>
namespace Ui {
class Application;
}

class Application : public QWidget
{
    Q_OBJECT

public:
    explicit Application(QWidget *parent = nullptr);
    ~Application();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

private:
    Ui::Application *ui;

    QPushButton* pushButton;
    QPushButton* pushButton_2;
    QPushButton* pushButton_3;
    QPushButton* pushButton_4;
};

#endif // APPLICATION_H
