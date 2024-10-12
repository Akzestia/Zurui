#include "../MsQuic/include/msquic.h"
#include <cstdint>

/*

    Zurui Client - main classs used by client side for communicating with the server.
    Note! This class must only send/receive data, all data processing like routing,
    serialization/ deserialization must be handled separately.

    Only 1 instance of client must be created, which must be reused during the application lifetime.
*/


class Zurui_Client {
  private:
#pragma region Connection_related_fields
    //Client configurations
    const char *client_ip_addr = nullptr;
    const char *client_vpn_addr = nullptr;
    const char *server_addr = nullptr;
    uint16_t server_port;
#pragma endregion

#pragma region MsQuic
    //Base MsQuic structures
    const QUIC_API_TABLE* MsQuic = nullptr;
    QUIC_CREDENTIAL_CONFIG CredConfig;

    //HQUICs for communicating with the server
    HQUIC Connection = nullptr;
    HQUIC Listener = nullptr;
    HQUIC Registration = nullptr;
    HQUIC Configuration = nullptr;

    //Alpn and config
    const QUIC_REGISTRATION_CONFIG RegConfig = {"Client", QUIC_EXECUTION_PROFILE_TYPE_REAL_TIME};
    const QUIC_BUFFER Alpn;

    //Resumption
    uint8_t *ResumptionTicket = nullptr;
    uint16_t ResumptionTicketLength;
#pragma endregion


  public:
    Zurui_Client();
};
