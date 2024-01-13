#ifndef DATAMODELLER_H
#define DATAMODELLER_H

#include"Employee.h"
#include"BusinessOwner.h"
#include<variant>
#include<vector>
#include<memory>

using BusinessPointer = std::unique_ptr<BusinessOwner>; //disables copy logic
using EmpPointer =std::unique_ptr<Employee>;
using VType = std::variant<BusinessPointer,EmpPointer>;

class DataModeller
{
private:
    /* data */
    VType _instances;
    std::vector<float> _goodsPrices;
    
public:

    DataModeller(VType v,const std::vector<float>& prices);
    void operator()();
    ~DataModeller() = default;
    DataModeller() = delete;
    DataModeller(const DataModeller &) = delete;
    DataModeller(DataModeller &&) = delete;
    DataModeller operator=(const DataModeller &) = delete;
    DataModeller operator=(DataModeller &&) = delete;

    // VType instances() const { return _instances; }     ----> cannot be done by copy because of unique ptr
    // VType& instances() const { return _instances; }   --> gives guarantee to give original variant (give unique_ptr variants reference)
    //above creates loophole to modify value
    
    const VType& instances() const { return _instances; }     //

    std::vector<float> goodsPrices() const { return _goodsPrices; }
};



#endif // DATAMODELLER_H
