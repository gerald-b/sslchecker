#include "mycertaffectedhost.hpp"

int MyCertAffectedHost::hostID() const
{
    return _hostID;
}

void MyCertAffectedHost::setHostID(int hostID)
{
    _hostID = hostID;
}

QString MyCertAffectedHost::hostname() const
{
    return _hostname;
}

void MyCertAffectedHost::setHostname(const QString &hostname)
{
    _hostname = hostname;
}

MyCertStates MyCertAffectedHost::status() const
{
    return _status;
}

void MyCertAffectedHost::setStatus(const MyCertStates &status)
{
    _status = status;
}

MyCertAffectedHost::MyCertAffectedHost(int id, QString host, MyCertStates status)
{
    this->setHostID(id);
    this->setHostname(host);
    this->setStatus(status);
}
