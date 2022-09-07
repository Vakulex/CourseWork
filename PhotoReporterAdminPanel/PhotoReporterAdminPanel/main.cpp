#include "PhotoReporterAdminPanel.h"
#include <QtWidgets/QApplication>

#include <qfile.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    PhotoReporterAdminPanel w;

    QFile file("D:/CourseWork/ThemeTemplate/SpyBot.qss");
    file.open(QFile::ReadOnly);

    QString styleSheet
    { 
        QLatin1String(file.readAll()) 
    };

    app.setStyleSheet(styleSheet);

    w.show();
    return app.exec();
}
