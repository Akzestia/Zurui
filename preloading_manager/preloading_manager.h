#ifndef PreloadingManager_H
#define PreloadingManager_H

#include <QMap>
#include <QMutex>
#include <QObject>
#include <QQmlComponent>
#include <QQmlEngine>
#include <QThread>

#include "preloading_worker.h"
#include "qdir.h"
#include "qobject.h"
#include "qpointer.h"
#include "qqmlcomponent.h"
#include "qqmlengine.h"
#include "qthread.h"
#include "qtmetamacros.h"
#include "qurl.h"

class PreloadingManager : public QObject {
    Q_OBJECT
  public:
    [[nodiscard]] explicit PreloadingManager(
        QQmlEngine* engine, QObject* parent = nullptr) noexcept;
    ~PreloadingManager();

    Q_INVOKABLE void preloadComponent(const QString& name, const QUrl& url);
    Q_INVOKABLE void discardComponent(const QString& name);
    Q_INVOKABLE QQmlComponent* getComponent(const QString& name);
  signals:
    void preloadComponentSignal(const QString& name, const QUrl& url);
    void discardComponentSignal(const QString& name);
    void componentPreloadedSignal(const QString& name);

  private:
    QThread m_worker_thread;
    QQmlEngine* m_engine = nullptr;
    PreloadingWorker* m_worker = nullptr;
    QMap<QString, QPointer<QQmlComponent>>* m_object_storage = nullptr;
  public slots:
    void componentPreloaded(const QString& componentName,
                            QPointer<QQmlComponent> component);
};

#endif
