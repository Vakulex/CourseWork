#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include "qsqltablemodel.h"
#include <QMainWindow>

namespace Ui {
class AdminPanel;
}

class AdminPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminPanel(QWidget *parent = nullptr);
    ~AdminPanel();

private:
    Ui::AdminPanel *ui;
    QSqlTableModel *model;
    void initResources();
    void createUserModel(QSqlTableModel*);
    void WidgetSettings();
};

#endif // ADMINPANEL_H
