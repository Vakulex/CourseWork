#include "adduserdata.h"
#include "ui_adduserdata.h"

AddUserData::AddUserData(QWidget *parent) :
    QMainWindow(parent),
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
    QRegularExpression rx("[A-zА-яЁёЄєЇїІі]+");
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
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select name_service from services");
    ui->ServiceComboBox->setModel(model);
}

bool AddUserData::checkIncorrectFields()
{
    //return false if incorrect
    return !ui->NameLineEdit->text().isEmpty() &&
           !ui->MiddleNameLineEdit->text().isEmpty() &&
           !ui->SurnameLineEdit->text().isEmpty() &&
           !ui->PhoneNumberLineEdit->text().isEmpty() &&
           !ui->AdressLineEdit->text().isEmpty() &&
           !ui->ServiceComboBox->itemText(-1).contains("Послуги") &&
           !ui->PriceLabel->text().isEmpty() &&
           !ui->StartDateEdit->date().isNull();
}

bool AddUserData::checkIncorrectFields(bool isChecked)
{
    if(isChecked)
        return !ui->EndOrderDate->date().isNull() &&
               !(ui->EndOrderDate->date() >= ui->StartDateEdit->date()) &&
               !ui->PhotoPathLineEdit->text().isEmpty();
    else
        return true;
}

void AddUserData::addUser()
{
    QSqlQuery query_user;
    query_user.prepare("INSERT INTO users(users_name, users_middle_name, users_surname, phone_number)"
                       "VALUES(:name, :midname, :surname, :p_num); ");
    query_user.bindValue(":name",    ui->NameLineEdit->text());
    query_user.bindValue(":midname", ui->MiddleNameLineEdit->text());
    query_user.bindValue(":surname", ui->SurnameLineEdit->text());
    query_user.bindValue(":p_num", "+38" + ui->PhoneNumberLineEdit->text());
    query_user.exec();

    QSqlQuery order_query;
    order_query.prepare("INSERT INTO order_data(creation_date, finalization_date, img, orders, adress, order_price, order_status, users_ID) "
                        "VALUES(:s_date, :f_date, :img, :orders, :adress, :price, :status, (SELECT users_ID from users WHERE users_ID = LAST_INSERT_ID()));");
    order_query.bindValue(":s_date", ui->StartDateEdit->text());
    order_query.bindValue(":orders", ui->ServiceComboBox->currentText());
    order_query.bindValue(":adress", ui->AdressLineEdit->text());
    order_query.bindValue(":price",  ui->PriceLabel->text());
    order_query.bindValue(":status", ui->StatusCheckBox->isChecked());
    if(ui->StatusCheckBox->isChecked())
    {
        order_query.bindValue(":f_date", ui->EndOrderDate->text());
        order_query.bindValue(":f_date", ui->PhotoPathLineEdit->text());
    }
    else
    {
        order_query.bindValue(":f_date", QVariant(QVariant::String));
        order_query.bindValue(":img", QVariant(QVariant::String));
    }
    order_query.exec();
}

QString AddUserData::calculatePrice(int index)
{
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel;
    query.prepare("SELECT * FROM services WHERE name_service = :name;");
    query.bindValue(":name", ui->ServiceComboBox->itemText(index));
    query.exec();
    model->setQuery(query);
    QString str = model->record(0).value(3).toString();
    return str;
}

void AddUserData::on_AddUserButton_clicked()
{
    if(checkIncorrectFields() && checkIncorrectFields(ui->StatusCheckBox->isChecked()))
    {
        addUser();
        this->close();
    }
}

void AddUserData::on_ServiceComboBox_currentIndexChanged(int index)
{
    ui->PriceLabel->setText(calculatePrice(index));
}

