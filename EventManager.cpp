#include "EventManager.h"
#include "FileManager.h"
#include <sstream>

Event::Event(const std::string& t, const std::string& d, const std::string& desc)
    : title(t), date(d), description(desc) {}

std::string Event::toCSV() const {
    return title + "," + date + "," + description;
}

Event Event::fromCSV(const std::string& line) {
    std::stringstream ss(line);
    std::string t, d, desc;
    getline(ss, t, ',');
    getline(ss, d, ',');
    getline(ss, desc);
    return Event(t, d, desc);
}

std::string Event::getTitle() const { return title; }
std::string Event::getDate() const { return date; }
std::string Event::getDescription() const { return description; }

void EventManager::addEvent(const Event& e) {
    events.push_back(e);
}

const std::vector<Event>& EventManager::getAllEvents() const {
    return events;
}

void EventManager::loadEvents() {
    auto lines = FileManager::readFromFile("events.csv");
    for (const auto& line : lines) {
        events.push_back(Event::fromCSV(line));
    }
}

void EventManager::saveEvents() {
    std::vector<std::string> lines;
    for (const auto& e : events) {
        lines.push_back(e.toCSV());
    }
    FileManager::saveToFile("events.csv", lines);
}
