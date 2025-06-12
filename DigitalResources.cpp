#include "DigitalResources.h"
#include <iostream>
#include <sstream>

DigitalResource::DigitalResource(std::string id, std::string title, std::string author, int year)
    : Resource(id, title, author, year) {}

void DigitalResource::displayInfo() const {
    std::cout << "Digital Resource: " << getTitle() << " by " << getAuthor()
              << " (" << getPublicationYear() << ")\n";
}

std::string DigitalResource::toCSV() const {
    return "Digital," + getId() + "," + getTitle() + "," + getAuthor() + "," +
           std::to_string(getPublicationYear()) + "," + (getAvailability() ? "1" : "0");
}

DigitalResource* DigitalResource::fromCSV(const std::string& line) {
    std::stringstream ss(line);
    std::string type, id, title, author, yearStr, availStr;
    getline(ss, type, ',');
    getline(ss, id, ',');
    getline(ss, title, ',');
    getline(ss, author, ',');
    getline(ss, yearStr, ',');
    getline(ss, availStr);
    auto* dr = new DigitalResource(id, title, author, std::stoi(yearStr));
    dr->setAvailability(availStr == "1");
    return dr;
}
int DigitalResource:: getPublicationYear() const  {
    return publicationYear;
}