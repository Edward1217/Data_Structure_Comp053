#ifndef CITIY_H
#define CITIY_H
#include<string>
using namespace std;
class City {
  public:
    void setName(string name) {this-> name = name;}
    void setPopulation (unsigned int population) {this-> population = population;}
    string getName() const {return name;}
    unsigned int getPopulation() const{return population;}

    City() {name = "N/A";population = 0;} 
    City(string name, unsigned int population) {
      this->name = name;
      this->population = population;
    };
  private:
    string name;
    unsigned int population;
};  
#endif