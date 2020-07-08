#ifndef FRMDETAILADDDOMAINHOST_HPP
#define FRMDETAILADDDOMAINHOST_HPP

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include "frmdetailadddomainhosttype.hpp"

namespace Ui {
class FrmDetailAddDomainHost;
}

class FrmDetailAddDomainHost : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmDetailAddDomainHost(FrmDetailAddDomainHostType type, QWidget *parent = nullptr);
    ~FrmDetailAddDomainHost();

    FrmDetailAddDomainHostType getCurrentType() const;

signals:
    void sendNewHostname(QString host);
    void sendNewDomainname(QString domain);

private slots:
    void on_btnAdd_clicked();

private:
    Ui::FrmDetailAddDomainHost *ui;
    FrmDetailAddDomainHostType currentType;

    void setCurrentType(const FrmDetailAddDomainHostType &value);
};

#endif // FRMDETAILADDDOMAINHOST_HPP
