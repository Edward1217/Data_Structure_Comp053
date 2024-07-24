#ifndef CITIES_H
#define CITIES_H
#include "city.h"
#include <vector>

using namespace std;

class Cities {
  public:
    void readCities();
    void printCityList();
    
  private: 
    vector<City> cityList;
};


#endif