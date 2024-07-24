#include"CoastalCity.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    City* my_City1 = nullptr;
    City* my_City2 = nullptr;
    CoastalCity* my_coastalCity1 = nullptr;
    CoastalCity* my_coastalCity2 = nullptr;
    vector <City*> cityVectorList;

    my_City1 = new City;
    my_City1->setName("Denver");
    my_City1->setPopulation(750000);
    my_City2 = new City;
    my_City2->setName("Reno");
    my_City2->setPopulation(250000);

    my_coastalCity1 = new CoastalCity;
    my_coastalCity1->setName("San Diego");
    my_coastalCity1->setPopulation(250000);
    my_coastalCity1->setwaterName("Pacific Ocean");
    my_coastalCity1->setbeachNum(5);

    my_coastalCity2 = new CoastalCity;
    my_coastalCity2->setName("Miami");
    my_coastalCity2->setPopulation(500000);
    my_coastalCity2->setwaterName("Atlantic Ocean");
    my_coastalCity2->setbeachNum(8);

    cityVectorList.push_back(my_City1);
    cityVectorList.push_back(my_City2);
    cityVectorList.push_back(my_coastalCity1);
    cityVectorList.push_back(my_coastalCity2);

    for (int i = 0; i < cityVectorList.size(); ++i) {
        cityVectorList[i]->printInfo();
    }
    return 0;
}