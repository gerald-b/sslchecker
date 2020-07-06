#ifndef FRMDETAILADDDOMAINHOST_HPP
#define FRMDETAILADDDOMAINHOST_HPP

#include <QMainWindow>

namespace Ui {
class FrmDetailAddDomainHost;
}

class FrmDetailAddDomainHost : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmDetailAddDomainHost(QWidget *parent = nullptr);
    ~FrmDetailAddDomainHost();

private:
    Ui::FrmDetailAddDomainHost *ui;
};

#endif // FRMDETAILADDDOMAINHOST_HPP
