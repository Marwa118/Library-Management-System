#include "Article.h"
#include <iostream>
#include <sstream>

Article::Article(std::string id, std::string title, std::string author, int year)
    : Resource(id, title, author, year) {}

void Article::displayInfo() const {
    std::cout << "Article: " << getTitle() << " by " << getAuthor()
              << " (" << getPublicationYear() << ")\n";
}

std::string Article::toCSV() const {
    return "Article," + getId() + "," + getTitle() + "," + getAuthor() + "," +
           std::to_string(getPublicationYear()) + "," + (getAvailability() ? "1" : "0");
}

Article* Article::fromCSV(const std::string& line) {
    std::stringstream ss(line);
    std::string type, id, title, author, yearStr, availStr;
    getline(ss, type, ',');
    getline(ss, id, ',');
    getline(ss, title, ',');
    getline(ss, author, ',');
    getline(ss, yearStr, ',');
    getline(ss, availStr);

    auto* article = new Article(id, title, author, std::stoi(yearStr));
    article->setAvailability(availStr == "1");
    return article;
}
int Article::getPublicationYear() const {
    return publicationYear;
}
