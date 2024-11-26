#include "preloading_manager.h"

#include "preloading_worker.h"
#include "qalgorithms.h"
#include "qdir.h"
#include "qhashfunctions.h"
#include "qlogging.h"
#include "qmap.h"
#include "qpointer.h"
#include "qqmlcomponent.h"

PreloadingManager::PreloadingManager(QQmlEngine* engine, QObject* parent)
    : QObject(parent), m_engine(engine) {
    m_worker = new PreloadingWorker(engine);
    m_worker->moveToThread(&m_worker_thread);

    connect(&m_worker_thread, &QThread::finished, m_worker,
            &QObject::deleteLater);

    m_object_storage = new QMap<QString, QPointer<QQmlComponent>>();

    connect(this, &PreloadingManager::preloadComponentSignal, m_worker,
            &PreloadingWorker::preload);
    connect(m_worker, &PreloadingWorker::componentPreloaded, this,
            &PreloadingManager::componentPreloaded);

    m_worker_thread.start();
}

PreloadingManager::~PreloadingManager() {
    m_worker_thread.quit();
    m_worker_thread.wait();

    if (m_object_storage) {
        m_object_storage->clear();
        delete m_object_storage;
    }
}

void PreloadingManager::preloadComponent(const QString& componentName,
                                         const QUrl& url) {
    emit preloadComponentSignal(componentName, url);
}

QQmlComponent* PreloadingManager::getComponent(const QString& name) {
    qDebug() << "Checking if component exists for name:" << name;

    qDebug() << "Current size of component storage:"
             << m_object_storage->size();

    auto it = m_object_storage->find(name);
    if (it != m_object_storage->end() && it->data()) {
        qDebug() << "Component found in storage for name:" << name;
        return it->data();
    } else
        qWarning() << "Failed to return requested QQmlComponent for name:"
                   << name;

    return nullptr;
}

void PreloadingManager::componentPreloaded(const QString& name,
                                           QPointer<QQmlComponent> component) {
    qDebug() << "Loaded " << name << " component";

    m_object_storage->insert(name, component);

    emit componentPreloadedSignal(name);
}

void PreloadingManager::discardComponent(const QString& name) {
}
