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

void mergeCityVector(vector <City>& cityVector, int i, int j, int k) {
    int leftPod = i;
    int rightPod = j+1;
    //int midPod = 0;

    vector<City> newVector;

    while (leftPod <= j && rightPod <= k) {
        if(cityVector[leftPod].getPopulation() < cityVector[rightPod].getPopulation()){
            newVector.push_back(cityVector[leftPod]);
            ++leftPod;
        }
        else{
            newVector.push_back(cityVector[rightPod]);
            ++rightPod;
        }
        while(leftPod <= j) {
            newVector.push_back(cityVector[leftPod]);
            ++leftPod;
        }
        while(rightPod <= k) {
            newVector.push_back(cityVector[rightPod]);  
            ++rightPod;
        }
    }
    for (int idx = 0; idx < newVector.size();++idx) {
        cityVector[idx+i] = newVector[idx];
    }
}

void cityMergeSort(vector <City>& cityVector, int i, int k) {
    int j =0;
    if (i <k) {
        j = (i +k) /2;
        cityMergeSort(cityVector, i, j);
        cityMergeSort(cityVector, j+1, k);
        mergeCityVector(cityVector, i, j, k);
    }
}

int main() {
    cout << "Initializing cityVector with cityArray[]:" <<endl;
    initVector(cityVector, cityArray, 11);
    printCityVector(cityVector);

    cout << "Merge sort on cityVector:" <<endl;
    cityMergeSort(cityVector, 0, 10);
    printCityVector(cityVector);

    return 0;
}