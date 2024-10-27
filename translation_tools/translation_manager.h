#ifndef TRANSLATION_MANAGER_H
#define TRANSLATION_MANAGER_H

#include <QGuiApplication>
#include <QObject>
#include <QQmlEngine>
#include <QTranslator>

/*

    TranslationManager - main class used for handling language translations
    in the application. This class is responsible for loading and applying
    translations based on the selected language. Note! This class should only
    manage the translations; the actual text rendering should be handled
    separately by the UI components.

    Only 1 instance of TranslationManager should be created, which must be
    reused throughout the application's lifetime.

*/

class TranslationManager : public QObject {
    Q_OBJECT
  public:
    explicit TranslationManager(QQmlEngine* engine, QObject* parent = nullptr);

    Q_INVOKABLE void changeLanguage(const QString& languageCode);

  private:
    QTranslator m_translator;
    QQmlEngine* m_engine;
};

#endif  // TRANSLATION_MANAGER_H
