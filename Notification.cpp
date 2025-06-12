#include "Notification.h"
#include <iostream>

void Notification::send(const std::string& message) {
    std::cout << "[Notification] " << message << std::endl;
}

void Notification::sendBulk(const std::vector<std::string>& messages) {
    for (const auto& msg : messages)
        send(msg);
}
