#ifndef MYCERT_HPP
#define MYCERT_HPP

#include <QList>
#include "mycertvaliddate.hpp"
#include "mycertaffecteddomain.hpp"

class MyCert
{
private:
    QString _certName;
    int _certID;
    QList<MyCertValidDate> validList;
    QList<MyCertAffectedDomain> affectedDomains;
    QList<QString> affectedHosts;

    void setCertName(const QString &certName);
    void setCertID(int certID);
public:
    MyCert(int id, QString name);

    QString certName() const;
    int certID() const;
    void appendValidDate(MyCertValidDate date);
    void appendAffectedDomain(MyCertAffectedDomain domain);
    void appendAffectedHost(QString host);
    int getCountAffectedDomains(void);
    int getCountAffectedHosts(void);
    QDate getActiveValidFromDate(void);
    QDate getActiveValidToDate(void);
};

#endif // MYCERT_HPP
