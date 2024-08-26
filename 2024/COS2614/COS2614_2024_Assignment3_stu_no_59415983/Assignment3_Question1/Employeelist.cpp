#include "EmployeeList.h"

EmployeeList::~EmployeeList() {
    qDeleteAll(*this);
    clear();
}
