#include "PhotoJournalistAdminPanel/PhotoJournalistAdminPanel.h"
#include "AdminPanel/adminpanel.h"
#include "ui_PhotoJournalistAdminPanel.h"
#include <QSettings>
#include <QFile>
#include <QDebug>
#include <QDir>

PhotoJournalistAdminPanel::PhotoJournalistAdminPanel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PhotoJournalistAdminPanel)
{
    ui->setupUi(this);

    QSettings *settings = new QSettings(m_cfgPath, QSettings::IniFormat);

    m_login = settings->value("user/login").toString();
    m_password = settings->value("user/password").toString();

    qDebug() << m_login;
    qDebug() << m_password;
    qDebug() << settings->value("user/login").toString();
    qDebug() << settings->value("user/password").toString();
}

PhotoJournalistAdminPanel::~PhotoJournalistAdminPanel()
{
    delete ui;
}


void PhotoJournalistAdminPanel::on_SignInButton_clicked()
{
    QString login = ui->LoginLineEdit->text();
    QString password = ui->PasswordLineEdit->text();

    if(checkInput(login, password))
    {
        createAdminWindow();
    }
}

bool PhotoJournalistAdminPanel::checkInput(QString login, QString password)
{
    if(login == m_login && password == m_password)
        return true;
    if(password != m_password || login != m_login)
        ui->ErrorLabel->setText("Неправильний логін або пароль.\nБудь ласка, спробуйте знову.");
    return false;
}

void PhotoJournalistAdminPanel::createAdminWindow()
{
    adminPanelWindow = new AdminPanel();
    adminPanelWindow->show();
    this->close();
}

void PhotoJournalistAdminPanel::setCfgPath(QString cfgPath)
{
    m_cfgPath = cfgPath;
}
