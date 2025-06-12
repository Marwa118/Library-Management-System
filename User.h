#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class Resource;

class User {
private:
    std::string userId;
    std::string name;
    std::vector<Resource*> borrowedItems;

public:
    User();
    User(const std::string& id, const std::string& name);
    User(const std::string& id, const char* name); 

    std::string getUserId() const;
    std::string getName() const;
    void setName(const std::string& n);

    void borrowResource(Resource* resource);
    void returnResource(Resource* resource);
    void listBorrowedItems() const;

    std::string toCSV() const;
    static User fromCSV(const std::string& line);

};

#endif
