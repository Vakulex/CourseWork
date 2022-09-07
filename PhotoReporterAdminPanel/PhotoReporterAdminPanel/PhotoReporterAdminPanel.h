#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PhotoReporterAdminPanel.h"

class PhotoReporterAdminPanel : public QMainWindow
{
    Q_OBJECT

public:
    PhotoReporterAdminPanel(QWidget *parent = nullptr);
    ~PhotoReporterAdminPanel();

private:
    Ui::PhotoReporterAdminPanelClass ui;
};
