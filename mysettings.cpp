#include "mysettings.hpp"

MySettings* MySettings::_instance = nullptr;

MySettings::MySettings()
{

}

MySettings *MySettings::getInstance()
{
    if (nullptr == _instance)
    {
        _instance  = new MySettings();
    }
    return _instance;
}
