#ifndef MAINTENANCE_H
#define MAINTENANCE_H

#include "string.h"
using namespace std;

class Maintenance {
private:
    Mystring date;
    Mystring technician;
    Mystring description;

public:
    Maintenance();
    Maintenance(const Mystring& date, const Mystring& tech, const Mystring& desc);
    Mystring getDate() const;
    Mystring getTechnician() const;
    Mystring getDescription() const;
};

#endif