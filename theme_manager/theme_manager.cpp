#include "theme_manager.h"

#include "qglobal.h"
#include "qobject.h"

ThemeManager::ThemeManager(QQmlEngine* engine, QObject* parent)
    : QObject(parent), m_engine(engine) {
}

void ThemeManager::update() {
}

ThemeManager::~ThemeManager() {
    if (m_engine)
        delete m_engine;
}
