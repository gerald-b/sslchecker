#include "mycertvaliddate.hpp"

QDate MyCertValidDate::getValidFrom() const
{
    return validFrom;
}

MyCertStates MyCertValidDate::getState() const
{
    return state;
}

void MyCertValidDate::setNewState(MyCertStates state)
{
    this->setState(state);
}

void MyCertValidDate::setState(const MyCertStates &value)
{
    state = value;
}

MyCertValidDate::MyCertValidDate(QDate from, QDate to, MyCertStates state)
{
    this->setValidFrom(from);
    this->setValidTo(to);
    this->setState(state);
}

void MyCertValidDate::setValidFrom(const QDate &value)
{
    validFrom = value;
}

QDate MyCertValidDate::getValidTo() const
{
    return validTo;
}

void MyCertValidDate::setValidTo(const QDate &value)
{
    validTo = value;
}
