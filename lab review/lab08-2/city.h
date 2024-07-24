# ifndef CITY_H
# define CITY_H
#include <string>
#include<iostream>

using namespace std;

class City {
    public:
        City (string nm, unsigned int pop) {
            name = nm;
            population = pop;
        }
        void setName(string name) {this->name = name;}
        void setPopulation(int population) {this->population = population;}
        string getName () const{return name;}
        unsigned int getPopulation() const {return population;}
        virtual void printInfo() {
            cout << getName() <<":" << getPopulation() <<endl;
        }
    protected:
        string name;
        unsigned int population;
};

#endif