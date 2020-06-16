#ifndef FRMMAIN_HPP
#define FRMMAIN_HPP

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "mycert.hpp"
#include "frmdetail.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class FrmMain; }
QT_END_NAMESPACE

class FrmMain : public QMainWindow
{
    Q_OBJECT

public:
    FrmMain(QWidget *parent = nullptr);
    ~FrmMain();

private slots:
    void on_btnDetails_clicked();

private:
    Ui::FrmMain *ui;
    QList<MyCert *> mycertlist;
};
#endif // FRMMAIN_HPP
