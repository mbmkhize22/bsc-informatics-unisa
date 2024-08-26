#include "Employee.h"
#include <utility>

int Employee::nextID = 1001;

Employee::Employee(const std::string& firstName, const std::string& surname, Payment* payment)
    : id(nextID++), firstName(firstName), surname(surname), payment(payment) {}

Employee::Employee(const Employee& other)
    : id(other.id), firstName(other.firstName), surname(other.surname), payment(other.payment ? other.payment->clone() : nullptr) {}

Employee& Employee::operator=(const Employee& other) {
    if (this == &other) return *this;

    id = other.id;
    firstName = other.firstName;
    surname = other.surname;
    delete payment;
    payment = other.payment ? other.payment->clone() : nullptr;

    return *this;
}

Employee::~Employee() {
    delete payment;
}

int Employee::getId() const { return id; }
std::string Employee::getFirstName() const { return firstName; }
std::string Employee::getSurname() const { return surname; }
Payment* Employee::getPayment() const { return payment; }
