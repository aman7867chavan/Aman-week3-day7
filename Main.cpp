#include "Functionalities.h"
#include<thread>
#include<array>
int main()
{
    Container data;
    std::array<std::thread,3> arr;
    arr[0]=std::thread (CreateObjects,std::ref(data));
    
    arr[0].join();
    arr[1]= std::thread (CalculateTax,std::ref(data));
    arr[2]=std::thread (CallParentOperator,std::ref(data));
    for(int i=1;i<3;i++)
        arr[i].join();
    
    
    // CreateObjects (data);
    // CalculateTax(data);
    // CallParentOperator(data);
}