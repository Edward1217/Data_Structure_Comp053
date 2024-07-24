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
    City ("Seattle", 750000),
    City ("Eugene", 200000)
};

vector <City> cityVector;

void initVector(vector <City>& cityVector, City array[], int size) {
    for(int  i = 0; i < size; ++i) {
        cityVector.push_back(array[i]);
    }
}

void printCityVector(vector <City> cityVector) {
    for(auto elements: cityVector) {
        elements.printInfo();
    }
    cout << endl;
}

void citySelectionSort(vector <City>& cityVector) {
    for (int i = 0; i < cityVector.size()-1; ++i) {
        int smallestIndex = i;
        for(int j = i +1; j < cityVector.size(); ++j) {
            if(cityVector[j].getPopulation() < cityVector[smallestIndex].getPopulation()) {
                smallestIndex = j;
            }
        }
        swap(cityVector[i],cityVector[smallestIndex]);
    }
}

void cityInsertionSort(vector <City>& cityVector) {
    for(int i = 1; i < cityVector.size(); ++i) {
        int j = i;
        while(cityVector[j].getPopulation() < cityVector[j-1].getPopulation() && j > 0) {
            swap(cityVector[j], cityVector[j-1]);
            --j;
        }

    }

}

int main() {
    cout <<"Initializing cityVector with cityArray[]:" <<endl;
    initVector(cityVector, cityArray, 11);
    printCityVector(cityVector);

    cout <<"Selection sort on cityVector:" <<endl;
    citySelectionSort(cityVector);
    printCityVector(cityVector);
    cityVector.clear();

    cout <<"Re-initializing cityVector with cityArray[]:" <<endl;
    initVector(cityVector, cityArray, 11);
    cityInsertionSort(cityVector);
    printCityVector(cityVector);
    return 0;
}