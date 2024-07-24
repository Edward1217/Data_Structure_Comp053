#ifndef COASTALCITY_H
#define COASTALCITY_H
#include<iostream>
#include<string>
#include"city.h"
using namespace std;

class CoastalCity: public City{
    public:
        CoastalCity() {
            waterName = "N/A"; 
            beachNum = 0;
            ++coastalCityCount;
        }
        
        CoastalCity(string name, int population, string waterName, int beachNum, string adjCityName, int adjCitypop) {
            this->name = name;
            this->population = population;
            this->waterName= waterName;
            this->beachNum = beachNum;
            adjCity->setName(adjCityName);
            adjCity->setPopulation(adjCitypop);
            ++coastalCityCount;
        }
        
        void setwaterName(string name) { waterName = name;}
        void setbeachNum(int data) {beachNum = data;}
        string getwaterName()const {return waterName;}
        int getbeachNum () const {return beachNum;}
        void printInfo() const override{
            City::printInfo();        //override thie derived class 
            cout <<"Water: " << waterName << endl;
            cout <<"No. of Beaches: " <<beachNum<<endl;
            cout << "Adjacent City:" <<endl;
            adjCity->printInfo();
            cout << endl;
        }
        CoastalCity operator * (int rhs);
        CoastalCity operator + (CoastalCity rhs);
        static unsigned int getCoastalCityCount(){ return coastalCityCount; }
        City* getAdjCity() {return adjCity;}
    private:
        string waterName;
        int beachNum;
        static unsigned int coastalCityCount;
        City* adjCity = new City;
};
    CoastalCity CoastalCity::operator*(int rhs) {
        CoastalCity totalNum;
        totalNum.name = name;
        totalNum.population = population;
        totalNum.waterName= waterName;
        totalNum.beachNum =  beachNum * rhs;
        return totalNum;
    }

    CoastalCity CoastalCity::operator+(CoastalCity rhs) {
        CoastalCity newcoastalName;
        newcoastalName.name = name.append(rhs.name);
        newcoastalName.population = population + rhs.population;
        newcoastalName.waterName = waterName.append(rhs.waterName);
        newcoastalName.beachNum = beachNum + rhs.beachNum;
        return newcoastalName;
    }   
#endif