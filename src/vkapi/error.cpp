#include "vkapi/error.h"

vkapi::error::Error::Error(const std::string &what) {
    this->what_str = what;
}

const char *vkapi::error::Error::what() const noexcept {
    return this->what_str.c_str();
}

vkapi::error::ApiError::ApiError(int error_code, const std::string &msg) :
        Error("[" + std::to_string(error_code) + "] " + msg) {
}
