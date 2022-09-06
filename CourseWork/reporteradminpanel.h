#ifndef REPORTERADMINPANEL_H
#define REPORTERADMINPANEL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ReporterAdminPanel; }
QT_END_NAMESPACE

class ReporterAdminPanel : public QMainWindow
{
    Q_OBJECT

public:
    ReporterAdminPanel(QWidget *parent = nullptr);
    ~ReporterAdminPanel();

private:
    Ui::ReporterAdminPanel *ui;
};
#endif // REPORTERADMINPANEL_H
