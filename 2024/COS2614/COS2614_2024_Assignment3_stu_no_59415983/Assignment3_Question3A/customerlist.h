#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include <QList>
#include <QMap>
#include <QMultiMap>
#include "customer.h"

class CustomerList : public QList<Customer*> {
private:
    QMap<int, Customer*> idIndex;
    QMultiMap<QString, Customer*> nameIndex;
    QMultiMap<QString, Customer*> postalCodeIndex;

    void updateIndices(Customer* customer);
    void removeFromIndices(Customer* customer);

public:
    ~CustomerList();
    bool add(Customer* customer);
    bool remove(int id);
    Customer* findByID(int id) const;
    QList<Customer*> findByName(const QString& name) const;
    QList<Customer*> findByPostalCode(const QString& postalCode) const;
};

#endif
