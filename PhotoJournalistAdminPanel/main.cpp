#include "DatabaseManager/databasemanager.h"
#include "AdminPanel/adminpanel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AdminPanel w;

    DatabaseManager::GetInstance()->ConnectToDatabase();

    w.show();

    return a.exec();
}
