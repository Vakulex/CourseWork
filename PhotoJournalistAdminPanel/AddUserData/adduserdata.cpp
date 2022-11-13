#include "adduserdata.h"
#include "ui_adduserdata.h"

AddUserData::AddUserData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddUserData)
{
    ui->setupUi(this);
    ui->EndOrderDate->setEnabled(false);
    ui->PhotoPathLineEdit->setEnabled(false);

    initComboBox();
    setValidFields();
}

AddUserData::~AddUserData()
{
    delete ui;
}

void AddUserData::on_StatusCheckBox_toggled(bool checked)
{
    ui->EndOrderDate->setEnabled(checked);
    ui->PhotoPathLineEdit->setEnabled(checked);
}

void AddUserData::setValidFields()
{
    QRegularExpression rx("[A-zА-яЁёЄєЇїІі']+");
    QValidator *validator = new QRegularExpressionValidator(rx, this);

    ui->NameLineEdit->setValidator(validator);
    ui->MiddleNameLineEdit->setValidator(validator);
    ui->SurnameLineEdit->setValidator(validator);

    rx.setPattern("^[0-9]{10}$");
    QValidator *phoneValidator = new QRegularExpressionValidator(rx, this);
    ui->PhoneNumberLineEdit->setValidator(phoneValidator);
}

void AddUserData::initComboBox()
{
    QStringList status;

    QSqlQuery query;    
    query.exec("select * from services");
    while (query.next())
    {
        QSqlRecord recorder = query.record();
        status.append(recorder.value("name_service").toString());
    }

    ui->ServiceComboBox->addItems(status);
    ui->ServiceComboBox->setCurrentIndex(0);

    setServiceValues(ui->ServiceComboBox->currentText());
}

bool AddUserData::checkIncorrectFields()
{
    bool correct = !ui->NameLineEdit->text().isEmpty() &&
                !ui->MiddleNameLineEdit->text().isEmpty() &&
                !ui->SurnameLineEdit->text().isEmpty() &&
                !ui->PhoneNumberLineEdit->text().isEmpty() &&
                !ui->AdressLineEdit->text().isEmpty() &&
                !ui->ServiceComboBox->itemText(-1).contains("Послуги") &&
                !ui->PriceLabel_2->text().isEmpty() &&
                !ui->StartDateEdit->date().isNull();

    if(ui->StatusCheckBox->isChecked())
    {
        correct = correct &&
                  !ui->EndOrderDate->date().isNull() &&
                  (ui->EndOrderDate->date() >= ui->StartDateEdit->date()) &&
                  !ui->PhotoPathLineEdit->text().isEmpty();
    }

    return correct;
}

void AddUserData::addUser()
{
    QSqlQuery query_user;
    query_user.prepare("INSERT INTO users(users_name, users_middle_name, users_surname, phone_number)"
                       "VALUES(:name, :midname, :surname, :p_num)");
    query_user.bindValue(":name",          ui->NameLineEdit->text());
    query_user.bindValue(":midname",       ui->MiddleNameLineEdit->text());
    query_user.bindValue(":surname",       ui->SurnameLineEdit->text());
    query_user.bindValue(":p_num", "+38" + ui->PhoneNumberLineEdit->text());
    query_user.exec();

    int user_id = query_user.lastInsertId().toUInt();

    QSqlQuery order_query;
    order_query.prepare("INSERT INTO order_data(creation_date, finalization_date, img, adress, order_price, order_status, users_ID, service_ID) "
                        "VALUES(:s_date, :f_date, :img, :adress, :price, :status, :user_id, :service)");
    order_query.bindValue(":s_date", ui->StartDateEdit->text());
    /*order_query.bindValue(":f_date", "");
    order_query.bindValue(":img", "");*/

    order_query.bindValue(":adress", ui->AdressLineEdit->text());
    order_query.bindValue(":price",  ui->PriceLabel_2->text().toInt());
    order_query.bindValue(":status", ui->StatusCheckBox->isChecked());
    order_query.bindValue(":user_id", user_id);
    order_query.bindValue(":service", service_id);


    if(ui->StatusCheckBox->isChecked())
    {
        order_query.bindValue(":f_date", ui->EndOrderDate->text());
        order_query.bindValue(":img", ui->PhotoPathLineEdit->text());
    }

    order_query.exec();
}

void AddUserData::setServiceValues(QString arg1)
{
    QSqlQuery query;
    query.prepare("SELECT service_ID, service_price FROM services WHERE name_service = :name;");
    query.bindValue(":name", arg1);
    query.exec();
    query.next();

    QSqlRecord record = query.record();

    ui->PriceLabel_2->setText(record.value("service_price").toString());
    service_id = record.value("service_ID").toInt();
}


void AddUserData::on_AddUserButton_clicked()
{
    qDebug() << checkIncorrectFields();

    if(checkIncorrectFields())
    {
        QMessageBox::warning(this, "Успішно", "Додавання пройшло успішно");
        addUser();
        this->close();
    }
    else
    {
        if(ui->StartDateEdit->date() >= ui->EndOrderDate->date())
            QMessageBox::warning(this, "Помилка", "Не вдалося додати користувача. Дата початку не може бути пізніше за дату окінчення");
        else
            QMessageBox::warning(this, "Помилка", "Не вдалося додати користувача. Заповніть, будь ласка, всі поля");
    }
}

void AddUserData::on_ServiceComboBox_textActivated(const QString &arg1)
{
    setServiceValues(arg1);
}

