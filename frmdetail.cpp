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

        this->ui->tblValidDates->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        this->ui->tblValidDates->horizontalHeader()->setStretchLastSection(true);
    }
}


