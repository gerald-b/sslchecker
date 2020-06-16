#ifndef MYCERTVALIDDATE_HPP
#define MYCERTVALIDDATE_HPP

#include <QDate>
#include "mycertstates.hpp"

class MyCertValidDate
{
private:
    int _dateID;
    QDate validFrom;
    QDate validTo;
    MyCertStates state;

    void setValidFrom(const QDate &value);
    void setValidTo(const QDate &value);
    void setState(const MyCertStates &value);
    void setDateID(int dateID);
public:
    MyCertValidDate(int id, QDate from, QDate to, MyCertStates state);

    QDate getValidFrom() const;
    QDate getValidTo() const;

    MyCertStates getState() const;
    void setNewState(MyCertStates state);
    int dateID() const;
};

#endif // MYCERTVALIDDATE_HPP
