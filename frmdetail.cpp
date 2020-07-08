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
        // Display ValidDates
        QList<MyCertValidDate> cvd = this->getCert()->getValidDates();
        for (int i = 0; i<cvd.count();++i)
        {
            int curRowValidDate = this->ui->tblValidDates->rowCount();
            this->ui->tblValidDates->setRowCount(curRowValidDate+1);
            this->ui->tblValidDates->setItem(curRowValidDate, 0,
                                             new QTableWidgetItem(
                                                 QString::number(cvd.at(i).dateID())
                                                 )
                                             );
            this->ui->tblValidDates->setItem(curRowValidDate, 1,
                                             new QTableWidgetItem(
                                                 cvd.at(i).getValidFrom().toString(Qt::ISODate)
                                                 )
                                             );
            this->ui->tblValidDates->setItem(curRowValidDate, 2,
                                             new QTableWidgetItem(
                                                 cvd.at(i).getValidTo().toString(Qt::ISODate)
                                                 )
                                             );
            this->ui->tblValidDates->setItem(curRowValidDate, 3,
                                             new QTableWidgetItem("")
                                             );
            for(int z=0;z<this->ui->tblValidDates->columnCount();++z)
            {
                QTableWidgetItem * item = this->ui->tblValidDates->item(curRowValidDate ,z);
                item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            }
        }
        // Display AffectedHosts
        QList<MyCertAffectedHost> cah = this->getCert()->getAffectedHosts();
        for (int i = 0; i<cah.count();++i)
        {
            int curRowAffectedHosts = this->ui->tblHosts->rowCount();
            this->ui->tblHosts->setRowCount(curRowAffectedHosts+1);
            this->ui->tblHosts->setItem(curRowAffectedHosts, 0,
                                             new QTableWidgetItem(
                                                 QString::number(cah.at(i).hostID())
                                                 )
                                             );
            this->ui->tblHosts->setItem(curRowAffectedHosts, 1,
                                             new QTableWidgetItem(
                                                 cah.at(i).hostname()
                                                 )
                                             );
            this->ui->tblHosts->setItem(curRowAffectedHosts, 2,
                                             new QTableWidgetItem("")
                                             );
            for(int z=0;z<this->ui->tblHosts->columnCount();++z)
            {
                QTableWidgetItem * item = this->ui->tblHosts->item(curRowAffectedHosts ,z);
                item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            }
        }
        // Display AffectedDomains
        QList<MyCertAffectedDomain> cad = this->getCert()->getAffectedDomains();
        for (int i = 0; i<cad.count();++i)
        {
            int curRowAffectedDomains = this->ui->tblDomains->rowCount();
            this->ui->tblDomains->setRowCount(curRowAffectedDomains+1);
            this->ui->tblDomains->setItem(curRowAffectedDomains, 0,
                                             new QTableWidgetItem(
                                                 QString::number(cad.at(i).domainID())
                                                 )
                                             );
            this->ui->tblDomains->setItem(curRowAffectedDomains, 1,
                                             new QTableWidgetItem(
                                                 cad.at(i).domainname()
                                                 )
                                             );
            this->ui->tblDomains->setItem(curRowAffectedDomains, 2,
                                             new QTableWidgetItem("")
                                             );
            for(int z=0;z<this->ui->tblDomains->columnCount();++z)
            {
                QTableWidgetItem * item = this->ui->tblDomains->item(curRowAffectedDomains ,z);
                item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            }
        }

        this->ui->tblValidDates->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        this->ui->tblValidDates->horizontalHeader()->setStretchLastSection(true);
        this->ui->tblHosts->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        this->ui->tblHosts->horizontalHeader()->setStretchLastSection(true);
        this->ui->tblDomains->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        this->ui->tblDomains->horizontalHeader()->setStretchLastSection(true);
        // Always select first row (if there is one)
        // if (0 < this->ui->tblValidDates->rowCount())
        // {
        //    this->ui->tblValidDates->selectRow(0);
        // }
        if (0 < this->ui->tblDomains->rowCount())
        {
            this->ui->tblDomains->selectRow(0);
        }
        if (0 < this->ui->tblHosts->rowCount())
        {
            this->ui->tblHosts->selectRow(0);
        }
    }
}



void FrmDetail::on_btnDomainsAdd_clicked()
{
    FrmDetailAddDomainHost *dadh = new FrmDetailAddDomainHost(FrmDetailAddDomainHostType::DOMAIN,this);
    dadh->setWindowModality(Qt::ApplicationModal);
    dadh->show();
}

void FrmDetail::on_btnHostsAdd_clicked()
{
    FrmDetailAddDomainHost *dadh = new FrmDetailAddDomainHost(FrmDetailAddDomainHostType::HOST,this);
    dadh->setWindowModality(Qt::ApplicationModal);
    dadh->show();
}

void FrmDetail::addNewHost(QString host)
{

}

void FrmDetail::addNewDomain(QString domain)
{

}
