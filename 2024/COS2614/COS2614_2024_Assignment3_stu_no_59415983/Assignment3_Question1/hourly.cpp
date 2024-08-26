#include "Hourly.h"

Hourly::Hourly(double hourlyRate)
    : hourlyRate(hourlyRate), hoursWorked(0) {
    type = "Hourly";
}

void Hourly::addHours(int hours) {
    hoursWorked += hours;
}

double Hourly::pay() const {
    return hourlyRate * hoursWorked;
}

Payment* Hourly::clone() const {
    return new Hourly(*this);
}
