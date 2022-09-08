#ifndef PHOTOREPORTERADMINPANEL_H
#define PHOTOREPORTERADMINPANEL_H

#include <QMainWindow>
#include <adminpanel.h>

QT_BEGIN_NAMESPACE
namespace Ui { class PhotoReporterAdminPanel; }
QT_END_NAMESPACE

class PhotoReporterAdminPanel : public QMainWindow
{
    Q_OBJECT

public:
    PhotoReporterAdminPanel(QWidget *parent = nullptr);
    ~PhotoReporterAdminPanel();

private slots:
    void on_SignInButton_clicked();

private:
    Ui::PhotoReporterAdminPanel *ui;
    AdminPanel *adminPanelWindow;
    std::string m_login = "admin", m_password = "123123";

    bool checkInput(std::string, std::string);

    void createAdminWindow();
};
#endif // PHOTOREPORTERADMINPANEL_H
