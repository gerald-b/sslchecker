#include "frmdetail.hpp"
#include "ui_frmdetail.h"

FrmDetail::FrmDetail(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmDetail)
{
    ui->setupUi(this);

    this->setCert(nullptr);

    connect(this->ui->action_EXIT,&QAction::triggered,this,&QMainWindow::close);
}

FrmDetail::~FrmDetail()
{
    delete ui;
}

void FrmDetail::getCert4View(MyCert *cert)
{
    this->setCert(cert);
}

MyCert *FrmDetail::getCert() const
{
    return _cert;
}

void FrmDetail::setCert(MyCert *cert)
{
    _cert = cert;
}


