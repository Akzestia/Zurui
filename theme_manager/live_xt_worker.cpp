#include "live_xt_worker.h"

#include <QDebug>
#include <cstdio>
#include <filesystem>
#include <string>

#include "qlogging.h"

LiveXtWorker::LiveXtWorker() noexcept {

};

LiveXtWorker::~LiveXtWorker() noexcept {
    if (m_running)
        m_running = false;
    if (m_thread.joinable())
        m_thread.join();
};

void LiveXtWorker::start() {
    last_modified.resize(paths.size());

    for (size_t i = 0; i < paths.size(); ++i) {
        qDebug() << "Entry " << paths[i].c_str();
        last_modified[i] = std::filesystem::last_write_time(paths[i]);
    }

    m_thread = std::thread(&LiveXtWorker::monitor, this);
};

void LiveXtWorker::stop() {
    m_running = false;
    if (m_thread.joinable())
        m_thread.join();
};

void LiveXtWorker::monitor() {
    while (m_running) {
        for (size_t i = 0; i < paths.size(); ++i) {
            auto current_modified = std::filesystem::last_write_time(paths[i]);
            if (current_modified != last_modified[i]) {
                last_modified[i] = current_modified;
                emit fileChanged(paths[i]);
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

bool LiveXtWorker::addPath(const std::string& path) {
    if (!std::filesystem::exists(path))
        return false;
    paths.push_back(path);
    return true;
}
