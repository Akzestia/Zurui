#ifndef VPN_MANAGER_H
#define VPN_MANAGER_H
#include <iostream>

/*!
 * \enum HandShakeProviders
 * \brief Enum representing available handshake providers for VPN connection.
 *
 * Providers include unique codes for each location, allowing the VPN Manager
 * to identify and connect to the relevant servers for establishing connections.
 */
enum HandShakeProviders {
    UA_PROVIDER = 0x01,   ///< Ukraine provider for handshake
    JAP_PROVIDER = 0x02,  ///< Japan provider for handshake
    PL_PROVIDER = 0x03,   ///< Poland provider for handshake
    TW_PROVIDER = 0x04,   ///< Taiwan provider for handshake

    UNKNOWN_PROVIDER = 0x0  ///< Unknown provider, used as a default or fallback
};

/*!
 * \class VpnManager
 * \brief The VpnManager class handles VPN connection setup and management.
 *
 * This class provides an interface for connecting to a handshake provider to
 * establish a VPN session. It includes methods to initiate or terminate a
 * connection and interact with other clients.
 */
class VpnManager {
  public:
    /*!
     * \brief Default constructor.
     */
    VpnManager() = default;

    /*!
     * \brief Destructor.
     */
    ~VpnManager() = default;

    /*!
     * \brief Copy constructor (deleted).
     */
    VpnManager(const VpnManager&) = delete;

    /*!
     * \brief Copy assignment operator (deleted).
     */
    VpnManager& operator=(const VpnManager&) = delete;

    /*!
     * \brief Move constructor (deleted).
     */
    VpnManager(VpnManager&&) = delete;

    /*!
     * \brief Move assignment operator (deleted).
     */
    VpnManager& operator=(VpnManager&&) = delete;

    /*!
     * \brief Connects to a handshake provider.
     *
     * This function initiates a temporary connection to the specified handshake
     * provider to facilitate VPN session establishment. The provider to connect
     * to will be determined based on the application context or configuration.
     */
    void connectToHandshakeProvider();

    /*!
     * \brief Disconnects from the currently connected handshake provider.
     *
     * This function terminates the temporary connection to the handshake
     * provider, effectively ending the session with that provider.
     */
    void disconnectFromHandshakeProvider();

    /*!
     * \brief Requests a handshake with another client.
     *
     * This function sends a handshake request to another client, starting
     * the process of establishing a secure connection.
     */
    void requestHandShake();

    /*!
     * \brief Accepts a handshake request from another client.
     *
     * This function confirms a received handshake request, establishing a
     * connection.
     */
    void acceptHandShake();

    /*!
     * \brief Rejects a handshake request from another client.
     *
     * This function declines a received handshake request, blocking the
     * connection attempt.
     */
    void rejectHandShake();

  private:
    const char* zurui_ip_addr = nullptr;  ///< IP address of the current device,
                                          ///< used for connection setup.
};

#endif  // VPN_MANAGER_H
