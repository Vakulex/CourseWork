#include "PhotoJournalistAdminPanel/PhotoJournalistAdminPanel.h"
#include "AdminPanel/adminpanel.h"

#include <QApplication>
#include <qfile.h>
#include <QtSql>
#include "DatabaseManager/databasemanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PhotoJournalistAdminPanel w;

    DatabaseManager db;

    w.show();
    return a.exec();
}
