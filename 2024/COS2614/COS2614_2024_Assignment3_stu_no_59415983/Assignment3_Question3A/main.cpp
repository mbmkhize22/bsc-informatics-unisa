#include <iostream>
#include "CustomerList.h"

int main()
{

    CustomerList customers;

    // Adding customers
    customers.add(new Customer(1001, "Alice Smith", "12345"));
    customers.add(new Customer(1002, "Bob Johnson", "54321"));
    customers.add(new Customer(1003, "Charlie Brown", "12345"));
    customers.add(new Customer(1004, "David White", "67890"));
    customers.add(new Customer(1005, "Eve Black", "67890"));
    customers.add(new Customer(1006, "Frank Green", "54321"));

    // Find by ID
    Customer* customer = customers.findByID(1001);
    if (customer) {
        std::cout << "Found Customer: " << customer->getName() << ", Postal Code: " << customer->getPostalCode() << std::endl;
    } else {
        std::cout << "Customer not found by ID." << std::endl;
    }

    // Find by Name
    QList<Customer*> foundByName = customers.findByName("Alice Smith");
    std::cout << "Customers with name 'Alice Smith':" << std::endl;
    for (Customer* c : foundByName) {
        std::cout << "ID: " << c->getId() << ", Postal Code: " << c->getPostalCode() << std::endl;
    }

    // Find by Postal Code
    QList<Customer*> foundByPostalCode = customers.findByPostalCode("54321");
    std::cout << "Customers with postal code '54321':" << std::endl;
    for (Customer* c : foundByPostalCode) {
        std::cout << "ID: " << c->getId() << ", Name: " << c->getName() << std::endl;
    }

    // Remove a customer
    if (customers.remove(1001)) {
        std::cout << "Customer with ID 1001 removed." << std::endl;
    } else {
        std::cout << "Failed to remove customer with ID 1001." << std::endl;
    }

    return 0;
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    //return a.exec();
}

