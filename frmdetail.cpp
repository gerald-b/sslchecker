#include "frmdetail.hpp"
#include "ui_frmdetail.h"

FrmDetail::FrmDetail(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmDetail)
{
    ui->setupUi(this);

    this->setCert(nullptr);

    connect(this->ui->action_EXIT,&QAction::triggered,this,&QMainWindow::close);

    this->displayCert();
}

FrmDetail::~FrmDetail()
{
    delete ui;
}

void FrmDetail::getCert4View(MyCert *cert)
{
    this->setCert(cert);
    this->displayCert();
}

MyCert *FrmDetail::getCert() const
{
    return _cert;
}

void FrmDetail::setCert(MyCert *cert)
{
    _cert = cert;
}

void FrmDetail::displayCert()
{
    if (nullptr != this->getCert())
    {
        this->ui->txtCertID->setText(QString::number(this->getCert()->certID()));
        this->ui->txtCertName->setText(this->getCert()->certName());
    }
}


