#ifndef THEME_MANAGER_H
#define THEME_MANAGER_H

#include <QObject>
#include <QQmlEngine>

#include "qtmetamacros.h"

class ThemeManager : public QObject {
    Q_OBJECT
    Q_PROPERTY(
        QVariantMap availableThemes READ availableThemes NOTIFY themesChanged)
    Q_PROPERTY(
        QObject* currentTheme READ currentTheme NOTIFY currentThemeChanged)
  public:
    [[nodiscard]] explicit ThemeManager(QQmlEngine* engine,
                                        QObject* parent = nullptr) noexcept;

    ~ThemeManager() noexcept;

    QVariantMap availableThemes() const;
    QObject* currentTheme() const;

    // void function call update()
    // used only to dump to refresh qml cache and set new theme
    Q_INVOKABLE void update();

  signals:
    void themesChanged();

    void currentThemeChanged();
  public slots:

  private:
    QQmlEngine* m_engine = nullptr;
    QPointer<QObject> m_current_theme;
    QVariantMap m_themes;
};

#endif  // THEME_MANAGER_H
