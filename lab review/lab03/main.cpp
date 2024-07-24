#include<iostream>
#include"CoastalCity.h"

int main() {
    CoastalCity my_coastalcity;
    my_coastalcity.printInfo();
    my_coastalcity.setName("San Francisco");
    my_coastalcity.setPopulation(900000);
    my_coastalcity.setwaterName("SF BAY");
    my_coastalcity.setbeachNum(10);
    my_coastalcity.printInfo();
    return 0;
}