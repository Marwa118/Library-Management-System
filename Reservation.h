#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include<sstream>
class Reservation {
private:
    std::string resourceId;
    std::string userId;
    bool fulfilled;

public:
    Reservation(std::string resourceId, std::string userId);

    std::string getResourceId() const;
    std::string getUserId() const;
    bool isFulfilled() const;
    void fulfill();
    std::string toCSV() const;
    static Reservation fromCSV(const std::string& line);

};

#endif
