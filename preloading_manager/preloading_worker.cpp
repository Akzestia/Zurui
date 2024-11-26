#include "preloading_worker.h"

#include <QDir>
#include <QQmlComponent>

#include "qlogging.h"
#include "qpointer.h"
#include "qqmlcomponent.h"
#include "qurl.h"

PreloadingWorker::PreloadingWorker(QQmlEngine* engine, QObject* parent)
    : QObject(parent), m_engine(engine) {
}

void PreloadingWorker::preload(const QString& componentName, const QUrl& url) {
    qDebug() << "Url: " << url.toString();
    qDebug() << "Name: " << url.toString();

    QPointer<QQmlComponent> component =
        new QQmlComponent(m_engine, url, QQmlComponent::Asynchronous);

    while (component->isLoading()) {
    }

    if (component->isReady()) {
        emit componentPreloaded(componentName, component);
        qDebug() << "Success";
    }
    if (component->isError())
        qDebug() << "Failure";
}
