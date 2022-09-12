#include "PhotoReporterAdminPanel/photoreporteradminpanel.h"
#include "AdminPanel/adminpanel.h"

#include <QApplication>
#include <qfile.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PhotoReporterAdminPanel w;

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
