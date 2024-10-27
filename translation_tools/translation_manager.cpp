#include "translation_manager.h"

TranslationManager::TranslationManager(QQmlEngine* engine, QObject* parent)
    : QObject(parent), m_engine(engine) {
}

void TranslationManager::changeLanguage(const QString& languageCode) {
    if (m_translator.load(":/translations/translations_" + languageCode
                          + ".qm")) {
        qApp->installTranslator(&m_translator);
        m_engine->retranslate();
    } else {
        qDebug() << "Failed to load translation file for" << languageCode;
    }
}
