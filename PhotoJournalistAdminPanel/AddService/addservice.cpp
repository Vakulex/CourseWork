#include "addservice.h"
#include "ui_addservice.h"

AddService::AddService(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddService)
{
    ui->setupUi(this);

    initCombobox();
}

AddService::~AddService()
{
    delete ui;
}

void AddService::initCombobox()
{
    QSqlQuery query;
    query.exec("SELECT DISTINCT type_service FROM services");

    QStringList items;
    while(query.next())
    {
        QSqlRecord recorder = query.record();
        items.append(recorder.value("type_service").toString());
    }

    ui->ServiceType->addItems(items);
}

void AddService::on_AddServiceButton_clicked()
{
    if(!CheckFields())
        return;

    qDebug() << ui->ServiceType->currentText();

    QSqlQuery query;
    QString request("INSERT INTO services(name_service, type_service, service_price, commentary) VALUES('%1', '%2', %3, '%4')");
    request = request.arg(ui->ServiceTitleLineEdit->text(), ui->ServiceType->currentText(), ui->PriceSpinBox->text(), ui->CommentaryTextEdit->text());

    if(query.exec(request))
        QMessageBox::information(this, "Успішно", "Додавання послуги пройшло успішно", QMessageBox::StandardButton());

    this->close();
}

bool AddService::CheckFields()
{
    return !ui->ServiceTitleLineEdit->text().isEmpty() &&
           !ui->PriceSpinBox->text().isEmpty();
}

