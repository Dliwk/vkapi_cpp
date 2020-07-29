#pragma once

#include <string>
#include <map>
#include "vkapi/request.h"

namespace vkapi {
    class VkApi {
    public:
        explicit VkApi(std::string token);

        VkApi(std::string login, std::string password);

        void auth(std::string login, std::string password);

        std::string token();

    protected:
        std::string access_token;
    };

    class Request {
    public:
        explicit Request(VkApi vk);

        void setopt(const std::string& key, int value);
        void setopt(const std::string& key, std::string value);

        void setmethod(std::string methodname);

        Json::Value send();

    private:
        std::map<std::string, std::string> options;
        std::string method;
        std::string token;
        std::string api_version = "5.120";
    };
}