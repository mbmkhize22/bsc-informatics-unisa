#include "CustomerList.h"
#include <QList>
#include <QMap>
#include <QMultiMap>
#include <QString>
#include "customer.h"
#include "customerlist.h"

CustomerList::~CustomerList() {
    qDeleteAll(*this);
    clear();
}

void CustomerList::updateIndices(Customer* customer) {
    idIndex.insert(customer->getId(), customer);
    nameIndex.insert(QString::fromStdString(customer->getName()), customer);
    postalCodeIndex.insert(QString::fromStdString(customer->getPostalCode()), customer);
}

void CustomerList::removeFromIndices(Customer* customer) {
    idIndex.remove(customer->getId());
    nameIndex.remove(QString::fromStdString(customer->getName()), customer);
    postalCodeIndex.remove(QString::fromStdString(customer->getPostalCode()), customer);
}

bool CustomerList::add(Customer* customer) {
    if (idIndex.contains(customer->getId())) {
        return false;  // ID must be unique
    }
    append(customer);
    updateIndices(customer);
    return true;
}

bool CustomerList::remove(int id) {
    Customer* customer = findByID(id);
    if (!customer) {
        return false;  // Customer not found
    }
    removeFromIndices(customer);
    removeOne(customer);
    delete customer;
    return true;
}


Customer* CustomerList::findByID(int id) const {
    return idIndex.value(id, nullptr);
}

QList<Customer*> CustomerList::findByName(const QString& name) const {
    return nameIndex.values(name);
}

QList<Customer*> CustomerList::findByPostalCode(const QString& postalCode) const {
    return postalCodeIndex.values(postalCode);
}
