#include "systray.h"

#include <QWindow>

#include "qicon.h"
#include "qkeysequence.h"
#include "qobject.h"

SysTray::SysTray(QGuiApplication* app) noexcept {
    trayIcon.setIcon(QIcon("/home/azure/Downloads/Untitled-modified.png"));
    trayIcon.setToolTip("ずるい");

    QString restoreAction_text = QObject::tr("Restore");
    QString quitAction_text = QObject::tr("Quit");

#ifdef ZURUI_DEBUG
    qDebug() << "RT: [" << restoreAction_text << "]";
    qDebug() << "QT: [" << quitAction_text << "]";
#endif

    restoreAction = new QAction(restoreAction_text, &trayMenu);
    quitAction = new QAction(quitAction_text, &trayMenu);

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
