#ifndef FRMDETAILADDVALIDDATE_HPP
#define FRMDETAILADDVALIDDATE_HPP

#include <QMainWindow>

namespace Ui {
class FrmDetailAddValidDate;
}

class FrmDetailAddValidDate : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmDetailAddValidDate(QWidget *parent = nullptr);
    ~FrmDetailAddValidDate();

private:
    Ui::FrmDetailAddValidDate *ui;
};

#endif // FRMDETAILADDVALIDDATE_HPP
