#ifndef DATAMODELLER_H
#define DATAMODELLER_H

#include "Employee.h"
#include <variant>
#include "BusinessOwner.h"
#include <vector>
#include <memory>
using BusinessPointer = std::unique_ptr<BusinessOwner>;
using EmpPointer = std::unique_ptr<Employee>;
using VType = std::variant<BusinessPointer, EmpPointer>;

class DataModeller
{
private:
    VType _instance;
    std::vector<float> _goodsPrices;

public:
    DataModeller ( VType type,const std::vector<float>&goodsPrices);

    void operator()();
    DataModeller(/* args */) = delete;
    ~DataModeller() = default;
    DataModeller(const DataModeller &) = delete;
    DataModeller(DataModeller &&) = delete;
    DataModeller operator=(const DataModeller &) = delete;
    DataModeller operator=(DataModeller &&) = delete;

    const VType& instance() const { return _instance; }

    std::vector<float> goodsPrices() const { return _goodsPrices; }

};

#endif // DATAMODELLER_H
