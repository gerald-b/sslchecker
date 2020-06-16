#ifndef FRMDETAIL_HPP
#define FRMDETAIL_HPP

#include <QMainWindow>

namespace Ui {
class FrmDetail;
}

class FrmDetail : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmDetail(QWidget *parent = nullptr);
    ~FrmDetail();

private:
    Ui::FrmDetail *ui;
};

#endif // FRMDETAIL_HPP
