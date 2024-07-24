#include <iostream>
#include <vector>
#include "city.h"

City cityArray[] = {
    City("Los Angeles", 4000000),
    City("San Diego", 1500000),
    City("San Francisco", 900000),
    City("Sacramento", 500000),
    City("Stockton", 300000),
    City("Redding", 300000),
    City("Las Vegas", 90000),
    City("Reno", 700000),
    City("Portland", 700000),
    City("Seattle", 750000),
    City("Eugene", 200000)
};

int gaps [] = {4,2,1};

vector<City> cityVector;
void initVector(City array[], vector<City>& newVector, int size) {
    for (int i = 0; i < size; ++i) {
        newVector.push_back(array[i]);
    }
}

void printCityVector(vector<City> newVector) {
    for (auto elements:newVector) {
        elements.printInfo();
    }
}

void cityInterleavedInsertionSort (vector<City>& newVector, int startIndex, int gap) {
    for (int i = startIndex+ gap; i < newVector.size(); i = i + gap) {
        int j = i;
        while(newVector[j-gap].getPopulation() > newVector[j].getPopulation() && j  >= startIndex) {
            swap(newVector[j-gap],newVector[j]);
            j = j - gap;
        }
    }
}

void cityShellSort (vector<City>& newVector, int gapsArray[], int gapSize) {
    for (int i = 0; i < gapSize; ++i) {
        for (int j = 0; j < gapsArray[i]; ++j) {
            cityInterleavedInsertionSort(newVector, j, gapsArray[i]);
        }
    }

}

int main() {
    cout << "Initializing cityVector with cityArray[]:" << endl;
    initVector(cityArray,cityVector,11 );
    printCityVector(cityVector);
    cout << endl;

    cout <<"Shell sort on cityVector:" <<endl;
    cityShellSort(cityVector,gaps,3);
    printCityVector(cityVector);
    return 0;
}
