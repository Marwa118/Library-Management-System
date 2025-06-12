#include "Book.h"
#include <iostream>
#include<sstream>

Book::Book(std::string id, std::string title, std::string author, int year)
    : Resource(id, title, author, year) {}

void Book::displayInfo() const {
    std::cout << "Book: " << getTitle() << " by " << getAuthor()
              << " (" << getPublicationYear() << ")\n";
}

std::string Book::toCSV() const {
    return "Book," + getId() + "," + getTitle() + "," + getAuthor() + "," +
           std::to_string(getPublicationYear()) + "," + (getAvailability() ? "1" : "0");
}

Book* Book::fromCSV(const std::string& line) {
    std::stringstream ss(line);
    std::string type, id, title, author, yearStr, availStr;
    getline(ss, type, ',');
    getline(ss, id, ',');
    getline(ss, title, ',');
    getline(ss, author, ',');
    getline(ss, yearStr, ',');
    getline(ss, availStr);
    Book* book = new Book(id, title, author, std::stoi(yearStr));
    book->setAvailability(availStr == "1");
    return book;
}
int Book::getPublicationYear() const {
    return publicationYear;
}


