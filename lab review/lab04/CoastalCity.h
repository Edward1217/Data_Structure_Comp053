#include<iostream>
#include<string>
#include"city.h"
using namespace std;

class CoastalCity: public City{
    public:
        CoastalCity() {waterName = "N/A"; beachNum = 0;}
        void setwaterName(string name) { waterName = name;}
        void setbeachNum(int data) {beachNum = data;}
        string getwaterName()const {return waterName;}
        int getbeachNum () const {return beachNum;}
        void printInfo() const override{
            City::printInfo();        //override thie derived class 
            cout <<"Water: " << waterName << endl;
            cout <<"No. of Beaches: " <<beachNum<<endl;
        }
    private:
        string waterName;
        int beachNum;
};