#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "Payment.h"

class Employee {
private:
    static int nextID;
    int id;
    std::string firstName;
    std::string surname;
    Payment* payment;

public:
    Employee(const std::string& firstName, const std::string& surname, Payment* payment);
    Employee(const Employee& other);
    Employee& operator=(const Employee& other);
    ~Employee();

    int getId() const;
    std::string getFirstName() const;
    std::string getSurname() const;
    Payment* getPayment() const;
};

#endif
