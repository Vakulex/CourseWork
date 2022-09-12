#include "PhotoJournalistAdminPanel/PhotoJournalistAdminPanel.h"
#include "AdminPanel/adminpanel.h"

#include <QApplication>
#include <qfile.h>
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PhotoJournalistAdminPanel w;

    QFile file("../ThemeTemplate/SpyBot.qss");
    file.open(QFile::ReadOnly);

    QString styleSheet
    {
        QLatin1String(file.readAll())
    };

    a.setStyleSheet(styleSheet);

    w.show();
    return a.exec();
}
