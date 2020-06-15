#ifndef MYCERTAFFECTEDDOMAIN_HPP
#define MYCERTAFFECTEDDOMAIN_HPP

#include <QString>
#include "mycertstates.hpp"

class MyCertAffectedDomain
{
private:
    int _domainID;
    QString _domainname;
    MyCertStates _status;
    void setDomainID(int domainID);
    void setDomainname(const QString &domainname);
public:
    MyCertAffectedDomain(int id, QString domain, MyCertStates status);

    int domainID() const;
    QString domainname() const;
    MyCertStates status() const;

    void setStatus(const MyCertStates &status);
};

#endif // MYCERTAFFECTEDDOMAIN_HPP
