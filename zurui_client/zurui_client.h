
#ifndef ZURUI_CLIENT_H
#define ZURUI_CLIENT_H
#include <openssl/evp.h>

#include <QObject>
#include <QThread>
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

#include "../../Zurui-WorkShop/client/client.h"
#include "client_worker.h"
#include "qcontainerfwd.h"
#include "qtmetamacros.h"

/*

    Zurui Client - main classs used by client side for communicating with the
    server. Note! This class must only send/receive data, all data processing
    like routing, serialization/ deserialization must be handled separately.

    Only 1 instance of client must be created, which must be reused during the
    application lifetime.
*/

enum NetworkTypes : uint8_t { WIFI = 0x00, ETHERNET = 0x01 };
enum IpvTypes : uint8_t { v4 = 0x00, v6 = 0x01 };

struct NAT_Mapping {
    uint8_t client_uuid[16];
    uint8_t ip_hash[64];
    uint16_t clent_mtu;
    bool trusted;
    uint8_t session_token[32];
};

struct NetworkInterface {
    int mtu;
    std::string name;
};

struct ClientSettings {
    uint8_t client_version[3];
    uint8_t alpn[16];

    NetworkInterface network_interface;
    NetworkTypes preferred_network;
    const char* client_address;
    IpvTypes ipv;

    uint16_t server_port;
    uint16_t listener_port;

    uint64_t client_uuid;
    uint64_t handshake_nonce;

    uint64_t handshake_time;
};

class ZuruiClient {
    Q_OBJECT
    QThread workerThread;

  public:
    [[nodiscard]] ZuruiClient() noexcept;

    ~ZuruiClient() noexcept;

    ZuruiClient(const ZuruiClient&) = delete;
    ZuruiClient& operator=(const ZuruiClient&) = delete;
    ZuruiClient(ZuruiClient&&) = delete;
    ZuruiClient& operator=(ZuruiClient&&) = delete;

    void setAlpn(const char* alpn);
    void setClientVersion(const char* version);

    Q_INVOKABLE void sign_in(const QString& u_name, const QString& u_password);
    Q_INVOKABLE void sign_up(const QString& u_name, const QString& u_email,
                             const QString& u_password);
    Q_INVOKABLE void sign_up_confirm(const QString& u_confirm_code);

  private:
    ずるい_クライアント m_zclp_client;
    ClientSettings* m_settings;
    std::vector<NAT_Mapping*> m_mappings;

    std::vector<NetworkInterface> getMTU() const;
    std::vector<std::string> getNetworkInterfaces() const;
    void setNetworkInterface();

    ClientWorker m_worker;
};

#endif  // ZURUI_CLIENT_H
