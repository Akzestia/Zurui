#include "theme_manager.h"

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QProcess>
#include <QQmlComponent>
#include <QQmlContext>

#include "qdir.h"
#include "qlogging.h"
#include "qobject.h"
#include "qobjectdefs.h"

ThemeManager::ThemeManager(QQmlEngine* engine, QObject* parent) noexcept
    : QObject(parent), m_engine(engine), m_current_theme(nullptr) {
    loadThemes();
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

    QQmlComponent component(m_engine, QUrl::fromLocalFile(path));
    if (component.status() != QQmlComponent::Ready) {
#ifdef ZURUI_DEBUG
        qWarning() << "Failed to load theme:" << component.errorString();
#endif
        return nullptr;
    }

    QObject* themeObject = component.create();
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
