#include"Functionalities.h"
#include<thread>


int main(){

    Container data;
    std::thread t1(&CreateObjects,std::ref(data));
    t1.join();

    CalculateTaxPayable(data);
    CallParanOperator(data);
    
}