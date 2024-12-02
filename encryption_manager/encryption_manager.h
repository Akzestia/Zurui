#ifndef ENCRYPTION_MANAGER_H
#define ENCRYPTION_MANAGER_H
#include <cstdint>
#include <string>

enum cypherError : uint8_t {
    SUCCESS = 0x00,
    CONTEXT_CREATION_FAILED = 0x01,
    CONTEXT_INIT_FAILED = 0x02,
    CONTEXT_UPDATE_FAILED = 0x03,
    CONEXT_FINALIZE_FAILED = 0x04,
};

struct cypherResult {
    cypherError err_code;
    uint8_t hash[64];

    [[nodiscard]] cypherResult(cypherError, std::string) noexcept;
};

class EncryptionManager {
  public:
    [[nodiscard]] EncryptionManager() noexcept;

    cypherResult* encryptUserData(const char* user_name,
                                  const char* user_password) const;
    cypherResult* encryptUserData(const char* user_name, const char* user_email,
                                  const char* user_password,
                                  const char* password_repeat) const;
};

#endif  // ENCRYPTION_MANAGER_H
