#include <QApplication>
#include <QDebug>
#include <QGuiApplication>
#include <QProcess>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QScreenCapture>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreationFailed, &app,
        []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);

    engine.loadFromModule("Zurui", "Main");

    return app.exec();
}
