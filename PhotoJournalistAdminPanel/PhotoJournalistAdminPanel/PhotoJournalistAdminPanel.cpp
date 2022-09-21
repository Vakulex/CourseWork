#include "PhotoJournalistAdminPanel/PhotoJournalistAdminPanel.h"
#include "AdminPanel/adminpanel.h"
#include "ui_PhotoJournalistAdminPanel.h"
#include <QSettings>
#include <QFile>
#include <QDebug>

PhotoJournalistAdminPanel::PhotoJournalistAdminPanel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PhotoJournalistAdminPanel)
{
    ui->setupUi(this);

    QString cfgPath = "D:/CourseWork/temp_PhotoJournalistAdminPanel//cfg/config.ini";

    if(QFile(cfgPath).exists())
    {
        QSettings settings(QString(cfgPath), QSettings::IniFormat);

        m_login = settings.value("user/login", "").toString();
        m_password = settings.value("user/password", "").toString();
    }
    else
        qDebug() << "config isn't found";
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
