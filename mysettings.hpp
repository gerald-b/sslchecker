#ifndef MYSETTINGS_HPP
#define MYSETTINGS_HPP

#include <QSettings>
#include <QVariant>
#include <QString>

class MySettings
{
private:
    static MySettings *_instance;
    QSettings *_settings;
    MySettings();
public:
    static MySettings *getInstance(void);

    MySettings(MySettings const&)     = delete;
    void operator=(MySettings const&) = delete;
    // Note: Scott Meyers mentions in his Effective Modern
    //       C++ book, that deleted functions should generally
    //       be public as it results in better error messages
    //       due to the compilers behavior to check accessibility
    //       before deleted status
    // Thanks stackoverflow and the community

    QVariant value(const QString &key, const QVariant &defaultValue = QVariant());
    QVariant getValue(const QString &key, const QVariant &defaultValue = QVariant());
    void setValue(const QString &key, const QVariant &value);
};

#endif // MYSETTINGS_HPP
