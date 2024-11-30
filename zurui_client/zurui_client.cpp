#include "zurui_client.h"

#include <net/if.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <boost/asio.hpp>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

void ZuruiClient::setNetworkInterface() {
    std::vector<NetworkInterface> interfaces = getMTU();

    if (!interfaces.empty()) {
        for (const auto& iface : interfaces) {
            if (m_settings->preferred_network == WIFI
                && iface.name.find("wlan") != std::string::npos) {
                m_settings->network_interface = iface;
                break;
            } else if (m_settings->preferred_network == ETHERNET
                       && iface.name.find("eth") != std::string::npos) {
                m_settings->network_interface = iface;
                break;
            }
        }
        if (m_settings->network_interface.name.empty()) {
            m_settings->network_interface = interfaces[0];
        }
    } else {
        m_settings->network_interface = {-1, "undefined"};
    }

#ifdef ZURUIDEBUG
    std::cout << "Selected Network Interface: "
              << m_settings->network_interface.name << std::endl;
#endif
}

ZuruiClient::ZuruiClient() noexcept {
    m_settings = new ClientSettings;

    m_settings->enable_multipath = false;
    m_settings->preferred_network = WIFI;  // ETHERNET
    m_settings->ipv = v4;
    m_settings->max_idle_timeout = 3000;

    setNetworkInterface();
}

std::vector<std::string> ZuruiClient::getNetworkInterfaces() const {
    std::vector<std::string> interfaces;

    struct ifconf ifc;
    struct ifreq ifr[50];
    int sock = socket(AF_INET, SOCK_DGRAM, 0);

    if (sock < 0) {
        perror("socket");
        return interfaces;
    }

    ifc.ifc_len = sizeof(ifr);
    ifc.ifc_ifcu.ifcu_req = ifr;

    if (ioctl(sock, SIOCGIFCONF, &ifc) < 0) {
        perror("ioctl");
        close(sock);
        return interfaces;
    }

    int interfaces_count = ifc.ifc_len / sizeof(struct ifreq);
    for (int i = 0; i < interfaces_count; i++) {
        interfaces.push_back(ifr[i].ifr_name);
    }

    close(sock);
    return interfaces;
}

std::vector<NetworkInterface> ZuruiClient::getMTU() const {
    std::vector<NetworkInterface> result;

    if (!m_settings)
        return result;

    std::vector<std::string> interfaces = getNetworkInterfaces();

    for (const auto& interface : interfaces) {
        int sock = socket(AF_INET, SOCK_DGRAM, 0);
        if (sock < 0) {
            perror("socket");
            continue;
        }

        struct ifreq ifr;
        std::strncpy(ifr.ifr_name, interface.c_str(), IFNAMSIZ - 1);

        if (ioctl(sock, SIOCGIFMTU, &ifr) < 0) {
            perror("ioctl");
            close(sock);
            continue;
        }

        close(sock);
        result.push_back({ifr.ifr_mtu, interface});
    }

    return result;
}

ZuruiClient::~ZuruiClient() {
    if (m_settings) {
        delete m_settings;
        m_settings = nullptr;
    }
    for (auto* mapping : m_mappings) {
        delete mapping;
        mapping = nullptr;
    }
}
