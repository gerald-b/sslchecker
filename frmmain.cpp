#include "frmmain.hpp"
#include "ui_frmmain.h"

FrmMain::FrmMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FrmMain)
{
    ui->setupUi(this);
    // ToDo4Release
    // this->ui->tblCertList->setColumnHidden(0,true);

    connect(this->ui->action_EXIT,&QAction::triggered,this,&QApplication::exit);
}

FrmMain::~FrmMain()
{
    delete ui;
}

