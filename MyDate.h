#ifndef MYDATE_H
#define MYDATE_H

#include <string>

class MyDate {
private:
    int day;
    int month;
    int year;

public:
    MyDate();  // default constructor
    MyDate(int d, int m, int y);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    std::string toString() const;
    bool isBefore(const MyDate& other) const;
    void addDays(int days);

    static MyDate fromString(const std::string& str);  // "dd/mm/yyyy"
    static MyDate getToday();  

};

#endif
