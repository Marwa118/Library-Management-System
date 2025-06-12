#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <string>
#include <vector>

class Event {
private:
    std::string title;
    std::string date;
    std::string description;

public:
    Event(const std::string& t, const std::string& d, const std::string& desc);
    std::string toCSV() const;
    static Event fromCSV(const std::string& line);
    std::string getTitle() const;
    std::string getDate() const;
    std::string getDescription() const;
};

class EventManager {
private:
    std::vector<Event> events;

public:
    void addEvent(const Event& e);
    const std::vector<Event>& getAllEvents() const;
    void loadEvents();     // from events.csv
    void saveEvents();     // to events.csv
};

#endif
