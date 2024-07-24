#include"CoastalCity.h"
#include <iostream>

int main() {
    CoastalCity ccity1 ("San diego", 1500000, "Pacific Ocean", 5);
    
    cout<<"The address of ccity1: "<< &ccity1 <<endl;;

    CoastalCity* ccityptr1 = nullptr;

    cout<< "The value stored in ccityPtr1: " << &ccityptr1 << endl;
    cout <<"The address stored in ccityPtr1: " << ccityptr1<<endl;

    cout <<"ccityPtr1 used to call printInfo()" <<endl;
    cout << "Using -> syntax:" <<endl;
    ccityptr1 = &ccity1;
    ccityptr1->printInfo();

    cout <<"Using * syntax:" << endl;
    (*ccityptr1).printInfo();

    CoastalCity* ccity2 = new CoastalCity;
    cout<< "The address stored in ccityPtr2: " << ccity2 <<endl;
    ccity2->setName("Miami");
    ccity2->setPopulation (5000000);
    ccity2->setwaterName("Atlantic Ocean");
    ccity2->setbeachNum(8);

    cout <<"ccityPtr2 used to call printInfo()" <<endl;
    cout << "Using -> syntax:" <<endl;
    ccity2->printInfo();

    cout << "Using * syntax:" << endl;
    (*ccity2).printInfo();

    cout<< "The address stored in ccityPtr2: " << ccity2 <<endl;
    
    return 0;
}