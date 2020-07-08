#include "frmdetailaddvaliddate.hpp"
#include "ui_frmdetailaddvaliddate.h"

FrmDetailAddValidDate::FrmDetailAddValidDate(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmDetailAddValidDate)
{
    ui->setupUi(this);
    connect(this->ui->btnCancel,&QPushButton::clicked,this,&QMainWindow::close);
    this->setFixedSize(this->width(),this->height());
    this->setWindowTitle(tr("FRMDETAILADD - VALIDDATE"));
}

FrmDetailAddValidDate::~FrmDetailAddValidDate()
{
    delete ui;
}
