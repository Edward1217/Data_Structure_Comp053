#include <iostream>
#include <map>
#include<utility>
#include "city.h"
using namespace std;

City cityArray[] = {
  City("Los Angeles",4000000),
  City("San Diego",1500000),
  City("San Francisco",900000),
  City("Sacramento",500000),
  City("Stockton",300000)
};

map <string, int> cityMap;

void initMap(map <string, int> &cityMap, City array[], int size) {
    for (int i = 0; i < size; ++i) {
        cityMap.emplace(array[i].getName(), array[i].getPopulation());
    }    
    
}

void printCityMap(map <string, int> cityMap) {
    for(auto elements: cityMap) {
        cout << elements.first<< ":" << elements.second <<endl;
    }
}

unsigned int findPopulation(map <string, int> cityMap, string name) {
    for(auto elements:cityMap) {
        if(elements.first == name) {
            return elements.second;
        }
    }
    return 0;
}

void updatePopulation(map <string, int>& cityMap, string cityname,int citypop) {
    for(auto elements:cityMap) {
        if(elements.first == cityname) {
           cityMap.at(cityname) = citypop;
        }
        else {
            cityMap.emplace(cityname, citypop);
        }
    }
}


void removeFromCityMap(map <string, int>& cityMap, string cityname) {
            cityMap.erase(cityname);
}

int main() {
    
    cout << "Initializing cityMap with cityArray[]:" <<endl;
    initMap(cityMap,cityArray,5);
    printCityMap(cityMap);
    
    cout <<"Find population of Sacramento: ";
    cout << findPopulation(cityMap, "Sacramento") << endl;
    
    cout << "Find population of Chicago: ";
    cout << findPopulation(cityMap, "Chicago") << endl;
    
    cout << "Find population of Stockton after update: ";
    updatePopulation(cityMap, "Stockton", 35000);
    cout << cityMap.at("Stockton");
    cout << endl;
    
    cout <<"Find population of Portland after update: ";
    updatePopulation(cityMap, "Portland", 70000);
    cout << cityMap.at("Portland");
    cout << endl;
    
    cout << "Removing San Francisco from cityMap:" <<endl;
    removeFromCityMap(cityMap, "San Francisco");
    //cityMap.erase("San Francisco");
    printCityMap(cityMap);
    return 0;    
}