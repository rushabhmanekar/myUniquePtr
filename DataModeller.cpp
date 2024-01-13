#include "DataModeller.h"

DataModeller::DataModeller(VType v,const std::vector<float>& prices)
:_goodsPrices(prices), _instances(std::move(v))//std::move(v))
{
}

void DataModeller::operator()()
{
    float total = 0.0f;

    if(_goodsPrices.empty()){
        throw std:: runtime_error("Not Found");
    }

    for(float val : _goodsPrices){
        total += val;
    }

    std::cout<<"\nAverage value is : "<<total/_goodsPrices.size();
}


/*
    Buffer 
[            ]

word - _instance
variant visit - Rushabh 0 780000.0f
word - _goodsPrice
for loop - vector {  , , ,  }


os is a buffer which stores the output to be shown on console
*/


std::ostream &operator<<(std::ostream &os, const DataModeller &rhs) {
    
    os << "_instances: ";

    std::visit([&](auto&& val){os<<*val;},rhs._instances);

    os<< " _goodsPrices: ";

    for(float val : rhs._goodsPrices){
        os<<val<<"\t";
    }

    return os;
}
