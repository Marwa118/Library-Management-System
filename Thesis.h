#ifndef THESIS_H
#define THESIS_H

#include "Resource.h"

class Thesis : public Resource {
private:
int publicationYear;
public:
    Thesis(std::string id, std::string title, std::string author, int year);

    void displayInfo() const override;
    std::string toCSV() const override;
    static Thesis* fromCSV(const std::string& line);
    int getPublicationYear() const override;

};

#endif
