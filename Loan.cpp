#include "Loan.h"
#include "MyDate.h"   // ✅ Include your custom date class
#include <sstream>

Loan::Loan(const std::string& resourceId, const std::string& userId, const MyDate& dueDate)
    : resourceId(resourceId), userId(userId), dueDate(dueDate) {}

std::string Loan::getResourceId() const { return resourceId; }
std::string Loan::getUserId() const { return userId; }
MyDate Loan::getDueDate() const { return dueDate; }

void Loan::setDueDate(const MyDate& date) {
    dueDate = date;
}

bool Loan::isOverdue(const MyDate& today) const {
    return dueDate.isBefore(today);
}

void Loan::renew(int extraDays) {
    dueDate.addDays(extraDays);
}

std::string Loan::toCSV() const {
    return resourceId + "," + userId + "," + dueDate.toString();
}

Loan Loan::fromCSV(const std::string& line) {
    std::stringstream ss(line);
    std::string resId, usrId, dateStr;
    getline(ss, resId, ',');
    getline(ss, usrId, ',');
    getline(ss, dateStr);
    MyDate due = MyDate::fromString(dateStr);
    return Loan(resId, usrId, due);
}
