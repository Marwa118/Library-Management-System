#include "IdGenerator.h"

int IdGenerator::counter = 0;

std::string IdGenerator::generate(const std::string& prefix) {
    return prefix + std::to_string(++counter);
}
