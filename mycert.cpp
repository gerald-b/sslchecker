#include "mycert.hpp"

QString MyCert::certName() const
{
    return _certName;
}

void MyCert::appendValidDate(MyCertValidDate date)
{
    this->validList.append(date);
}

void MyCert::appendAffectedDomain(MyCertAffectedDomain domain)
{
    this->affectedDomains.append(domain);
}

void MyCert::appendAffectedHost(MyCertAffectedHost host)
{
    this->affectedHosts.append(host);
}

int MyCert::getCountAffectedDomains()
{
    return this->affectedDomains.count();
}

int MyCert::getCountAffectedHosts()
{
    return this->affectedHosts.count();
}

QDate MyCert::getActiveValidFromDate()
{
    QDate res = QDate(1,1,1);
    for(int i=0; i<this->validList.count(); ++i)
    {
        if(MyCertStates::ACTIVE == this->validList.at(i).getState())
        {
            res = this->validList.at(i).getValidFrom();
            break;
        }
    }
    return res;
}

QDate MyCert::getActiveValidToDate()
{
    QDate res = QDate(1,1,1);
    for(int i=0; i<this->validList.count(); ++i)
    {
        if(MyCertStates::ACTIVE == this->validList.at(i).getState())
        {
            res = this->validList.at(i).getValidTo();
            break;
        }
    }
    return res;
}

int MyCert::certID() const
{
    return _certID;
}

void MyCert::setCertID(int certID)
{
    _certID = certID;
}

void MyCert::setCertName(const QString &certName)
{
    _certName = certName;
}

MyCert::MyCert(int id, QString name)
{
    this->setCertID(id);
    this->setCertName(name);
}
