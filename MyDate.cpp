#include "MyDate.h"
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <ctime>

MyDate::MyDate() : day(1), month(1), year(2000) {}

MyDate::MyDate(int d, int m, int y) : day(d), month(m), year(y) {}

int MyDate::getDay() const { return day; }
int MyDate::getMonth() const { return month; }
int MyDate::getYear() const { return year; }

void MyDate::setDay(int d) { day = d; }
void MyDate::setMonth(int m) { month = m; }
void MyDate::setYear(int y) { year = y; }

std::string MyDate::toString() const {
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << day << "/"
        << std::setw(2) << std::setfill('0') << month << "/"
        << year;
    return oss.str();
}

bool MyDate::isBefore(const MyDate& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

void MyDate::addDays(int days) {
    day += days;
    while (day > 30) { // simplified calendar (30 days/month)
        day -= 30;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

MyDate MyDate::fromString(const std::string& str) {
    int d, m, y;
    sscanf(str.c_str(), "%d/%d/%d", &d, &m, &y);
    return MyDate(d, m, y);
}
MyDate MyDate::getToday() {
	time_t now = time(0);
	tm* local = localtime(&now);
	return MyDate(local->tm_mday, local->tm_mon + 1, local->tm_year + 1900);
}





