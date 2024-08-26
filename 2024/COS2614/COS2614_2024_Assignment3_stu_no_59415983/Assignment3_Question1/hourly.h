#ifndef HOURLY_H
#define HOURLY_H

#include "Payment.h"

class Hourly : public Payment {
private:
    double hourlyRate;
    int hoursWorked;

public:
    Hourly(double hourlyRate);
    void addHours(int hours);
    double pay() const override;
    Payment* clone() const override;
};

#endif
