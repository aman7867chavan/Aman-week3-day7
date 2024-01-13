#ifndef BUSINESSOWNER_H
#define BUSINESSOWNER_H
#include<iostream>
#include "BusinessType.h"
class BusinessOwner
{
private:
    float _expense;
    float _revenue;
    std::string _registereBusinessName;
    BusinessType  _type;
public:
    BusinessOwner(float expense,float revenue, std::string name,BusinessType type); // PC
    ~BusinessOwner() = default;
    BusinessOwner() = default;
    BusinessOwner(const BusinessOwner &) = delete;
    BusinessOwner(BusinessOwner &&) = delete;
    BusinessOwner operator=(const BusinessOwner &) = delete;
    BusinessOwner operator=(BusinessOwner &&) = delete;

    float expense() const { return _expense; }
    float revenue() const { return _revenue; }
    std::string registereBusinessName() const { return _registereBusinessName; }
    BusinessType type() const { return _type; }

    friend std::ostream &operator<<(std::ostream &os, const BusinessOwner &rhs);
};

#endif // BUSINESSOWNER_H
