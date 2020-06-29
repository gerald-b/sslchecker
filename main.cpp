#include "frmmain.hpp"

#include "mysettings.hpp"
#include <QApplication>
#include <QTranslator>
#include <QMessageBox>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QString langFile = QString("./language/").append(MySettings::getInstance()->value("language/current").toString()).append(".qm");
    QString errMsg = "";
    bool hasLanguage = true;
    if (!QFile::exists(langFile))
    {
        errMsg += QObject::tr("FILE");
        errMsg += " " + langFile + " ";
        errMsg += QObject::tr("NOT FOUND");
        errMsg += "\n\n";
        errMsg += QObject::tr("TRY TO LOAD FALLBACK");
        QMessageBox::warning(nullptr,QObject::tr("WARNING"),errMsg,QMessageBox::Ok,QMessageBox::Ok);
        langFile = QString("./language/english.qm");
        if (!QFile::exists(langFile))
        {
            errMsg = QObject::tr("FALLBACK LANGUAGE (ENGLISH) ALSO NOT FOUND");
            errMsg += "\n\n";
            errMsg += QObject::tr("RUNNING ON DEVELOPMENT NAMING!");
            QMessageBox::warning(nullptr,QObject::tr("WARNING"),errMsg,QMessageBox::Ok,QMessageBox::Ok);
            hasLanguage = false;
        }
        else
        {
            errMsg = QObject::tr("FALLBACK LANGUAGE (ENGLISH) FOUND");
            errMsg += "\n\n";
            errMsg += QObject::tr("PROCEED WITH THIS");
            QMessageBox::information(nullptr,QObject::tr("INFORMATION"),errMsg,QMessageBox::Ok,QMessageBox::Ok);
        }
    }
    if (hasLanguage)
    {
        QTranslator *lang = new QTranslator(&a);
        lang->load(langFile);
        a.installTranslator(lang);
    }
    FrmMain w;
    w.show();
    return a.exec();
}
