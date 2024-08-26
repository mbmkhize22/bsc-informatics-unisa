#include "Gate.h"

Gate::Gate(const std::string& desc, const std::string& pass)
    : description(desc), password(pass) {}

bool Gate::checkPassword(const std::string& p) const {
    return p == password;
}

std::string Gate::getDescription() const {
    return description;
}
