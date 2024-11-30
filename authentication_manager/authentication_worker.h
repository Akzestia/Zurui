#ifndef AUTH_WORKER_H
#define AUTH_WORKER_H

#include "../zurui_client/zurui_client.h"
#include "qobject.h"
#include "qqmlengine.h"
#include "qtmetamacros.h"

class AuthenticationWorker : public QObject {
    Q_OBJECT
  public:
    [[nodiscard]] AuthenticationWorker(ZuruiClient* client) noexcept;
    ~AuthenticationWorker();

  signals:
    void signUpFinished();
    void signInFinished();

  public slots:
    void signUp(QString u_name, QString u_email, QString u_password,
                QString r_password);
    void signIn(QString u_name, QString u_password);

  private:
    ZuruiClient* m_client = nullptr;
};
#endif  // AUTH_WORKER_H
