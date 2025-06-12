#ifndef LOAN_H
#define LOAN_H

#include <string>
#include "MyDate.h"

class Loan {
private:
    std::string resourceId;
    std::string userId;
    MyDate dueDate;

public:
    Loan(const std::string& resourceId, const std::string& userId, const MyDate& dueDate);

    std::string getResourceId() const;
    std::string getUserId() const;
    MyDate getDueDate() const;
    void setDueDate(const MyDate& date);

    bool isOverdue(const MyDate& today) const;
    void renew(int extraDays);

    std::string toCSV() const;
    static Loan fromCSV(const std::string& line);
};

#endif

