#include "mainsense.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <dataconfig.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "coinFlip_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainSense w;
    w.show();
    return a.exec();
}

