#include "live_update_xt.h"

#include <QDebug>

#include "qlogging.h"
#include "qobject.h"

LiveUpdateXt::LiveUpdateXt() noexcept {
    m_worker.moveToThread(&m_worker_thread);
    QObject::connect(&m_worker, &LiveXtWorker::fileChanged, this,
                     &LiveUpdateXt::file_changed);
}

LiveUpdateXt::~LiveUpdateXt() noexcept {
    m_worker.stop();
    m_worker_thread.quit();
    m_worker_thread.wait();
}

bool LiveUpdateXt::addPath(const QString& path) {
    qDebug() << "Adding path" << path;
    return m_worker.addPath(path.toStdString().c_str());
}

void LiveUpdateXt::file_changed(const std::string& path) {
    qDebug() << "File Changed: " << path;
    emit request_theme_update(QString::fromStdString(path));
}

void LiveUpdateXt::monitor() {
    m_worker.start();
}
