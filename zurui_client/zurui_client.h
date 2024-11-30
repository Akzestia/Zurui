
#ifndef ZURUI_CLIENT_H
#define ZURUI_CLIENT_H
#include <openssl/evp.h>

#include <cstdint>
#include <string>
#include <vector>

/*

    Zurui Client - main classs used by client side for communicating with the
    server. Note! This class must only send/receive data, all data processing
    like routing, serialization/ deserialization must be handled separately.

    Only 1 instance of client must be created, which must be reused during the
    application lifetime.
*/

enum NetworkTpes : uint8_t { WIFI = 0x00, ETHERNET = 0x01 };
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
    NetworkInterface network_interface;
    const char* client_address;

    uint16_t server_port;
    uint16_t listener_port;

    uint8_t alpn[16];
    uint64_t blockchain_signature[64];
    uint64_t public_key[64];

    uint8_t client_uuid[16];
    uint64_t encryption_key[64];
    uint64_t handshake_nonce[12];

    uint32_t max_idle_timeout;

    bool enable_multipath;

    IpvTypes ipv;
    NetworkTpes preferred_network;

    uint64_t initial_rtt;
    uint64_t handshake_time;
};

class ZuruiClient {
  private:
    ClientSettings* m_settings;
    std::vector<NAT_Mapping*> m_mappings;

    std::vector<NetworkInterface> getMTU() const;
    std::vector<std::string> getNetworkInterfaces() const;
    void setNetworkInterface();

  public:
    [[nodiscard]] ZuruiClient() noexcept;

    ~ZuruiClient();

    ZuruiClient(const ZuruiClient&) = delete;

    ZuruiClient& operator=(const ZuruiClient&) = delete;

    ZuruiClient(ZuruiClient&&) = delete;

    ZuruiClient& operator=(ZuruiClient&&) = delete;
};

#endif  // ZURUI_CLIENT_H
