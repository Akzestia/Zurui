#include "authentication_manager.h"

#include "authentication_worker.h"
#include "qobject.h"
#include "qqmlengine.h"
#include "qthread.h"

AuthenticationManager::AuthenticationManager(QQmlEngine* engine,
                                             ZuruiClient* client,
                                             QObject* parent) noexcept
    : m_engine(engine), QObject(parent) {
    m_worker = new AuthenticationWorker(client);

    QObject::connect(&m_workerThread, &QThread::finished, m_worker,
                     &QObject::deleteLater);
    QObject::connect(this, &AuthenticationManager::signInStartedSignal,
                     m_worker, &AuthenticationWorker::signIn);
    QObject::connect(this, &AuthenticationManager::signUpStartedSignal,
                     m_worker, &AuthenticationWorker::signUp);
}

AuthenticationManager::~AuthenticationManager() {
    m_workerThread.quit();
    m_workerThread.wait();
}
