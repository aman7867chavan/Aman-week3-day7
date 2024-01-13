#include "BusinessOwner.h"

BusinessOwner::BusinessOwner(float expense, float revenue, std::string name, BusinessType type)
:_expense(expense),_revenue(revenue),_registereBusinessName(name),_type(type)
{
}
std::ostream &operator<<(std::ostream &os, const BusinessOwner &rhs) {
    os << "_expense: " << rhs._expense
       << " _revenue: " << rhs._revenue
       << " _registereBusinessName: " << rhs._registereBusinessName
       << " _type: " <<static_cast<int>( rhs._type);
    return os;
}
