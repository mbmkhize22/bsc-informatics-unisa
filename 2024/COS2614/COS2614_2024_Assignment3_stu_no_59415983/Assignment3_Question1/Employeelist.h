#ifndef EMPLOYEELIST_H
#define EMPLOYEELIST_H

#include <QList>
#include "Employee.h"

class EmployeeList : public QList<Employee*> {
public:
    ~EmployeeList();
};

#endif
