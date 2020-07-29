#pragma once

#include <exception>
#include <string>

namespace vkapi::error {
    class Error : public std::exception {
    public:
        explicit Error(const std::string& what);

        [[nodiscard]] const char *what() const noexcept override;

    protected:
        std::string what_str;
    };

    class ApiError : public Error {
    public:
        ApiError(int error_code, const std::string &msg);
    };

}