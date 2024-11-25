#include <QAction>
#include <QMenu>
#include <QSystemTrayIcon>

#include "qguiapplication.h"

class SysTray {
  public:
    [[nodiscard]] SysTray(QGuiApplication* app);
    void show();

  private:
    QSystemTrayIcon trayIcon;
    QMenu trayMenu;
    QAction* restoreAction = nullptr;
    QAction* quitAction = nullptr;
};
