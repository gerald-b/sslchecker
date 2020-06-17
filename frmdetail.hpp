#ifndef FRMDETAIL_HPP
#define FRMDETAIL_HPP

#include <QMainWindow>
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

private:
    Ui::FrmDetail *ui;
    MyCert * _cert;

    MyCert *getCert() const;
    void setCert(MyCert *cert);
};

#endif // FRMDETAIL_HPP
