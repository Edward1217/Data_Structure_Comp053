#include <iostream>
#include "CoastalCity.h"

unsigned int CoastalCity::coastalCityCount = 0;
int main() {
    CoastalCity city1;
    CoastalCity city2;

    city1.setName("San Diego");
    city1.setPopulation(1500000);
    city1.setwaterName("Pacific ocean");
    city1.setbeachNum(5);
    
    city2.setName("Miami");
    city2.setPopulation(500000);
    city2.setwaterName("Atlantic ocean");
    city2.setbeachNum(8);

    city1 = city1 *5;
    city1.printInfo();
    CoastalCity newCity = city1 + city2;

    newCity.printInfo();

    cout << CoastalCity::getCoastalCityCount() << endl;
    return 0;
}