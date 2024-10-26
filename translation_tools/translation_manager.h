#ifndef TRANSLATION_MANAGER_H
#define TRANSLATION_MANAGER_H

#include <QGuiApplication>
#include <QObject>
#include <QTranslator>
#include <QQmlEngine>

class TranslationManager : public QObject
{
    Q_OBJECT
public:
    explicit TranslationManager(QQmlEngine *engine, QObject *parent = nullptr);

    Q_INVOKABLE void changeLanguage(const QString &languageCode);

private:
    QTranslator m_translator;
    QQmlEngine *m_engine;
};

#endif // TRANSLATION_MANAGER_H
