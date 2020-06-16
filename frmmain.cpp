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
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("./certdata.db");

    if (mydb.open())
    {
        QSqlQuery query(mydb);
        query.exec("SELECT * FROM `tbl_certs`");
        while(query.next())
        {
            MyCert * c = new MyCert(query.value(0).toInt(),query.value(1).toString());
            this->mycertlist.append(c);
        }

        for(int i=0; i<this->mycertlist.count(); ++i)
        {
            MyCert * c = this->mycertlist.at(i);
            query.exec("SELECT * FROM `tbl_domains` WHERE `fk_certs` ='" + QString::number(c->certID()) + "'");
            while(query.next())
            {
                c->appendAffectedDomain(MyCertAffectedDomain(query.value(0).toInt(), query.value(2).toString(), static_cast<MyCertStates>(query.value(3).toInt())));
            }
            query.exec("SELECT * FROM `tbl_hosts` WHERE `fk_certs` ='" + QString::number(c->certID()) + "'");
            while(query.next())
            {
                c->appendAffectedHost(MyCertAffectedHost(query.value(0).toInt(), query.value(2).toString(), static_cast<MyCertStates>(query.value(3).toInt())));
            }
        }
    }

    /*
    MyCert * c = new MyCert("*.example.com");
    c->appendValidDate(MyCertValidDate(QDate(2018,06,13),QDate(2020,6,26),MyCertStates::ACTIVE));
    c->appendAffectedDomain("blog.example.com");
    c->appendAffectedDomain("grafana.example.com");
    c->appendAffectedHost("fqdn.example.com");
    this->mycertlist.append(c);
    */

    for (int i=0; i<this->mycertlist.count(); ++i)
    {
        int curRow = this->ui->tblCertList->rowCount();
        this->ui->tblCertList->setRowCount(curRow+1);
        this->ui->tblCertList->setItem(curRow,0,new QTableWidgetItem(QString::number(this->mycertlist.at(i)->certID())));
        this->ui->tblCertList->setItem(curRow,1,new QTableWidgetItem(this->mycertlist.at(i)->certName()));
        this->ui->tblCertList->setItem(curRow,2,new QTableWidgetItem(this->mycertlist.at(i)->getActiveValidFromDate().toString(Qt::ISODate)));
        this->ui->tblCertList->setItem(curRow,3,new QTableWidgetItem(this->mycertlist.at(i)->getActiveValidToDate().toString(Qt::ISODate)));
        this->ui->tblCertList->setItem(curRow,4,new QTableWidgetItem(QString::number(this->mycertlist.at(i)->getCountAffectedDomains())));
        this->ui->tblCertList->setItem(curRow,5,new QTableWidgetItem(QString::number(this->mycertlist.at(i)->getCountAffectedHosts())));
        this->ui->tblCertList->setItem(curRow,6,new QTableWidgetItem(""));
        for(int z=0;z<=6;++z)
        {
            QTableWidgetItem * item = this->ui->tblCertList->item(curRow ,z);
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        }
    }
    //**********
    // TEST END
    //**********
    this->ui->tblCertList->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    this->ui->tblCertList->horizontalHeader()->setStretchLastSection(true);
}

FrmMain::~FrmMain()
{
    delete ui;
}


void FrmMain::on_btnDetails_clicked()
{
    FrmDetail * detail = new FrmDetail(this);
    detail->setWindowModality(Qt::ApplicationModal);
    detail->show();
}
