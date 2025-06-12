#include "LibrarySystem.h"
#include "SearchEngine.h"
#include "Notification.h"
#include "FileManager.h"
#include "User.h"
#include "Book.h"
#include "Thesis.h"
#include "DigitalResources.h"
#include "Article.h"
#include "Loan.h"
#include "Reservation.h"
#include "MyDate.h"  // ✅ Include your custom date class

#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>

// Helper to get today's date as MyDate
MyDate getToday() {
    time_t now = time(0);
    tm* timeInfo = localtime(&now);
    return MyDate(timeInfo->tm_mday, timeInfo->tm_mon + 1, timeInfo->tm_year + 1900);
}

// Helper to get due date: today + 7 days
MyDate getDueDate() {
    MyDate today = getToday();
    today.addDays(7);
    return today;
}

//------------------- LibrarySystem Methods ----------------------

void LibrarySystem::addUser(const User& user) {
    users.push_back(user);
}

void LibrarySystem::addResource(Resource* resource) {
    resources.push_back(resource);
}

void LibrarySystem::borrowResource(const std::string& userId, const std::string& resourceId) {
    for (auto& user : users) {
        if (user.getUserId() == userId) {
            for (auto* res : resources) {
                if (res->getId() == resourceId && res->getAvailability()) {
                    user.borrowResource(res);
                    res->setAvailability(false);
                    Notification::send("You have borrowed: " + res->getTitle());

                    MyDate dueDate = getDueDate();  // ✅ now using MyDate
                    loans.emplace_back(resourceId, userId, dueDate);
                    return;
                }
            }

            reservations.emplace_back(resourceId, userId);
            Notification::send("Resource unavailable. Reserved: " + resourceId);
        }
    }
}

void LibrarySystem::returnResource(const std::string& userId, const std::string& resourceId) {
    for (auto& user : users) {
        if (user.getUserId() == userId) {
            for (auto* res : resources) {
                if (res->getId() == resourceId) {
                    user.returnResource(res);
                    res->setAvailability(true);
                    Notification::send("You returned: " + res->getTitle());

                    for (auto& r : reservations) {
                        if (r.getResourceId() == resourceId && !r.isFulfilled()) {
                            Notification::send("Reserved item available for: " + r.getUserId());
                            r.fulfill();
                            break;
                        }
                    }
                    return;
                }
            }
        }
    }
}

void LibrarySystem::searchResources(const std::string& keyword) const {
    auto results = SearchEngine::search(resources, keyword);
    for (const auto* res : results) {
        res->displayInfo();
    }
}

void LibrarySystem::checkOverdues(const MyDate& today) {
    for (const auto& loan : loans) {
        if (loan.isOverdue(today)) {
            Notification::send("Loan overdue for resource: " + loan.getResourceId());
        }
    }
}

//------------------- File I/O ----------------------

void LibrarySystem::saveData() {
    std::vector<std::string> userLines;
    for (const auto& u : users)
        userLines.push_back(u.toCSV());
    FileManager::saveToFile("users.csv", userLines);

    std::vector<std::string> resourceLines;
    for (const auto* r : resources)
        resourceLines.push_back(r->toCSV());
    FileManager::saveToFile("resources.csv", resourceLines);

    std::vector<std::string> loanLines;
    for (const auto& l : loans)
        loanLines.push_back(l.toCSV());
    FileManager::saveToFile("loans.csv", loanLines);

    std::vector<std::string> reservationLines;
    for (const auto& r : reservations)
        reservationLines.push_back(r.toCSV());
    FileManager::saveToFile("reservations.csv", reservationLines);
}

void LibrarySystem::loadData() {
    auto userLines = FileManager::readFromFile("users.csv");
    for (const auto& line : userLines)
        users.push_back(User::fromCSV(line));

    auto resourceLines = FileManager::readFromFile("resources.csv");
    for (const auto& line : resourceLines) {
        std::stringstream ss(line);
        std::string type;
        getline(ss, type, ',');

        if (type == "Book") {
            resources.push_back(Book::fromCSV(line));
        } else if (type == "Thesis") {
            resources.push_back(Thesis::fromCSV(line));
        } else if (type == "Digital") {
            resources.push_back(DigitalResource::fromCSV(line));
        } else if (type == "Article") {
            resources.push_back(Article::fromCSV(line));
        }
    }

    auto loanLines = FileManager::readFromFile("loans.csv");
    for (const auto& line : loanLines)
        loans.push_back(Loan::fromCSV(line));

    auto reservationLines = FileManager::readFromFile("reservations.csv");
    for (const auto& line : reservationLines)
        reservations.push_back(Reservation::fromCSV(line));
}
const std::vector<Resource*>& LibrarySystem::getAllResources() const {
    return resources;
}
const std::vector<Loan>& LibrarySystem::getLoans() const {
	return loans;
}

