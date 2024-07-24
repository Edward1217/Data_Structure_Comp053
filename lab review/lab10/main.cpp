#include<queue>
#include<deque>
#include<algorithm>
#include<iostream>
#include "city.h"
using namespace std;

City cityArray[] = {
    City("Los Angeles", 4000000),
    City("San Diego", 1500000),
    City("San Francisco", 900000),
    City("Sacramento", 500000),
    City("Stockton", 300000)
};

queue<City> cityQueue;
deque<City> cityStack;
vector<City> cityVector;

void initQueue(queue<City>& queue, City array[], int size) {
    for (int i = 0; i < size;++i) {
        queue.push(array[i]);
    }
}

void printCityQueue(queue<City>& queue) {
    while(queue.size()>0){
        queue.front().printInfo();
        queue.pop();
    }

}

void initStack(deque<City>& stack, City array[], int size) {
    for(int i = 0; i < size; ++i) {
        stack.push_front(array[i]);
    }
}

void printCityStack(deque<City>& stack) {
    while(stack.size() >0) {
        stack.front().printInfo();
        stack.pop_front();
    }
}

void initVector(vector<City>& vector, City array[], int size) {
    for(int i = 0; i < size; ++i) {
        cityVector.push_back(array[i]);
    }
}

void printCityVector(vector<City> vector) {
    for(auto elements: vector) {
        elements.printInfo();
    }
}

bool sortDescendingName(City i, City j) {
    return i.getName() > j.getName();
}

bool sortDescendingPop(City i, City j) {
    return i.getPopulation() > j.getPopulation(); 
}

int main() {
    cout <<"Initializing cityQueue with cityArray[]:" <<endl;
    initQueue(cityQueue,cityArray,5);
    printCityQueue(cityQueue);
    cout <<endl;

    cout << "Initializing cityStack with cityArray[]:" <<endl;
    initStack(cityStack, cityArray,5);
    printCityStack(cityStack);
    cout <<endl;

    cout << "Initializing cityVector with cityArray[]:" <<endl;
    initVector(cityVector,cityArray, 5);
    printCityVector(cityVector);
    cout <<endl;

    cout << "Sorting cityVector based on names in descending order:" <<endl;
    sort(cityVector.begin(), cityVector.end(), sortDescendingName);
    printCityVector(cityVector);
    cout <<endl;

    cout <<"Sorting cityVector based on populations in ascending order:" <<endl;
    sort(cityVector.begin(), cityVector.end(),sortDescendingPop);
    printCityVector(cityVector);
    cout <<endl;
    
    return 0;
}

