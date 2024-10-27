#ifndef THEME_MANAGER_H
#define THEME_MANAGER_H

#include <QObject>
#include <QQmlEngine>

#include "qobject.h"
#include "qobjectdefs.h"
#include "qqmlengine.h"

class ThemeManager : public QObject {
    Q_OBJECT
  public:
    explicit ThemeManager(QQmlEngine* engine, QObject* parent = nullptr);
    void update();
    ~ThemeManager();

  private:
    QQmlEngine* m_engine;
};

#endif //THEME_MANAGER_H
