#include "Functionalities.h"


void CreateObjects(Container&data)
{
    data.emplace_back(


    std::make_unique<DataModeller>(
        // 1st param _instance
        std::make_unique<Employee>(
            "Aman",
            EmployeeType::REGULAR,
            450000.1f),
            // 2nd param _goodsprices
        std::vector<float>{19, 21.2, 20.4, 100.9})
    );
    data.emplace_back(


    std::make_unique<DataModeller>(
        // 1st param _instance
        std::make_unique<BusinessOwner>(
            1000.0f,
            200.01f,
            "Aman Enterprises",
            BusinessType::PRIVATE
            ),
            // 2nd param _goodsprices
        std::vector<float>{190, 210.2, 200.4, 1000.9})
    );
}

//this will accept container of dataModeller
// Each pointer wil perform
    // capture the instances from instance by reference
    // use holds_alternative to verify which type of pointer is present in the _intance
    // if pointer is of BusinessOwner
        // use std::get to fetch businessowner(safe.. no chance of exception)
        // use fetched pointer in businessowner to calculte tax
    // if pointer is of Employee type
        // use std::get to fetch empPointer
        // use fetched pointer to get salary and then display
    
void CalculateTax(const Container &data)
{
    for(const dataPointer& ptr:data){

        const VType& val=ptr->instance();
        if(std::holds_alternative<BusinessPointer>(val)){
            const BusinessPointer&p=std::get<BusinessPointer>(val);
            std::cout<<"Tax for Business: "<<0.2*((p->expense())-(p->revenue()))<<'\n';
            
        }
        else
        {
            const EmpPointer&p=std::get<EmpPointer>(val);
            if(p->type()==EmployeeType::REGULAR){
            std::cout<<"Tax is 10%:"<<0.1*(p->salary())<<'\n';

            }
            else
                std::cout<<"Tax is 20%:"<<0.2*(p->salary())<<'\n';
                
            
        }
    }
}

void CallParentOperator(const Container &data)
{
    if(data.empty())
        throw std::runtime_error("No data");
    
    for(const dataPointer&ptr:data){
        ptr->operator()();

    }
}
