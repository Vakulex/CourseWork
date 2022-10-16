#include "databasemanager.h"

DatabaseManager::DatabaseManager()
{

}

void DatabaseManager::ConnectToDatabase()
{
    if(!db.open())
    {
        db = QSqlDatabase::addDatabase("QODBC");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("123123");
        db.setDatabaseName("coursework");
        checkDatabaseConnection();
    }

    return;
}

bool DatabaseManager::checkDatabaseConnection()
{
    if(db.open())
    {
        qDebug() << "Connected";
        return true;
    }
    else
    {
        qDebug() << "Not connected";
        return false;
    }
}

void DatabaseManager::editDatabase(QSqlDatabase db, QString hostname, QString username, QString password, QString databaseName)
{
    db.setHostName(hostname);
    db.setUserName(username);
    db.setPassword(password);
    db.setDatabaseName(databaseName);
    checkDatabaseConnection();
}

DatabaseManager DatabaseManager::s_Instance;
