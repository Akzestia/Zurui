#include "theme_manager.h"

ThemeManager::ThemeManager(QQmlEngine* engine, QObject* parent) noexcept
    : m_engine(engine) {
}

ThemeManager::~ThemeManager() noexcept {
    if (m_current_theme) {
        delete m_current_theme;
        m_current_theme = nullptr;
    }
}

QObject* ThemeManager::currentTheme() const {
    return m_current_theme;
}

QVariantMap ThemeManager::availableThemes() const {
    return m_themes;
}
