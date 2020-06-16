#include "frmdetail.hpp"
#include "ui_frmdetail.h"

FrmDetail::FrmDetail(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmDetail)
{
    ui->setupUi(this);


    connect(this->ui->action_EXIT,&QAction::triggered,this,&QMainWindow::close);
}

FrmDetail::~FrmDetail()
{
    delete ui;
}
