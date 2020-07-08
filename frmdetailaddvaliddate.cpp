#include "frmdetailaddvaliddate.hpp"
#include "ui_frmdetailaddvaliddate.h"

FrmDetailAddValidDate::FrmDetailAddValidDate(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmDetailAddValidDate)
{
    ui->setupUi(this);
}

FrmDetailAddValidDate::~FrmDetailAddValidDate()
{
    delete ui;
}
