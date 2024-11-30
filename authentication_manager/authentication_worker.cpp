#include "authentication_worker.h"

AuthenticationWorker::AuthenticationWorker(ZuruiClient* client) noexcept
    : m_client(client) {
}

AuthenticationWorker::~AuthenticationWorker(){
    if(m_client)
        delete m_client;
}
