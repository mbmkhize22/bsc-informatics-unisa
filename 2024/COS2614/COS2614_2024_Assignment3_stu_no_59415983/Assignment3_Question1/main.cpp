#include "mainwindow.h"
#include <iostream>
#include "EmployeeList.h"
#include "Salary.h"
#include "Hourly.h"
#include "Commission.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    EmployeeList employees;

    // Adding employees
    employees.append(new Employee("John", "Doe", new Salary(5000)));
    employees.append(new Employee("Jane", "Smith", new Salary(6000)));
    employees.append(new Employee("Jim", "Beam", new Hourly(50)));
    employees.append(new Employee("Jack", "Daniels", new Hourly(75)));
    employees.append(new Employee("Jill", "Valentine", new Commission(0.1)));
    employees.append(new Employee("Chris", "Redfield", new Commission(0.15)));

    // Adding hours and sales
    dynamic_cast<Hourly*>(employees[2]->getPayment())->addHours(160);
    dynamic_cast<Hourly*>(employees[3]->getPayment())->addHours(150);
    dynamic_cast<Commission*>(employees[4]->getPayment())->addSales(20000);
    dynamic_cast<Commission*>(employees[5]->getPayment())->addSales(30000);

    // Displaying payment report
    for (auto employee : employees) {
        std::cout << "Employee ID: " << employee->getId()
                  << " Name: " << employee->getFirstName() << " " << employee->getSurname()
                  << " Payment Type: " << employee->getPayment()->getType()
                  << " Payment Amount: " << employee->getPayment()->pay()
                  << std::endl;
    }


    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    //return a.exec();
    return 0;
}
