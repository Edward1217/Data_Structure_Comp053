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

int cityPartition(vector <City>& cityVector, int i, int h) {
    bool done = false;
    int mid = i + (h - i)/2;
    unsigned int pivot = cityVector[mid].getPopulation();
    while(!done) {
        while(cityVector[i].getPopulation() < pivot) {
            ++i;
        }
        while(cityVector[h].getPopulation() > pivot) {
            --h;
        }

        if (i >= h) {
            done = true;
        }
        else {
            swap(cityVector[i],cityVector[h]);
            ++i;
            --h;
        }
    }
    return h;
}

void cityQuickSort(vector <City>& cityVector,int i,int h) {
    
    if (i >= h) {
        return;
    }
    int j = cityPartition(cityVector,i,h);
    cityQuickSort(cityVector, i, j);
    cityQuickSort(cityVector, j+1, h);
}


int main() {
    cout << "Initializing cityVector with cityArray[]:" <<endl;
    initVector(cityVector, cityArray, 11);
    printCityVector(cityVector);

    cout <<"Quick sort on cityVector:" <<endl;
    cityQuickSort(cityVector, 0,10);
    printCityVector(cityVector);

    return 0;
}