#include "Commission.h"

Commission::Commission(double commissionRate)
    : commissionRate(commissionRate), totalSales(0) {
    type = "Commission";
}

void Commission::addSales(double sales) {
    totalSales += sales;
}

double Commission::pay() const {
    return commissionRate * totalSales;
}

Payment* Commission::clone() const {
    return new Commission(*this);
}
