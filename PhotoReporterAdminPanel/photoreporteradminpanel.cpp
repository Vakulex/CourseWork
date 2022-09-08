#include "photoreporteradminpanel.h"
#include "ui_photoreporteradminpanel.h"

PhotoReporterAdminPanel::PhotoReporterAdminPanel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PhotoReporterAdminPanel)
{
    ui->setupUi(this);
}

PhotoReporterAdminPanel::~PhotoReporterAdminPanel()
{
    delete ui;
}


void PhotoReporterAdminPanel::on_SignInButton_clicked()
{
    std::string login = ui->LoginLineEdit->text().toStdString();
    std::string password = ui->PasswordLineEdit->text().toStdString();

    if(checkInput(login, password))
    {
        createAdminWindow();
        return;
    }
}

bool PhotoReporterAdminPanel::checkInput(std::string login, std::string password)
{
    if(login == m_login && password == m_password)
        return true;
    if(password != m_password && login != m_login)
        ui->ErrorLabel->setText("Неправильний логін або пароль.\nБудь ласка, спробуйте знову.");
    return false;
}

void PhotoReporterAdminPanel::createAdminWindow()
{
    adminPanelWindow = new AdminPanel();
    adminPanelWindow->show();
    this->close();
}
