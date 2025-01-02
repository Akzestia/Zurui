#ifndef LIVE_XT_H
#define LIVE_XT_H

#include <QObject>
#include <QThread>
#include <string>

#include "live_xt_worker.h"

class LiveUpdateXt : public QObject {
    Q_OBJECT
    QThread m_worker_thread;

  public:
    [[nodiscard]] LiveUpdateXt() noexcept;
    bool addPath(const QString& path);
    void monitor();
    ~LiveUpdateXt() noexcept;
  signals:
    void request_theme_update(const QString& path);

  private slots:
    void file_changed(const std::string& path);

  private:
    LiveXtWorker m_worker;
};
#endif  // LIVE_XT_H
