#ifndef MYCERTAFFECTEDHOST_HPP
#define MYCERTAFFECTEDHOST_HPP

#include <QString>
#include "mycertstates.hpp"

class MyCertAffectedHost
{
private:
    int _hostID;
    QString _hostname;
    MyCertStates _status;
    void setHostID(int hostID);
    void setHostname(const QString &hostname);
public:
    MyCertAffectedHost(int id, QString host, MyCertStates status);
    int hostID() const;
    QString hostname() const;
    MyCertStates status() const;
    void setStatus(const MyCertStates &status);
};

#endif // MYCERTAFFECTEDHOST_HPP
