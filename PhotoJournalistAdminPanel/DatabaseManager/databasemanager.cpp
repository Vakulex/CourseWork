#include "databasemanager.h"

DatabaseManager::DatabaseManager()
{
    createDatabase();
}

void DatabaseManager::createDatabase()
{
    db = QSqlDatabase::addDatabase("MYSQL");
    db.setHostName("192.168.0.77");
    db.setUserName("root");
    db.setPassword("123123");
    db.setDatabaseName("photojournalist");
    checkDatabaseConnection(db);
}

void DatabaseManager::checkDatabaseConnection(QSqlDatabase db)
{
    if(db.open())
        qDebug() << "Connected";
    else
        qDebug() << "Not connected";
}

void DatabaseManager::editDatabase(QSqlDatabase db, QString hostname, QString username, QString password, QString databaseName)
{
    db.setHostName(hostname);
    db.setUserName(username);
    db.setPassword(password);
    db.setDatabaseName(databaseName);
    checkDatabaseConnection(db);
}
