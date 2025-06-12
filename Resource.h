#ifndef RESOURCE_H
#define RESOURCE_H
#include<sstream>
#include <string>

class Resource {
private:
    std::string id, title, author;
    int publicationYear;
    bool isAvailable;

public:
    Resource(std::string id, std::string title, std::string author, int year);
    virtual ~Resource() = default;

    virtual void displayInfo() const = 0;

    std::string getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    virtual int getPublicationYear() const=0;
    bool getAvailability() const;

    void setTitle(const std::string& t);
    void setAuthor(const std::string& a);
    void setPublicationYear(int year);
    void setAvailability(bool status);
    virtual std::string toCSV() const = 0; // pure virtual
    
};

#endif
