#include <iostream>
#include <vkapi/vkapi.h>

int main() {
    std::cout << "Hello, world!" << std::endl;
    vkapi::VkApi vk("VK ACCESS TOKEN");
    vkapi::Request request(vk);
    request.setmethod("users.get");
    request.setopt("user_id", 1);
    std::cout << request.send() << std::endl;
}