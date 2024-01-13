#include "DataModeller.h"

void DataModeller::operator()()
{
    if(_goodsPrices.empty())
        throw std::runtime_error("Data empty");
    float total=0;
    for(auto value:_goodsPrices)
        total+=value;
    std::cout<<"Average price: "<<total/_goodsPrices.size()<<'\n';


}

DataModeller::DataModeller(VType type, const std::vector<float>& goodsPrices)
:_instance(std::move(type)),_goodsPrices(goodsPrices)
{
}

