#include <utility>

#include "vkapi/client.h"

std::string vkapi::VkApi::token() {
    return this->access_token;
}

vkapi::VkApi::VkApi(std::string token) {
    this->access_token = std::move(token);
}

vkapi::VkApi::VkApi() = default;

void vkapi::VkApi::auth(const std::string &login, const std::string &password, int app_id, std::string app_secret) {
    this->access_token = vkapi::request::oauth(login, password, app_id, std::move(app_secret));
}
