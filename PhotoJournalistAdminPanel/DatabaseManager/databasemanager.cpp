#include "databasemanager.h"

DatabaseManager *DatabaseManager::GetInstance()
{
    if(s_Instance==nullptr){
        s_Instance = new DatabaseManager();
    }
    return s_Instance;
}

DatabaseManager* DatabaseManager::s_Instance;

DatabaseManager::DatabaseManager()
{
}

void DatabaseManager::ConnectToDatabase()
{
    if(!m_db.open())
    {
        m_db = QSqlDatabase::addDatabase("QODBC");
        m_db.setHostName("192.168.0.77");
        m_db.setPort(3306);
        m_db.setUserName("root");
        m_db.setPassword("123123");
        m_db.setDatabaseName("coursework");
        checkDatabaseConnection();
    }
    return;
}

bool DatabaseManager::checkDatabaseConnection()
{
    QMessageBox *message = new QMessageBox();
    if(m_db.open())
    {
        message->setText("БД підключена успішно.");
        message->exec();
        return true;
    }
    else
    {
        message->setText("БД не була підключена успішно.");
        message->exec();
        return false;
    }
}

void DatabaseManager::editDatabase(QString hostname, QString username, QString password, QString databaseName)
{
    m_db.setHostName(hostname);
    m_db.setUserName(username);
    m_db.setPassword(password);
    m_db.setDatabaseName(databaseName);
}
