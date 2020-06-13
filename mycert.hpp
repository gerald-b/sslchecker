#ifndef MYCERT_HPP
#define MYCERT_HPP

#include <QList>
#include "mycertvaliddate.hpp"

class MyCert
{
private:
    QString _certName;
    QList<MyCertValidDate> validList;
    QList<QString> affectedDomains;
    QList<QString> affectedHosts;

    void setCertName(const QString &certName);
public:
    MyCert(QString name);

    QString certName() const;
    void appendValidDate(MyCertValidDate date);
    void appendAffectedDomain(QString domain);
    void appendAffectedHost(QString host);
    int getCountAffectedDomains(void);
    int getCountAffectedHosts(void);
    QDate getActiveValidFromDate(void);
    QDate getActiveValidToDate(void);
};

#endif // MYCERT_HPP
