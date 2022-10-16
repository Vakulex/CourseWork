#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QtSql>
#include <QSqlDatabase>

class DatabaseManager
{
private:
    QSqlDatabase db;
    DatabaseManager();
    static DatabaseManager s_Instance;

public:
    DatabaseManager(const DatabaseManager&) = delete;

    static DatabaseManager& Get()
    {
        return s_Instance;
    }

    void ConnectToDatabase();
    bool checkDatabaseConnection();
    void editDatabase(QSqlDatabase, QString, QString, QString, QString);

};

#endif // DATABASEMANAGER_H
