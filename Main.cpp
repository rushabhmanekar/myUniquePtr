#include"Functionalities.h"
#include<thread>
#include<array>

int main(){

    std::array<std::thread,3> arr;
    Container data;


    /*
    
    There is a raise condition - when two or more threads tries to write on the same memory

    in this case cout is a shared buffer ( sharing the same memory )

    Buffer - aisa memory location jo reserved rakha hai for some purpose ( in this case output buffer )
    
    */

    arr[0] = std::thread(&CreateObjects,std::ref(data));
    arr[0].join();

    arr[1] = std::thread(&CalculateTaxPayable,std::ref(data));

    arr[2] = std::thread(&CallParanOperator,std::ref(data));

    for(std::thread& th : arr){
        if(th.joinable()){
            th.join();
        }
    }


    // Container data;
    // std::thread t1(&CreateObjects,std::ref(data));
    // t1.join();

    // std::thread t2(&CalculateTaxPayable,std::ref(data));

    // std::thread t3(&CallParanOperator,std::ref(data));

    // CalculateTaxPayable(data);
    // CallParanOperator(data);

    
    
}