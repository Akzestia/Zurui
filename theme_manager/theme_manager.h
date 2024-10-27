#ifndef THEME_MANAGER_H
#define THEME_MANAGER_H

#include <QObject>
#include <QQmlEngine>

#include "qobject.h"
#include "qobjectdefs.h"
#include "qqmlengine.h"

/*

    ThemeManager - main class used for managing application themes.
    This class is responsible for loading, applying, and providing
    access to different themes. Note! This class must only manage
    themes and their properties; theme rendering should be handled
    separately by the UI components.

    Only 1 instance of ThemeManager should be created, which must be
    reused throughout the application's lifetime.

*/

class ThemeManager : public QObject {
    Q_OBJECT
  public:
    explicit ThemeManager(QQmlEngine* engine, QObject* parent = nullptr);
    void update();
    ~ThemeManager();

  private:
    QQmlEngine* m_engine;
};

#endif  // THEME_MANAGER_H
