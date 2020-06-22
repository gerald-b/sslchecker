#ifndef MYSETTINGS_HPP
#define MYSETTINGS_HPP

class MySettings
{
private:
    static MySettings *_instance;
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

};

#endif // MYSETTINGS_HPP
