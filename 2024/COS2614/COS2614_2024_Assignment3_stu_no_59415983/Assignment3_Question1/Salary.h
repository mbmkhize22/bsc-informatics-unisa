#ifndef SALARY_H
#define SALARY_H

#include "Payment.h"

class Salary : public Payment {
private:
    double monthlySalary;

public:
    Salary(double monthlySalary);
    double pay() const override;
    Payment* clone() const override;
};

#endif
