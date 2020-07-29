#pragma once
#include <map>
#include <string>
#include <json/json.h>

namespace vkapi::request {
    Json::Value api_request(const std::string& method, const std::map<std::string, std::string>& params);
}