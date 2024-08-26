#include "Salary.h"

Salary::Salary(double monthlySalary)
    : monthlySalary(monthlySalary) {
    type = "Salary";
}

double Salary::pay() const {
    return monthlySalary;
}

Payment* Salary::clone() const {
    return new Salary(*this);
}
