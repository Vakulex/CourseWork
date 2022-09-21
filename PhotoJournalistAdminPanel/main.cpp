#include "PhotoJournalistAdminPanel/PhotoJournalistAdminPanel.h"
#include "AdminPanel/adminpanel.h"

#include <QApplication>
#include <qfile.h>
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PhotoJournalistAdminPanel w;

    w.show();
    return a.exec();
}
