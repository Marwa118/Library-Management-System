#ifndef BOOK_H
#define BOOK_H
#include<sstream>
#include "Resource.h"

class Book : public Resource {
private:
int publicationYear;
public:
    Book(std::string id, std::string title, std::string author, int year);
    void displayInfo() const override;

    std::string toCSV() const override;
    static Book* fromCSV(const std::string& line);
    int getPublicationYear() const override;
    
  };





#endif
