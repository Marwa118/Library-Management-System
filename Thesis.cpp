#include "Thesis.h"
#include <iostream>
#include <sstream>

Thesis::Thesis(std::string id, std::string title, std::string author, int year)
    : Resource(id, title, author, year) {}

void Thesis::displayInfo() const {
    std::cout << "Thesis: " << getTitle() << " by " << getAuthor()
              << " (" << getPublicationYear() << ")\n";
}

std::string Thesis::toCSV() const {
    return "Thesis," + getId() + "," + getTitle() + "," + getAuthor() + "," +
           std::to_string(getPublicationYear()) + "," + (getAvailability() ? "1" : "0");
}

Thesis* Thesis::fromCSV(const std::string& line) {
    std::stringstream ss(line);
    std::string type, id, title, author, yearStr, availStr;
    getline(ss, type, ',');
    getline(ss, id, ',');
    getline(ss, title, ',');
    getline(ss, author, ',');
    getline(ss, yearStr, ',');
    getline(ss, availStr);
    auto* thesis = new Thesis(id, title, author, std::stoi(yearStr));
    thesis->setAvailability(availStr == "1");
    return thesis;
}
int Thesis::getPublicationYear() const {
    return publicationYear;
}


