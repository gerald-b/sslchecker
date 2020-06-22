#include "mysettings.hpp"

MySettings* MySettings::_instance = nullptr;

MySettings::MySettings()
{
    this->_settings = new QSettings("./app.ini",QSettings::IniFormat);
}

MySettings *MySettings::getInstance()
{
    if (nullptr == _instance)
    {
        _instance  = new MySettings();
    }
    return _instance;
}

QVariant MySettings::value(const QString &key, const QVariant &defaultValue)
{
    return this->_settings->value(key,defaultValue);
}

QVariant MySettings::getValue(const QString &key, const QVariant &defaultValue)
{
    return this->value(key,defaultValue);
}

void MySettings::setValue(const QString &key, const QVariant &value)
{
    this->_settings->setValue(key,value);
}
