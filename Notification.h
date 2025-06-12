#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <string>
#include <vector>

class Notification {
public:
    static void send(const std::string& message);
    static void sendBulk(const std::vector<std::string>& messages);
};

#endif
