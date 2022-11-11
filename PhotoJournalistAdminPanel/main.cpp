#include "DatabaseManager/databasemanager.h"
#include "AdminPanel/adminpanel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DatabaseManager::GetInstance()->ConnectToDatabase();
    AdminPanel w;


    w.show();

    return a.exec();
}
