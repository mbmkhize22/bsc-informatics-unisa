#include <QCoreApplication>
#include <iostream>
#include "storeitem.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    StoreItem item1(1, "Iphone", 32000.99);
    Supplier supplierA(2301, "IStore V&A", "Shop 13 V&A, Cape town");
    item1.setSupplier(supplierA);

    StoreItem item2(1, "Milk", 15.99);
    Supplier supplierB(2301, "Spar", "Shop 13 Bellville, Cape town");
    item2.setSupplier(supplierB);

    std::cout << "Item Details (without supplier): " << item1.toString().toStdString() << std::endl;
    std::cout << "Item Details (with supplier): " << item1.toString(true).toStdString() << std::endl;
    std::cout << "Supplier Name: " << item1.getSupplierName().toStdString() << std::endl;

    std::cout << "\n\nItem Details (without supplier): " << item2.toString().toStdString() << std::endl;
    std::cout << "Item Details (with supplier): " << item2.toString(true).toStdString() << std::endl;
    std::cout << "Supplier Name: " << item2.getSupplierName().toStdString() << std::endl;

    return a.exec();
}
