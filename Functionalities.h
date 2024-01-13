#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include"BusinessOwner.h"
#include"Employee.h"
#include"DataModeller.h"
#include<vector>

using dataPointer = std::unique_ptr<DataModeller>;
using Container = std::vector<dataPointer>;
void CreateObjects(Container& data);

void CalculateTaxPayable(const Container& data);

void CallParanOperator(const Container& data);

#endif // FUNCTIONALITIES_H
