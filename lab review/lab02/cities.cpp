#include "cities.h"
#include<iostream>
using namespace std;

void Cities::readCities() {
  City currCity;
  string name;
  int population;
  
  getline(cin, name);
  cout << "City: ";
  getline(cin, name);
  
  while(name !="X") {
    cout << "Population: ";
    cin >> population;
    currCity.setName(name);
    currCity.setPopulation(population);
    cityList.push_back(currCity);
    getline(cin, name);
    cout << "City: ";
    getline(cin, name);
  }
  
}
void Cities::printCityList() {
  
  for (int i = 0; i < cityList.size(); ++i) {
    cout << cityList.at(i).getName() << ": "  << cityList.at(i).getPopulation() << endl;
    
  }
}