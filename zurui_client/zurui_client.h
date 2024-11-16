
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
    // Client configurations
    const char* client_ip_addr = nullptr;
    const char* client_vpn_addr = nullptr;
    const char* server_addr = nullptr;
    uint16_t server_port;
#pragma endregion

  public:
    /*!
     * \brief Default constructor.
     */
    Zurui_Client();

    /*!
     * \brief Destructor.
     */
    ~Zurui_Client() = default;

    /*!
     * \brief Copy constructor (deleted).
     */
    Zurui_Client(const Zurui_Client&) = delete;

    /*!
     * \brief Copy assignment operator (deleted).
     */
    Zurui_Client& operator=(const Zurui_Client&) = delete;

    /*!
     * \brief Move constructor (deleted).
     */
    Zurui_Client(Zurui_Client&&) = delete;

    /*!
     * \brief Move assignment operator (deleted).
     */
    Zurui_Client& operator=(Zurui_Client&&) = delete;
};

#endif  // ZURUI_CLIENT_H
