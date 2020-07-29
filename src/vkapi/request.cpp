#include "vkapi/request.h"
#include "vkapi/config.h"
#include "vkapi/error.h"
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/cURLpp.hpp>

std::string map_to_url_params(const std::map<std::string, std::string>& params) {
    std::string result;
    for (auto iter = params.begin(); iter != params.end(); ++iter) {
        result += curlpp::escape(iter->first) + "=" + curlpp::escape(iter->second);
        if (iter != --params.end()) {
            result += "&";
        }
    }
    return result;
}

Json::Value vkapi::request::api_request(const std::string& method, const std::map<std::string, std::string>& params) {
    curlpp::Easy request;
    request.setOpt<curlpp::options::Url>(
            vkapi::config::vk_api_method_url + method + "?" + map_to_url_params(params));
    std::stringstream os;
    curlpp::options::WriteStream ws(&os);
    request.setOpt(ws);
    request.perform();
    Json::Value root;
    os >> root;
    std::cout << root;
    if (root.isMember("error")) {
        throw vkapi::error::ApiError(root["error"]["error_code"].asInt(),
                                     root["error"]["error_msg"].asString());
    }
    return root;
}