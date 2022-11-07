#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QtSql>
#include <QSqlDatabase>
#include <qmessagebox.h>

class DatabaseManager
{
private:
    QSqlDatabase m_db;
    DatabaseManager();
    static DatabaseManager* s_Instance;

public:
    DatabaseManager(DatabaseManager &other) = delete;
    void operator=(const DatabaseManager &) = delete;

    static DatabaseManager *GetInstance();

    void ConnectToDatabase();
    bool checkDatabaseConnection();
    void editDatabase(QString, QString, QString, QString);
};

#endif // DATABASEMANAGER_H
