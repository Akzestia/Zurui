#include "systray.h"

#include <QWindow>

#include "qicon.h"

SysTray::SysTray(QGuiApplication* app) {
    trayIcon.setIcon(QIcon("/home/azure/Downloads/Untitled-modified.png"));
    trayIcon.setToolTip("ずるい");

    restoreAction = new QAction("Restore", &trayMenu);
    quitAction = new QAction("Quit", &trayMenu);

    trayMenu.addAction(restoreAction);
    trayMenu.addAction(quitAction);

    trayIcon.setContextMenu(&trayMenu);

    QObject::connect(restoreAction, &QAction::triggered, [&]() {
        QWindow* w = QGuiApplication::allWindows()[0];
        if (w && !w->isVisible())
            w->show();
    });

    QObject::connect(quitAction, &QAction::triggered, &*app,
                     &QCoreApplication::quit);

    trayIcon.show();
}
