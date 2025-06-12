#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H

#include <vector>
#include <string>
#include "User.h"
#include "Loan.h"
#include "Reservation.h"
#include "Resource.h"
#include "MyDate.h"  // ✅ Include your renamed Date class

class LibrarySystem {
private:
    std::vector<User> users;
    std::vector<Resource*> resources;
    std::vector<Loan> loans;
    std::vector<Reservation> reservations;

public:
    void addUser(const User& user);
    void addResource(Resource* resource);
    void borrowResource(const std::string& userId, const std::string& resourceId);
    void returnResource(const std::string& userId, const std::string& resourceId);
    void searchResources(const std::string& keyword) const;

    void checkOverdues(const MyDate& today);  // ✅ Changed from std::string to MyDate

    void saveData();
    void loadData();
    const std::vector<Resource*>& getAllResources() const;
    const std::vector<Loan>& getLoans() const;


};

#endif
