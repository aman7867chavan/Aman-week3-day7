#include "Functionalities.h"
#include<thread>
#include<array>
    void PrintAll(const Container& data){
        for(const auto&p:data)
            std::cout<<*p;
    }
int main()
{
    Container data;
    std::array<std::thread,4> arr;
    arr[0]=std::thread (CreateObjects,std::ref(data));
    
    arr[0].join();
    arr[1]= std::thread (CalculateTax,std::ref(data));
    arr[2]=std::thread (CallParentOperator,std::ref(data));
    arr[3]=std::thread(PrintAll,std::ref(data));
    for(int i=1;i<4;i++)
        arr[i].join();
    

    // CreateObjects (data);
    // CalculateTax(data);
    // CallParentOperator(data);
}