#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>

class Payment {
protected:
    std::string type;

public:
    virtual ~Payment() = default;
    virtual double pay() const = 0;
    virtual Payment* clone() const = 0;
    std::string getType() const { return type; }
};

#endif
