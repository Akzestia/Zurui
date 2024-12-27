
#include <QApplication>
#include <QDir>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QWindow>
#include <QtQml/QQmlExtensionPlugin>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#include "key_bindings/key_binding_manager.h"
#include "preloading_manager/preloading_manager.h"
#include "qdebug.h"
#include "qnamespace.h"
#include "qplugin.h"
#include "qqml.h"
#include "systray/systray.h"
#include "theme_manager/theme_manager.h"
#include "translation_tools/translation_manager.h"

/*
    Note: From now on, application will use mostly dynamic linking,
    so please consider avoiding implicit static linking of any modules.
*/
Q_IMPORT_PLUGIN(TranslationToolsPlugin)

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.addImportPath(":/");
    engine.addImportPath("qrc:/ui_components");

#ifdef ZURUI_DEBUG
    QDir resourceDir(":/");
    if (!resourceDir.exists()) {
        qDebug() << "The directory does not exist.";
    }

    QStringList entries =
        resourceDir.entryList(QDir::Files | QDir::NoDotAndDotDot);
    for (const QString& entry : entries) {
        qDebug() << "File:" << entry;
    }
#endif

#ifdef ZURUI_DEBUG
    engine.rootContext()->setContextProperty("zurui_debug", true);
#else
    engine.rootContext()->setContextProperty("zurui_debug", false);
#endif

    // Context props
    ThemeManager themeManager(&engine);
    TranslationManager translationManager(&engine);
    PreloadingManager preloadingManager(&engine);
    KeyBindingManager keyBindingManager(&engine);
    translationManager.changeLanguage("ja");
    qDebug() << "Current language: [" << translationManager.currentLanguage()
             << "]";
    SysTray sysTray(&app);
    app.installEventFilter(&keyBindingManager);

    engine.rootContext()->setContextProperty("themeManager", &themeManager);
    engine.rootContext()->setContextProperty("keyBindingManager",
                                             &keyBindingManager);
    engine.rootContext()->setContextProperty("translationManager",
                                             &translationManager);
    engine.rootContext()->setContextProperty("preloadingManager",
                                             &preloadingManager);

    themeManager.update("zurui_dark");

    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreationFailed, &app,
        []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);

    engine.loadFromModule("Zurui", "Main");

    return app.exec();
}
