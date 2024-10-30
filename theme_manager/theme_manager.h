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
    /*!
     * \brief Constructs the ThemeManager with a specified QQmlEngine.
     * \param engine A pointer to the QQmlEngine used in the application.
     * \param parent An optional parent QObject. Default is nullptr.
     *
     * This constructor initializes the ThemeManager with the provided
     * QQmlEngine and sets up the necessary resources for theme management.
     */
    explicit ThemeManager(QQmlEngine* engine, QObject* parent = nullptr);

    /*!
     * \brief Retrieves a map of available themes.
     *
     * This method returns a QVariantMap where the keys are theme names
     * and the values are the corresponding theme objects. It is intended
     * for use in QML to populate UI elements, such as dropdown menus.
     *
     * \return A QVariantMap of available themes.
     */
    QVariantMap availableThemes() const;

    /*!
     * \brief Updates the currently applied theme.
     *
     * This method reloads or re-applies the specified theme based on the
     * latest settings or preferences. It ensures that changes are reflected
     * in the user interface by updating the current theme object.
     *
     * \param theme_name The name of the theme to be applied.
     */
    Q_INVOKABLE void update(const QString& theme_name);

    /*!
     * \brief Loads available themes from the "themes" directory.
     *
     * This method scans the "themes" directory for subdirectories representing
     * themes. It clears any previously loaded themes and loads new theme
     * configurations, creating corresponding theme objects.
     */
    void loadThemes();

    /*!
     * \brief Creates a theme object from the specified QML file.
     * \param path The path to the QML theme file.
     *
     * This method loads a QML component from the specified file and
     * instantiates it as a QObject. If loading fails, it returns nullptr.
     *
     * \return A pointer to the created QObject representing the theme,
     *         or nullptr if loading fails.
     */
    QObject* createThemeObject(const QString& path);

    /*!
     * \brief Retrieves the currently applied theme.
     *
     * This method returns a pointer to the currently active theme object.
     *
     * \return A pointer to the current QObject representing the theme.
     */
    QObject* currentTheme() const { return m_current_theme; }

    /*!
     * \brief Destructor for ThemeManager.
     *
     * Cleans up resources associated with the ThemeManager, ensuring
     * that all loaded themes are properly deleted.
     */
    ~ThemeManager();

  signals:
    /*!
     * \brief Signal emitted when the available themes change.
     *
     * This signal should be emitted whenever themes are added, removed,
     * or updated, allowing connected QML components to respond accordingly.
     */
    void themesChanged();

    /*!
     * \brief Signal emitted when the current theme changes.
     *
     * This signal should be emitted whenever the current theme is updated,
     * notifying connected QML components of the change.
     */
    void currentThemeChanged();

  private:
    QQmlEngine* m_engine;  ///< Pointer to the application's QQmlEngine.
    QPointer<QObject> m_current_theme;  ///< The currently applied theme object.
    QVariantMap m_themes;               ///< The list of available themes.
};

#endif  // THEME_MANAGER_H
