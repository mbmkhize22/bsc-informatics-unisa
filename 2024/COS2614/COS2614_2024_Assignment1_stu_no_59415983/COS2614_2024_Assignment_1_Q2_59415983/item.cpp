#include "item.h"

Item::Item(int id, const QString &name, double price) : id(id), name(name), price(price) {}

int Item::getId() const
{
    return id;
}

void Item::setId(int id)
{
    this->id = id;
}

QString Item::getName() const
{
    return name;
}

void Item::setName(const QString &name)
{
    this->name = name;
}

double Item::getPrice() const
{
    return price;
}

void Item::setPrice(double price)
{
    this->price = price;
}

QString Item::toString() const {
    return QString("ID: %1, Name: %2, Price: %3").arg(id).arg(name).arg(price);
}
