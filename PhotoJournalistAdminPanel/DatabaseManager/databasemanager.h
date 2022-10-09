#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

class DatabaseManager
{
private:
    QSqlDatabase db;
public:
    DatabaseManager();
    void createDatabase();
    void checkDatabaseConnection(QSqlDatabase);
protected:
    void editDatabase(QSqlDatabase, QString, QString, QString, QString);
};

#endif // DATABASEMANAGER_H
