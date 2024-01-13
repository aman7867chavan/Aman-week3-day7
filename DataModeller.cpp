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

std::ostream &operator<<(std::ostream &os, const DataModeller &rhs) {
    os << "_instance: ";
    std::visit(
        [&](auto&&val){
            os<<*val<<'\n';
        }
        ,rhs._instance);
    
    os<< " _goodsPrices: ";
    for(auto&p:rhs._goodsPrices)
        os<<p<<'\t';
    return os;
}

DataModeller::DataModeller(VType type, const std::vector<float>& goodsPrices)
:_instance(std::move(type)),_goodsPrices(goodsPrices)
{
}

