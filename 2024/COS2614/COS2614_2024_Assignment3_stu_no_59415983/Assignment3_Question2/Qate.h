#ifndef GATE_H
#define GATE_H

#include <string>

class Gate {
private:
    std::string description;
    std::string password;

public:
    Gate(const std::string& desc, const std::string& pass);
    bool checkPassword(const std::string& p) const;
    std::string getDescription() const;
};

#endif
