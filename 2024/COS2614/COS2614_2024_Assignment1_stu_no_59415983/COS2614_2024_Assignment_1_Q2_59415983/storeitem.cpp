#include "storeitem.h"

StoreItem::StoreItem(int id, const QString &name, double price)
    : Item(id, name, price), supplier(nullptr) {}

void StoreItem::setSupplier(const Supplier &supplier) {
    this->supplier = new Supplier(supplier);
}

QString StoreItem::getSupplierName() const {
    return supplier ? supplier->getName() : "Unknown";
}

QString StoreItem::toString(bool includeSupplierDetails) const {
    QString details = Item::toString();
    if (includeSupplierDetails && supplier) {
        details += ", " + supplier->toString();
    }
    return details;
}
