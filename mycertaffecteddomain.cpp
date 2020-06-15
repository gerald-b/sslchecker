#include "mycertaffecteddomain.hpp"

int MyCertAffectedDomain::domainID() const
{
    return _domainID;
}

void MyCertAffectedDomain::setDomainID(int domainID)
{
    _domainID = domainID;
}

QString MyCertAffectedDomain::domainname() const
{
    return _domainname;
}

void MyCertAffectedDomain::setDomainname(const QString &domainname)
{
    _domainname = domainname;
}

MyCertStates MyCertAffectedDomain::status() const
{
    return _status;
}

void MyCertAffectedDomain::setStatus(const MyCertStates &status)
{
    _status = status;
}

MyCertAffectedDomain::MyCertAffectedDomain(int id, QString domain, MyCertStates status)
{
    this->setDomainID(id);
    this->setDomainname(domain);
    this->setStatus(status);
}
