#include "customer.h"

Customer::Customer(int id, const std::string& name, const std::string& postalCode)
    : id(id), name(name), deliveryPostalCode(postalCode) {}

int Customer::getId() const {
    return id;
}

std::string Customer::getName() const {
    return name;
}

std::string Customer::getPostalCode() const {
    return deliveryPostalCode;
}
