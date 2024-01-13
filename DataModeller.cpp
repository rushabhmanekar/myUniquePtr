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
