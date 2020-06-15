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

    //**********
    // TEST START
    //**********
    MyCert * c = new MyCert("*.example.com");
    c->appendValidDate(MyCertValidDate(QDate(2018,06,13),QDate(2020,6,26),MyCertStates::ACTIVE));
    c->appendAffectedDomain("blog.example.com");
    c->appendAffectedDomain("grafana.example.com");
    c->appendAffectedHost("fqdn.example.com");
    this->mycertlist.append(c);

    for (int i=0; i<this->mycertlist.count(); ++i)
    {
        int curRow = this->ui->tblCertList->rowCount();
        this->ui->tblCertList->setRowCount(curRow+1);
        this->ui->tblCertList->setItem(curRow,1,new QTableWidgetItem(this->mycertlist.at(i)->certName()));
        this->ui->tblCertList->setItem(curRow,2,new QTableWidgetItem(this->mycertlist.at(i)->getActiveValidFromDate().toString(Qt::ISODate)));
        this->ui->tblCertList->setItem(curRow,3,new QTableWidgetItem(this->mycertlist.at(i)->getActiveValidToDate().toString(Qt::ISODate)));
        this->ui->tblCertList->setItem(curRow,4,new QTableWidgetItem(QString::number(this->mycertlist.at(i)->getCountAffectedDomains())));
        this->ui->tblCertList->setItem(curRow,5,new QTableWidgetItem(QString::number(this->mycertlist.at(i)->getCountAffectedHosts())));
    }
    //**********
    // TEST END
    //**********
}

FrmMain::~FrmMain()
{
    delete ui;
}

