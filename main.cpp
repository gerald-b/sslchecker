#include "frmmain.hpp"

#include "mysettings.hpp"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString langFile = QString("./language/").append(MySettings::getInstance()->value("language/current").toString()).append(".qm");
    QTranslator *lang = new QTranslator(&a);
    lang->load(langFile);
    a.installTranslator(lang);

    FrmMain w;
    w.show();
    return a.exec();
}
