#include "adduserdata.h"
#include "ui_adduserdata.h"

AddUserData::AddUserData(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddUserData)
{
    ui->setupUi(this);
    ui->EndOrderDate->setEnabled(false);
    ui->PhotoPathLineEdit->setEnabled(false);

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

void AddUserData::on_AddUserButton_clicked()
{
    QString queryUserData = "BEGIN; "
                          "INSERT into users (users_surname,"
                          " users_name,"
                          " users_middle_name,"
                          " phone_number) "
                          "VALUES (" + ui->SurnameLineEdit->text() + "," +
                          ui->NameLineEdit->text() + "," +
                          ui->MiddleNameLineEdit->text() + "," +
                          ui->PhoneLineEdit->text() + ");" +
                          "INSERT into order_data (creation_date, "
                          "finalization_date,"
                          "img,"
                          "orders,"
                          "adress,"
                          "order_price,"
                          "order_status) "
                          "VALUES (" + ui->StartDateEdit->text() + "," +
                          ui->EndOrderDate->text() + "," +
                          ui->PhotoPathLineEdit->text() + "," +
                          ui->ServiceComboBox->itemData(ui->ServiceComboBox->currentIndex()).toString() + "," +
                          ui->AdressLineEdit->text() + "," +
                          ui->StatusCheckBox->text() + ");"
                          "COMMIT;";
    if(CheckNulls() && CheckFieldsAfterCheckBox() && CheckFields())
    {
        QSqlQuery query;
        query.exec(queryUserData);
        AddUserData::~AddUserData();
    }
}

bool AddUserData::CheckNulls()
{
    if((!ui->NameLineEdit->text().isEmpty()       &&
        !ui->SurnameLineEdit->text().isEmpty()    &&
        !ui->MiddleNameLineEdit->text().isEmpty() &&
        !ui->PhoneLineEdit->text().isEmpty()      &&
        !ui->AdressLineEdit->text().isEmpty()     &&
        !ui->StartDateEdit->text().isEmpty()      &&
        !ui->ServiceComboBox->currentText().isEmpty()))
    return true;

    ui->ErrorLabel->setText("Потрібно заповнити всі доступні поля.");
    return false;
}

bool AddUserData::CheckFields()
{
    QString nums = "0123456789";
    if(ui->PhoneLineEdit->text().toInt() &&
       ui->PhoneLineEdit->text().size() < 13 &&
       !(ui->SurnameLineEdit->text().contains(nums) || ui->NameLineEdit->text().contains(nums) || ui->MiddleNameLineEdit->text().contains(nums)))
        return true;
    ui->ErrorLabel->setText("Невірні значення. Будь ласка, перевіврте коректність даних.");
    return false;
}

bool AddUserData::CheckFieldsAfterCheckBox()
{
    if(ui->StatusCheckBox->isChecked())
        if((ui->EndOrderDate && ui->PhotoPathLineEdit) != NULL)
            return true;
    ui->ErrorLabel->setText("Потрібно заповнити всі поля.");
    return false;
}

