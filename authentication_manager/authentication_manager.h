
#ifndef AUTH_MANAGER_H
#define AUTH_MANAGER_H
#include <QThread>
#include <cstdint>

#include "authentication_worker.h"
#include "qobject.h"
#include "qqmlengine.h"
#include "qtmetamacros.h"

enum AuthErrors : uint8_t {
    SUCCESS = 0x00,
    INCORRECT_USER_DATA = 0x01,
    CONNECTION_FAILED = 0x02,
};

class AuthenticationManager : public QObject {
    Q_OBJECT
  public:
    [[nodiscard]] explicit AuthenticationManager(
        QQmlEngine* engine, ZuruiClient* client,
        QObject* parent = nullptr) noexcept;
    ~AuthenticationManager();

  signals:
    void signInStartedSignal();
    void signInFinishedSignal();
    void signUpStartedSignal();
    void signUpFinishedSignal();
  public slots:
    void signInFinished();
    void signUpFinished();

  private:
    QQmlEngine* m_engine = nullptr;
    QThread m_workerThread;
    AuthenticationWorker* m_worker = nullptr;
};
#endif  // AUTH_MANAGER_H
