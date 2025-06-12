#ifndef ARTICLE_H
#define ARTICLE_H

#include "Resource.h"

class Article : public Resource {
private:
int publicationYear;
public:
     
    Article(std::string id, std::string title, std::string author, int year);

    void displayInfo() const override;
    std::string toCSV() const override;
    static Article* fromCSV(const std::string& line);
    int getPublicationYear() const override;
   


    
};

#endif
