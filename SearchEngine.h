#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include <vector>
#include <string>
#include "Resource.h"

class SearchEngine {
public:
    static std::vector<Resource*> search(const std::vector<Resource*>& resources,
                                         const std::string& keyword);
};

#endif
