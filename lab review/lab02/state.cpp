#include "cities.h"

class State {
  public:
    State() {name = "N/A";} 
    void setName(string stateName) {name = stateName;}
    string getName() const {return name;}
    void readStateCities() {
      stateCities.readCities();
    }
    void printStateCities() {
      stateCities.printCityList();
    }
  private:
    string name;
    Cities stateCities;
};