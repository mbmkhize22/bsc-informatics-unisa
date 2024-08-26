#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    int id;
    std::string name;
    std::string deliveryPostalCode;

public:
    Customer(int id, const std::string& name, const std::string& postalCode);
    int getId() const;
    std::string getName() const;
    std::string getPostalCode() const;
};

#endif
