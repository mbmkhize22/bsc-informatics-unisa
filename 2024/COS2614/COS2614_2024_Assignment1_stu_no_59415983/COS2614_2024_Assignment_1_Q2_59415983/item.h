#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item {
public:
    Item(int id, const QString &name, double price);
    int getId() const;
    void setId(int id);
    QString getName() const;
    void setName(const QString &name);
    double getPrice() const;
    void setPrice(double price);
    virtual QString toString() const;

private:
    int id;
    QString name;
    double price;
};

#endif
