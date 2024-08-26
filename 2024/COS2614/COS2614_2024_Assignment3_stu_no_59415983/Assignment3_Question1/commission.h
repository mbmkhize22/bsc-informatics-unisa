#ifndef COMMISSION_H
#define COMMISSION_H

#include "Payment.h"

class Commission : public Payment {
private:
    double commissionRate;
    double totalSales;

public:
    Commission(double commissionRate);
    void addSales(double sales);
    double pay() const override;
    Payment* clone() const override;
};

#endif
