#include "Maintenance.h"
using namespace std;

Maintenance::Maintenance() : date(""), technician(""), description("") {}

Maintenance::Maintenance(const Mystring& date, const Mystring& tech, const Mystring& desc) : date(date), technician(tech), description(desc) {}

Mystring Maintenance::getDate() const {
    return date;
}

Mystring Maintenance::getTechnician() const {
    return technician;
}

Mystring Maintenance::getDescription() const {
    return description;
}