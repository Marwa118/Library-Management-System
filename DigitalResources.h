#ifndef DIGITALRESOURCE_H
#define DIGITALRESOURCE_H

#include "Resource.h"

class DigitalResource : public Resource {
    private:
    int publicationYear;
public:
    DigitalResource(std::string id, std::string title, std::string author, int year);

    void displayInfo() const override;
    std::string toCSV() const override;
    static DigitalResource* fromCSV(const std::string& line);
    int getPublicationYear() const override;

};

#endif
