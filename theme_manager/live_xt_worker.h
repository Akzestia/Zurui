#ifndef LIVE_XT_WORKER
#define LIVE_XT_WORKER
#include <QObject>
#include <filesystem>
#include <string>
#include <thread>
#include <vector>

#include "qtmetamacros.h"

class LiveXtWorker : public QObject {
    Q_OBJECT

  public:
    [[nodiscard]] LiveXtWorker() noexcept;
    ~LiveXtWorker() noexcept;

    void start();
    void stop();

    bool addPath(const std::string& path);
  signals:
    void fileChanged(const std::string& path);

  private:
    std::vector<std::string> paths;
    std::vector<std::filesystem::file_time_type> last_modified;
    void monitor();
    std::thread m_thread;
    bool m_running = true;
};
#endif  // LIVE_XT_WORKER
