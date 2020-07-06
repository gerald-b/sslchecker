#include "frmdetailadddomainhost.hpp"
#include "ui_frmdetailadddomainhost.h"

FrmDetailAddDomainHost::FrmDetailAddDomainHost(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmDetailAddDomainHost)
{
    ui->setupUi(this);
}

FrmDetailAddDomainHost::~FrmDetailAddDomainHost()
{
    delete ui;
}
