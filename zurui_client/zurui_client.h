
#ifndef ZURUI_CLIENT_H
#define ZURUI_CLIENT_H
#include <cstdint>

/*

    Zurui Client - main classs used by client side for communicating with the
    server. Note! This class must only send/receive data, all data processing
    like routing, serialization/ deserialization must be handled separately.

    Only 1 instance of client must be created, which must be reused during the
    application lifetime.
*/

class Zurui_Client {
  private:
#pragma region Connection_related_fields
    const char* client_ip_addr = nullptr;
    const char* client_vpn_addr = nullptr;
    const char* server_addr = nullptr;
    uint16_t server_port;
#pragma endregion

  public:
    Zurui_Client() = delete;

    ~Zurui_Client() = default;

    Zurui_Client(const Zurui_Client&) = delete;

    Zurui_Client& operator=(const Zurui_Client&) = delete;

    Zurui_Client(Zurui_Client&&) = delete;

    Zurui_Client& operator=(Zurui_Client&&) = delete;
};

#endif  // ZURUI_CLIENT_H
