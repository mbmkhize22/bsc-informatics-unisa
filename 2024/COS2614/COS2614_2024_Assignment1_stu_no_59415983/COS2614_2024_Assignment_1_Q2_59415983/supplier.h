#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <QString>

class Supplier {
public:
    Supplier(int supplierId, const QString &name, const QString &address);
    int getSupplierId() const;
    void setSupplierId(int supplierId);
    QString getName() const;
    void setName(const QString &name);
    QString getAddress() const;
    void setAddress(const QString &address);
    QString toString() const;

private:
    int supplierId;
    QString name;
    QString address;
};

#endif
