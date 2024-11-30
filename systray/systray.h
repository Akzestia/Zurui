#ifndef SYSTRAY_H
#define SYSTRAY_H

#include <QAction>
#include <QMenu>
#include <QSystemTrayIcon>

#include "qguiapplication.h"

class SysTray {
  public:
    [[nodiscard]] SysTray(QGuiApplication* app) noexcept;
    void show();

  private:
    QSystemTrayIcon trayIcon;
    QMenu trayMenu;
    QAction* restoreAction = nullptr;
    QAction* quitAction = nullptr;
};
#endif //SYSTRAY_H
