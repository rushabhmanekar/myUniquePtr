#include "Functionalities.h"

// void CreateObjects()
// {   

//     std::unique_ptr<DataModeller> ptr = 
    
    
// }

void CreateObjects(Container &data)
{
    data.emplace_back(
        std::make_unique<DataModeller>(

        std::make_unique<Employee>(
            "Rushabh",
            EmployeeType::REGULAR,
            780000.0f),

        std::vector<float> {19.21f,145.31f,204.5})
    );

    data.emplace_back(
        std::make_unique<DataModeller>(

        std::make_unique<BusinessOwner>(100000.0f,20000.0f,"XYZ COmo",BusinessType::PRIVATE),

        std::vector<float> {19.21f,145.31f,204.5})
    );
}

/*  

    This function will accept a Container of DataModeller pointer

    FOR EACH POINTER, perform following

    a) capture the instance reference
    b) Use holds_alternative to verify which type of pointer is present int the _instance
    c) if pointer is f type BusinessOwner
        i) use std::get to fetch BusinessOwner (this will be safe because if has been checked)
        ii) use the fetched pointer in BusinessOwner to calculate tax for business

        else when pointer is of type Employee

        i) use std::get to fetch EmployeePointer
        ii) use the fetched pointer to fetch type of employee
        iii) if type is REGULAR tax is 10% else it should 20% of salary

    
*/

void CalculateTaxPayable(const Container &data)
{    
    for(const dataPointer& ptr : data ){
        // const VType val = ptr->instances();  --> copy hora hai nahi jamega
        const VType& val = ptr->instances();

        if(std::holds_alternative<BusinessPointer>(val)){
            const BusinessPointer& p = std::get<BusinessPointer> (val);
            std::cout<<"Business Tax : "<<0.1f*(p->revenue()-p->expense());
        }else{
            const EmpPointer& p = std::get<EmpPointer> (val);
            if(p->type()==EmployeeType::REGULAR){
                std::cout<<"Tax is 10% : "<<0.1f * p->salary()<<"\n";
            }else{
                std::cout<<"Tax is 20% : "<<0.2f * p->salary()<<"\n";
            }
        }
    }
}

/*

*/

void CallParanOperator(const Container &data)
{
    if(data.empty()){
        throw std::runtime_error("data empty");

    }else{
        for(const dataPointer& ptr : data){
            ptr->operator()();
        }
    }
}
