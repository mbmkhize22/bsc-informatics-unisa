#ifndef STOREITEM_H
#define STOREITEM_H

#include "item.h"
#include "supplier.h"

class StoreItem : public Item {
public:
    StoreItem(int id, const QString &name, double price);
    void setSupplier(const Supplier &supplier);
    QString getSupplierName() const;
    QString toString(bool includeSupplierDetails = false) const;

private:
    Supplier *supplier;
};

#endif
