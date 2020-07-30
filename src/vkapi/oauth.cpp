#include "vkapi/request.h"
#include "vkapi/config.h"
#include "vkapi/error.h"
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <utility>
#include <json/json.h>

std::string vkapi::request::oauth(std::string login, std::string password, int app_id, std::string app_secret) {
    std::map<std::string, std::string> params;
    params["client_id"] = std::to_string(app_id);
    params["grant_type"] = "password";
    params["client_secret"] = std::move(app_secret);
    params["username"] = std::move(login);
    params["password"] = std::move(password);
    std::string request_url = vkapi::config::vk_oauth_url +
                              map_to_url_params(params);
    curlpp::Easy request;
    request.setOpt<curlpp::options::Url>(request_url);
    std::stringstream os;
    curlpp::options::WriteStream ws(&os);
    request.setOpt(ws);
    request.perform();
    Json::Value root;
    os >> root;
    std::cout << root << std::endl;
    if (root.isMember("error"))
        throw vkapi::error::AuthError(root["error"].asString(), root);
    return root["access_token"].asString();
}