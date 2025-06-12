#ifndef IDGENERATOR_H
#define IDGENERATOR_H

#include <string>

class IdGenerator {
private:
    static int counter;

public:
    static std::string generate(const std::string& prefix);
};

#endif
