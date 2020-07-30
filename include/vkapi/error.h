#pragma once

#include <exception>
#include <string>
#include <json/json.h>

namespace vkapi::error {
    class Error : public std::exception {
    public:
        explicit Error(const std::string &what);

        [[nodiscard]] const char *what() const noexcept override;

    protected:
        std::string what_str;
    };

    class ApiError : public Error {
    public:
        ApiError(int error_code, const std::string &msg);
    };

    class AuthError : public Error {
    public:
        explicit AuthError(const std::string &msg, const Json::Value &args);

        Json::Value args;
    };

}