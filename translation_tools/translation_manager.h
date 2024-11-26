#ifndef TRANSLATION_MANAGER_H
#define TRANSLATION_MANAGER_H

#include <QGuiApplication>
#include <QObject>
#include <QQmlEngine>
#include <QTranslator>

/*!
 * \class TranslationManager
 * \brief Manages language translations for the application.
 *
 * The TranslationManager class is responsible for loading and applying
 * language translations based on the selected language. This class does
 * not handle text rendering, which is managed separately by UI components.
 *
 * Only one instance of TranslationManager should be created and reused
 * throughout the application's lifetime.
 */
class TranslationManager : public QObject {
    Q_OBJECT
  public:
    explicit TranslationManager(QQmlEngine* engine, QObject* parent = nullptr);

    Q_INVOKABLE QString currentLanguage() const;

    Q_INVOKABLE void changeLanguage(const QString& languageCode);

  private:
    QTranslator m_translator;  ///< Handles the language translation files.
    QQmlEngine* m_engine;      ///< Pointer to the application's QQmlEngine.
};

#endif  // TRANSLATION_MANAGER_H
