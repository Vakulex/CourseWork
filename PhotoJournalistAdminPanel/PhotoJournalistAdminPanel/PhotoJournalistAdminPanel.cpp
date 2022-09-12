#include "PhotoJournalistAdminPanel/PhotoJournalistAdminPanel.h"
#include "AdminPanel/adminpanel.h"
#include "ui_PhotoJournalistAdminPanel.h"

PhotoJournalistAdminPanel::PhotoJournalistAdminPanel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PhotoJournalistAdminPanel)
{
    ui->setupUi(this);
}

PhotoJournalistAdminPanel::~PhotoJournalistAdminPanel()
{
    delete ui;
}


void PhotoJournalistAdminPanel::on_SignInButton_clicked()
{
    std::string login = ui->LoginLineEdit->text().toStdString();
    std::string password = ui->PasswordLineEdit->text().toStdString();

    if(checkInput(login, password))
    {
        createAdminWindow();
        return;
    }
}

bool PhotoJournalistAdminPanel::checkInput(std::string login, std::string password)
{
    if(login == m_login && password == m_password)
        return true;
    if(password != m_password && login != m_login)
        ui->ErrorLabel->setText("Неправильний логін або пароль.\nБудь ласка, спробуйте знову.");
    return false;
}

void PhotoJournalistAdminPanel::createAdminWindow()
{
    adminPanelWindow = new AdminPanel();
    adminPanelWindow->show();
    this->close();
}
