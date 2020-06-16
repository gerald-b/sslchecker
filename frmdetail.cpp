#include "frmdetail.hpp"
#include "ui_frmdetail.h"

FrmDetail::FrmDetail(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmDetail)
{
    ui->setupUi(this);
}

FrmDetail::~FrmDetail()
{
    delete ui;
}
