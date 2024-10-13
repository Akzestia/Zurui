#include "zurui_client.h"

#include <cstdlib>
#include <cstring>

/*
    Before building u need to set the following variables:

    1.ZURUI_ALPN - Alpn
        Type: const char *
        Default value: "zurui"

    2.ZURUI_SERVER_ADDR - Server addres
        Type: const char *
        Default value: "127.0.0.1"

    3.ZURUI_SERVER_PORT - Server port
        Type: uint16_t
        Default value: 6121
*/

Zurui_Client::Zurui_Client()
    : Alpn{static_cast<uint32_t>(strlen(std::getenv("ZURUI_ALPN")
                                            ? std::getenv("ZURUI_ALPN")
                                            : "zurui")),
           reinterpret_cast<uint8_t*>(const_cast<char*>(
               std::getenv("ZURUI_ALPN") ? std::getenv("ZURUI_ALPN")
                                         : "zurui"))},
      server_addr{std::getenv("ZURUI_SERVER_ADDR")
                      ? std::getenv("ZURUI_SERVER_ADDR")
                      : "127.0.0.1"},
      server_port{static_cast<uint16_t>(
          std::getenv("ZURUI_SERVER_PORT")
              ? std::strtol(std::getenv("ZURUI_SERVER_PORT"), nullptr, 10)
              : 6121)} {
#ifdef ZURUI_DEBUG
    printf("ALPN Length: %u\n", Alpn.Length);
    printf("ALPN Value: %s\n", Alpn.Buffer);
    printf("Server Address: %s\n", server_addr);
    printf("Server Port: %u\n", server_port);
#endif
}
