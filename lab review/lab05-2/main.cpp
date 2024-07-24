#include <iostream>
#include "city.h"
#include "CoastalCity.h"

int main() {
    CoastalCity* ccityPtr = new CoastalCity ("Miami", 500000, "Atlantic Ocean", 8, "Coral Gables", 50000);
    cout << "address of coastal city: " << ccityPtr <<endl;
    cout << "address of adjacent city: " << ccityPtr->getAdjCity() <<endl;
    ccityPtr->printInfo();
    
    return 0;
}