#ifndef FRMDETAIL_HPP
#define FRMDETAIL_HPP

#include <QMainWindow>
#include "frmdetailadddomainhost.hpp"
#include "mycert.hpp"

namespace Ui {
class FrmDetail;
}

class FrmDetail : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmDetail(QWidget *parent = nullptr);
    ~FrmDetail();

public slots:
    void getCert4View(MyCert * cert);

private slots:
    void on_btnDomainsAdd_clicked();

    void on_btnHostsAdd_clicked();

    void addNewHost(QString host);
    void addNewDomain(QString domain);

private:
    Ui::FrmDetail *ui;
    MyCert * _cert;

    MyCert *getCert() const;
    void setCert(MyCert *cert);

    void clearDisplay(void);
    void displayCert(void);
};

#endif // FRMDETAIL_HPP
