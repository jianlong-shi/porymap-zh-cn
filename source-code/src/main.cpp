#include "mainwindow.h"
#include "loadingscreen.h"

#include <QApplication>
#include <QCoreApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::Round);
    QCoreApplication::setAttribute(Qt::AA_UseStyleSheetPropagationInWidgetStyles, true);

    QApplication a(argc, argv);
    a.setStyle("fusion");

    // The localized build stays beside the original Porymap executable.
    QTranslator zhTranslator;
    const QString translationPath = QCoreApplication::applicationDirPath() + "/porymap_zh_CN.qm";
    if (zhTranslator.load(translationPath))
        a.installTranslator(&zhTranslator);

    porysplash = new PorymapLoadingScreen;

    QObject::connect(&a, &QCoreApplication::aboutToQuit, [=]() { delete porysplash; });

    MainWindow w(nullptr);
    w.initialize();

    return a.exec();
}
