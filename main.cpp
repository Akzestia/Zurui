
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtQml/QQmlExtensionPlugin>

#include "theme_manager/theme_manager.h"
#include "translation_tools/translation_manager.h"

Q_IMPORT_QML_PLUGIN(UIComponentsPlugin)
Q_IMPORT_QML_PLUGIN(TranslationToolsPlugin)
Q_IMPORT_QML_PLUGIN(ThemeManagerPlugin)

int main(int argc, char* argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    ThemeManager themeManager(&engine);
    TranslationManager translationManager(&engine);

    themeManager.update("themes/zurui_light/conf.qml");

    engine.rootContext()->setContextProperty("themeManager", &themeManager);
    engine.rootContext()->setContextProperty("translationManager", &translationManager);

    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreationFailed, &app,
        []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);
    engine.loadFromModule("Zurui", "Main");

    return app.exec();
}
