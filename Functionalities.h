#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "Employee.h"
#include <thread>
#include "BusinessOwner.h"
#include <memory>
#include "DataModeller.h"
#include<vector>
#include<mutex>
using dataPointer=std::unique_ptr<DataModeller>;
using Container=std::vector<dataPointer>;
void CreateObjects(Container&data);

void CalculateTax(const Container&data);

void CallParentOperator(const Container& data);
#endif // FUNCTIONALITIES_H
