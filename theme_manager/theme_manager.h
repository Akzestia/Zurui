#ifndef THEME_MANAGER_H
#define THEME_MANAGER_H

#include <QObject>
#include <QQmlEngine>

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
  public:
    /*!
     * \brief Constructs the ThemeManager with a specified QQmlEngine.
     * \param engine A pointer to the QQmlEngine used in the application.
     * \param parent An optional parent QObject.
     */
    explicit ThemeManager(QQmlEngine* engine, QObject* parent = nullptr);

    /*!
     * \brief Updates the currently applied theme.
     *
     * Reloads or re-applies the theme based on the latest settings or
     * preferences. This method ensures that changes are reflected in
     * the user interface.
     */
    void update();

    /*!
     * \brief Destructor for ThemeManager.
     *
     * Cleans up resources associated with the ThemeManager, ensuring
     * the theme manager instance is properly deleted.
     */
    ~ThemeManager();

  private:
    QQmlEngine* m_engine =
        nullptr;  ///< Pointer to the application's QQmlEngine.
    QObject* m_current_theme =
        nullptr;  ///< The currently applied theme object.
};

#endif  // THEME_MANAGER_H
