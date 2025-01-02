#include "theme_manager.h"

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QProcess>
#include <QQmlComponent>
#include <QQmlContext>

#include "qdebug.h"
#include "qdir.h"
#include "qlogging.h"
#include "qobject.h"
#include "qobjectdefs.h"
#include "qpoint.h"

ThemeManager::ThemeManager(QQmlEngine* engine, QObject* parent) noexcept
    : QObject(parent), m_engine(engine), m_current_theme(nullptr) {
    loadThemes();
    m_live_xt.monitor();

    connect(&m_live_xt, &LiveUpdateXt::request_theme_update, this,
            &ThemeManager::theme_config_changed);
}

void ThemeManager::theme_config_changed(const QString& path) {
#ifdef ZURUI_DEBUG
    qDebug() << "Theme configuration was changed at: " << path;
#endif
    m_current_theme = createThemeObject(path);
    emit currentThemeChanged();
}

void ThemeManager::loadThemes() {
    QDir themesDir(QDir::currentPath() + "/themes");

    if (!themesDir.exists()) {
        qWarning() << "Themes directory does not exist!";
        return;
    }

#ifdef ZURUI_DEBUG
    qDebug() << "Executing command: tree themes";
#endif

#ifdef ZURUI_DEBUG
    QProcess process;
    process.start("tree", QStringList() << "themes");
    process.waitForFinished();

    QString output = process.readAllStandardOutput();
    if (!output.isEmpty()) {
        qDebug() << "Directory structure of 'themes':\n" << output;
    }
#endif

    for (const QFileInfo& dirInfo :
         themesDir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot)) {
        QString themeName = dirInfo.fileName();
        QString themePath = dirInfo.absoluteFilePath() + "/conf.qml";

#ifdef ZURUI_DEBUG
        qDebug() << "Attempting to load theme:" << themePath;
#endif

        QObject* themeObject = createThemeObject(themePath);
        if (themeObject) {
            m_themes.insert(themeName, QVariant::fromValue(themeObject));
            m_live_xt.addPath(themePath);
        }
    }
}

QVariantMap ThemeManager::availableThemes() const {
    return m_themes;
}

QObject* ThemeManager::createThemeObject(const QString& path) {
    if (!QFile::exists(path)) {
#ifdef ZURUI_DEBUG
        qWarning() << "Theme file does not exist at path:" << path;
#endif
        return nullptr;
    }

    m_engine->clearComponentCache();
    m_engine->trimComponentCache();
    m_engine->collectGarbage();

    QUrl themeUrl = QUrl::fromLocalFile(path);
    // themeUrl.setQuery("nocache="
    //                   + QString::number(QDateTime::currentMSecsSinceEpoch()));

    QQmlComponent* component = new QQmlComponent(m_engine, themeUrl);
    component->loadUrl(themeUrl, QQmlComponent::PreferSynchronous);

    // QProcess process;
    // process.start("cat", QStringList() << path);
    // process.waitForFinished();
    // QString output = process.readAllStandardOutput();
    // if (!output.isEmpty()) {
    //     qDebug() << "Theme file:\n" << output;
    //     auto split = output.split('\n');
    //     for (int i = 0; i < split.size(); i++) {
    //         qDebug() << split[i];
    //     }
    // }

    if (component->status() != QQmlComponent::Ready) {
#ifdef ZURUI_DEBUG
        qWarning() << "Failed to load theme:" << component->errorString();
#endif
        delete component;
        return nullptr;
    }

    QObject* themeObject = component->create();
    delete component;

    if (!themeObject) {
#ifdef ZURUI_DEBUG
        qWarning() << "Failed to instantiate theme object from QML file";
#endif
    }

    return themeObject;
}

void ThemeManager::update(const QString& theme_name) {
    if (!m_themes.contains(theme_name)) {
        qWarning() << "Theme not found:" << theme_name;
        return;
    }

    m_current_theme = m_themes[theme_name].value<QObject*>();
    if (!m_current_theme) {
        qWarning() << "Failed to instantiate theme object from QML file";
        return;
    }

    emit currentThemeChanged();
}

ThemeManager::~ThemeManager() {
    if (m_current_theme)
        delete m_current_theme;
}
