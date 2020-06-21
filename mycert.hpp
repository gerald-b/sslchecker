#ifndef MYCERT_HPP
#define MYCERT_HPP

#include <QList>
#include "mycertvaliddate.hpp"
#include "mycertaffecteddomain.hpp"
#include "mycertaffectedhost.hpp"

class MyCert
{
private:
    QString _certName;
    int _certID;
    QList<MyCertValidDate> validList;
    QList<MyCertAffectedDomain> affectedDomains;
    QList<MyCertAffectedHost> affectedHosts;

    void setCertName(const QString &certName);
    void setCertID(int certID);
public:
    MyCert(int id, QString name);

    QString certName() const;
    int certID() const;
    void appendValidDate(MyCertValidDate date);
    void appendAffectedDomain(MyCertAffectedDomain domain);
    void appendAffectedHost(MyCertAffectedHost host);
    int getCountAffectedDomains(void);
    int getCountAffectedHosts(void);
    QDate getActiveValidFromDate(void);
    QDate getActiveValidToDate(void);
    QList<MyCertValidDate> getValidDates(void) const;
    QList<MyCertAffectedHost> getAffectedHosts(void) const;
    QList<MyCertAffectedDomain> getAffectedDomains(void) const;
};

#endif // MYCERT_HPP
