#ifndef CITY_H
#define CITY_H
#include <string>
#include <iostream>
#include<utility>
using namespace std;

class City {
public:
City(string name, unsigned int population) {
namePopulationPair.first= name;
namePopulationPair.second = population;
}
void setName(string name) {namePopulationPair.first= name;}
void setPopulation(unsigned int population) {namePopulationPair.second=population;}
string getName() const {return namePopulationPair.first;}
unsigned int getPopulation() const {return namePopulationPair.second;}
virtual void printInfo() const { cout<<getName()<<": "<<getPopulation()<<endl;}

bool operator<(const City &city) const{
      return (getName() < city.getName());
}

protected:
pair <string, int> namePopulationPair;
};
#endif