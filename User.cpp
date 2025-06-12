#include "User.h"
#include "Resource.h"
#include <iostream>
#include <algorithm>
#include <sstream>

User::User() : userId(""), name("") {}
User::User(const std::string& id, const std::string& name) : userId(id), name(name) {}
User::User(const std::string& id, const char* name)
    : userId(id), name(name) {}


std::string User::getUserId() const { return userId; }
std::string User::getName() const { return name; }
void User::setName(const std::string& n) { name = n; }

void User::borrowResource(Resource* resource) {
    if (resource->getAvailability()) {
        borrowedItems.push_back(resource);
        resource->setAvailability(false);
    }
}

void User::returnResource(Resource* resource) {
    borrowedItems.erase(std::remove(borrowedItems.begin(), borrowedItems.end(), resource), borrowedItems.end());
    resource->setAvailability(true);
}

void User::listBorrowedItems() const {
    for (const auto& item : borrowedItems)
        item->displayInfo();
}

std::string User::toCSV() const {
    return userId + "," + name;
}

User User::fromCSV(const std::string& line) {
    std::stringstream ss(line);
    std::string id, name;
    getline(ss, id, ',');
    getline(ss, name);
    return User(id, name);
}