#include "addservice.h"
#include "ui_addservice.h"

AddService::AddService(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddService)
{
    ui->setupUi(this);
}

AddService::~AddService()
{
    delete ui;
}

void AddService::on_AddServiceButton_clicked()
{
    query.prepare("INSERT into services(name_service, type_service, service_price, commentary) "
                   "VALUES (?, ?, ?, ?);");
    query.addBindValue(ui->ServiceTitleLineEdit->text());
    query.addBindValue(ui->ServiceTypeComboBox->currentText());
    query.addBindValue(ui->PriceSpinBox->text());
    query.addBindValue(ui->CommentaryTextEdit->text());
    if(CheckFields())
    {
        if(query.exec())
            QMessageBox::information(this, "Успішно", "Додавання послуги пройшло успішно", QMessageBox::StandardButton());
    }
    AddService::~AddService();
}

bool AddService::CheckFields()
{
    bool isTitleCorrect = !ui->ServiceTitleLineEdit->text().isEmpty();
    bool isPriceCorrect = !ui->PriceSpinBox->text().isEmpty();
    if(isTitleCorrect && isPriceCorrect)
        return true;
    return false;
}

