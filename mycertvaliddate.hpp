#ifndef MYCERTVALIDDATE_HPP
#define MYCERTVALIDDATE_HPP

#include <QDate>
#include "mycertstates.hpp"

class MyCertValidDate
{
private:
    QDate validFrom;
    QDate validTo;
    MyCertStates state;

    void setValidFrom(const QDate &value);
    void setValidTo(const QDate &value);
    void setState(const MyCertStates &value);
public:
    MyCertValidDate(QDate from, QDate to, MyCertStates state);

    QDate getValidFrom() const;
    QDate getValidTo() const;

    MyCertStates getState() const;
    void setNewState(MyCertStates state);
};

#endif // MYCERTVALIDDATE_HPP
