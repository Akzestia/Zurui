

#include "qcontainerfwd.h"
#include "qobject.h"
#include "qtmetamacros.h"
class ClientWorker : public QObject {
  public:
    [[nodiscard]] ClientWorker() noexcept;
    ~ClientWorker() noexcept;
  signals:
    void sign_in_started();
    void sign_in_finished();

    void sign_up_started();
    void sign_up_finished();

    void sign_up_confirm_started();
    void sign_up_confirm_finished();
  public slots:
    void sign_in(const QString& u_name, const QString& u_password);
    void sign_up(const QString& u_name, const QString& u_email,
                 const QString& u_password);
    void sign_up_confirm(const QString& u_confirm_code);

  private:
};
