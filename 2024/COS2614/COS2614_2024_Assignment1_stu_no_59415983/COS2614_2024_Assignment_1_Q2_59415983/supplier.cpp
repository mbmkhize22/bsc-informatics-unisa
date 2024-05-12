#include "supplier.h"

Supplier::Supplier(int supplierId, const QString &name, const QString &address)
    : supplierId(supplierId), name(name), address(address) {}

int Supplier::getSupplierId() const
{
    return supplierId;
}

void Supplier::setSupplierId(int supplierId)
{
    this->supplierId = supplierId;
}

QString Supplier::getName() const
{
    return name;
}

void Supplier::setName(const QString &name)
{
    this->name = name;
}

QString Supplier::getAddress() const
{
    return address;
}

void Supplier::setAddress(const QString &address)
{
    this->address = address;
}

QString Supplier::toString() const {
    return QString("Supplier ID: %1, Name: %2, Address: %3").arg(supplierId).arg(name).arg(address);
}
