#ifndef APPLICATION_H
#define APPLICATION_H

#include <QWidget>
#include <QLabel>
#include "client.h"

namespace Ui {
class Application;
}

class Application : public QWidget
{
    Q_OBJECT

public:
    explicit Application(Client* client, QWidget *parent = nullptr);
    ~Application();

private:
    Ui::Application *ui;
    Client* m_client;
    QLabel* nomLabel;
    QLabel* prenomLabel;
};

#endif // APPLICATION_H
