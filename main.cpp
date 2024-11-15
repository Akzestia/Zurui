
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtQml/QQmlExtensionPlugin>
#include <QDir>
#include <iostream>

#include "key_bindings/key_binding_manager.h"
#include "theme_manager/theme_manager.h"
#include "translation_tools/translation_manager.h"

// Q_IMPORT_QML_PLUGIN(UIcomponentsPlugin)
// Q_IMPORT_QML_PLUGIN(TranslationToolsPlugin)
// Q_IMPORT_QML_PLUGIN(ThemeManagerPlugin)

/*!
 * \brief Overview of Plugin-Based Approach
 *
 * This application employs a plugin-based architecture to promote modularity
 * and flexibility. Each plugin represents a specific functionality or feature,
 * such as themes or UI components, allowing developers to extend or modify the
 * project without altering the core logic.
 *
 * Note: Importing plugins directly with `Q_IMPORT_QML_PLUGIN()` can increase
 * RAM usage during the build process, especially when plugins include
 * large-sized assets. Use with consideration to optimize memory consumption
 * during compilation.
 */
// Q_IMPORT_QML_PLUGIN(Zurui_lightPlugin)

int main(int argc, char* argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    KeyBindingManager keyBindingManager(&engine);

    engine.addImportPath("qrc:/ui_components");

    app.installEventFilter(&keyBindingManager);

    // const auto importPathList = engine.importPathList();
    // qDebug() << "QML Import Paths:";
    // for (const QString &path : importPathList) {
    //     qDebug() << path;
    // }
#ifdef ZURUI_DEBUG
    engine.rootContext()->setContextProperty("zurui_debug", true);
#else
    engine.rootContext()->setContextProperty("zurui_debug", false);
#endif

    ThemeManager themeManager(&engine);
    TranslationManager translationManager(&engine);

    engine.rootContext()->setContextProperty("themeManager", &themeManager);
    engine.rootContext()->setContextProperty("keyBindingManager", &keyBindingManager);
    engine.rootContext()->setContextProperty("translationManager",
                                             &translationManager);

    themeManager.update("zurui_dark");

    QObject* signUpProps = themeManager.currentTheme()
                               ->property("sign_up_props")
                               .value<QObject*>();
    // if (signUpProps) {
    //     QString bgSource = signUpProps->property("bg_source").toString();
    //     std::cout << "\n\nTheme asset path -> (" << bgSource.toStdString()
    //               << ")\n";
    // }

    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreationFailed, &app,
        []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);
    engine.loadFromModule("Zurui", "Main");

    return app.exec();
}
