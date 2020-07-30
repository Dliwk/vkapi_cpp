#pragma once
#include <map>
#include <string>
#include <json/json.h>

namespace vkapi::request {
    std::string map_to_url_params(const std::map<std::string, std::string>& params);
    Json::Value api_request(const std::string& method, const std::map<std::string, std::string>& params);
    std::string oauth(std::string login, std::string password, int app_id, std::string app_secret);
}