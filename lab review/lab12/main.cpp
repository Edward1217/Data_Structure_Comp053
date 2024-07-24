#include <vector>
#include<iostream>
#include"city.h"
using namespace std;

City cityArray[] = {
    City ("Los Angeles", 4000000),
    City ("San Diego", 1500000),
    City ("San Francisco", 900000),
    City ("Sacramento", 500000),
    City ("Stockton", 300000),
    City ("Redding", 90000),
    City ("Las Vegas", 700000),
    City ("Reno", 300000),
    City ("Portland", 700000),
    City ("Seattle", 7500000),
    City ("Eugene", 200000)
};

vector <City> cityvector;
int steps = 0;

void initVector(vector <City>& vector, City array[], int size ) {
    for (int i = 0; i < size; ++i) {
        vector.push_back(array[i]);
    }
}

void printCityVector(vector <City> vector) {
    for(auto elements:vector) {
        elements.printInfo();
    }
    cout << endl;
}

bool ascendingName (City i, City j) {
    return i.getName() < j.getName();
}

unsigned int cityLinearSearch(vector <City> vector, string name) { 
    for (auto elements:vector) {
        ++steps;
        if (elements.getName()== name) {
            return elements.getPopulation();
        }
    }
    return 0;
}

unsigned int cityBinarySearch(vector <City> vector, string name) {
    int firstPod = 0;
    int lastPod = vector.size()-1;
    
    while(firstPod <= lastPod) {
        ++steps;
        int midPod = (lastPod + firstPod)/2;
        if(vector[midPod].getName() < name) {
            firstPod = midPod +1;
        }
        else if(vector[midPod].getName() > name) {
            lastPod = midPod -1;
        }
        else {
            return vector[midPod].getPopulation();
        }
    }
    return 0;
}

int main() {
    cout << "Initializing cityVector with cityArray[]:" <<endl;
    initVector(cityvector,cityArray,11);
    printCityVector(cityvector);
    

    cout <<"Sorting cityVector based on names in ascending order:" <<endl;
    sort(cityvector.begin(), cityvector.end(), ascendingName);
    printCityVector(cityvector);

    cout << "Linear search for the population of San Francisco: " ;
    cout <<cityLinearSearch(cityvector, "San Francisco")<<endl;
    cout <<"Number of comparisons for this search: ";
    cout << steps <<endl;
    steps =0;

    cout <<"Linear search for the population of Boston: ";
    cout <<cityLinearSearch(cityvector, "Boston")<<endl;
    cout <<"Number of comparisons for this search: ";
    cout << steps <<endl;
    steps = 0;

    cout <<"Binary search for the population of San Francisco: ";
    cout << cityBinarySearch(cityvector, "San Francisco")<<endl;
    cout <<"Number of comparisons for this search: ";
    cout << steps <<endl;
    steps = 0;

    cout <<"Binary search for the population of Boston: ";
    cout << cityBinarySearch(cityvector, "Boston")<<endl;
    cout <<"Number of comparisons for this search: ";
    cout << steps <<endl;
    
    return 0;
}