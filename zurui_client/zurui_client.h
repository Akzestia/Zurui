

#include <cstdint>
class Zurui_Client {
  private:

#pragma region Connection_related_fields
    const char *client_ip_addr = nullptr;
    const char *client_vpn_addr = nullptr;
    const char *server_addr = nullptr;
    uint16_t server_port;
#pragma endregion

  public:
    Zurui_Client();
};
