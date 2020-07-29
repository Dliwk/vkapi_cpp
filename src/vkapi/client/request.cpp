#include <utility>

#include "vkapi/client.h"


vkapi::Request::Request(VkApi vk) {
    this->token = vk.token();
}

void vkapi::Request::setmethod(std::string methodname) {
    this->method = std::move(methodname);
}

void vkapi::Request::setopt(const std::string &key, int value) {
    this->options[key] = std::to_string(value);
}

void vkapi::Request::setopt(const std::string &key, std::string value) {
    this->options[key] = std::move(value);
}

Json::Value vkapi::Request::send() {
    this->options["access_token"] = this->token;
    this->options["v"] = this->api_version;
    return vkapi::request::api_request(this->method, this->options);
}