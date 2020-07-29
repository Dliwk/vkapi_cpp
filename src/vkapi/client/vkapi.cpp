#include <utility>

#include "vkapi/client.h"

std::string vkapi::VkApi::token() {
    return this->access_token;
}

vkapi::VkApi::VkApi(std::string token) {
    this->access_token = std::move(token);
}