#include "Reservation.h"
#include<sstream>

Reservation::Reservation(std::string resourceId, std::string userId)
    : resourceId(resourceId), userId(userId), fulfilled(false) {}

std::string Reservation::getResourceId() const { return resourceId; }
std::string Reservation::getUserId() const { return userId; }
bool Reservation::isFulfilled() const { return fulfilled; }
void Reservation::fulfill() { fulfilled = true; }
std::string Reservation::toCSV() const {
    return resourceId + "," + userId + "," + (fulfilled ? "1" : "0");
}

Reservation Reservation::fromCSV(const std::string& line) {
    std::stringstream ss(line);
    std::string resId, usrId, fulfilledStr;
    getline(ss, resId, ',');
    getline(ss, usrId, ',');
    getline(ss, fulfilledStr);
    Reservation r(resId, usrId);
    if (fulfilledStr == "1") r.fulfill();
    return r;
}
