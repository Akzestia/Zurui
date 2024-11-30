#ifndef THEME_MANAGER_H
#define THEME_MANAGER_H

#include <QObject>
#include <QPointer>
#include <QQmlEngine>
#include <QVariantMap>
#include <map>

/*!
 * \class ThemeManager
 * \brief Manages application themes.
 *
 * The ThemeManager class is responsible for loading, applying, and
 * providing access to various application themes. It does not handle
 * theme rendering, which should be managed by UI components.
 *
 * Only one instance of ThemeManager should be created and reused
 * throughout the application's lifetime.
 */
class ThemeManager : public QObject {
    Q_OBJECT
    Q_PROPERTY(
        QVariantMap availableThemes READ availableThemes NOTIFY themesChanged)
    Q_PROPERTY(
        QObject* currentTheme READ currentTheme NOTIFY currentThemeChanged)

  public:
    [[nodiscard]] explicit ThemeManager(QQmlEngine* engine,
                                        QObject* parent = nullptr) noexcept;

    QVariantMap availableThemes() const;

    Q_INVOKABLE void update(const QString& theme_name);

    void loadThemes();

    QObject* createThemeObject(const QString& path);

    QObject* currentTheme() const { return m_current_theme; }

    ~ThemeManager();

  signals:
    void themesChanged();

    void currentThemeChanged();

  private:
    QQmlEngine* m_engine;
    QPointer<QObject> m_current_theme;
    QVariantMap m_themes;
};

#endif  // THEME_MANAGER_H
