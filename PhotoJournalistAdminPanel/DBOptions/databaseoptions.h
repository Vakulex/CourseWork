#ifndef DATABASEOPTIONS_H
#define DATABASEOPTIONS_H

#include <QMainWindow>
#include "DatabaseManager/databasemanager.h"

namespace Ui {
class DataBaseOptions;
}

class DataBaseOptions : public QMainWindow
{
    Q_OBJECT

public:
    explicit DataBaseOptions(QWidget *parent = nullptr);
    ~DataBaseOptions();

private slots:
    void on_ApplyButton_clicked();

private:
    Ui::DataBaseOptions *ui;
};

#endif // DATABASEOPTIONS_H
