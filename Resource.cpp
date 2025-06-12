#include "Resource.h"


Resource::Resource(std::string id, std::string title, std::string author, int year)
    : id(id), title(title), author(author), publicationYear(year), isAvailable(true) {}

std::string Resource::getId() const { return id; }
std::string Resource::getTitle() const { return title; }
std::string Resource::getAuthor() const { return author; }

bool Resource::getAvailability() const { return isAvailable; }

void Resource::setTitle(const std::string& t) { title = t; }
void Resource::setAuthor(const std::string& a) { author = a; }
void Resource::setPublicationYear(int year) { publicationYear = year; }
void Resource::setAvailability(bool status) { isAvailable = status; }
