#include <iostream>
#include <list>
#include "city.h"

using namespace std;
const int SIZE = 5;

int a[SIZE] = {2,8,1,7,3};
City cityArray[SIZE] = {
    City("Los Angeles",4000000),
    City("San Diego",1500000),
    City("San Francisco",900000),
    City("Sacramento",500000),
    City("Stockton",300000)
};

list <int> intList;
list<City> cityList;

template <typename T>
void initList(list<T>& list, T arr[], int size) {
    for(int i = 0; i < size; ++i) {
        list.push_back(arr[i]);
    }
}

template <typename T>
void printList(list<T> list) {
    for(auto elements: list) {
        cout << elements << " ";
    }
    cout << endl;
}
void printCityList(list<City> list) {
    for(auto it = list.begin(); it != list.end(); ++it) {
        it->printInfo();
    }
    cout << endl;
}

// void printCityList(list<City> list) {
//     for(auto elements: list) {
//         elements.printInfo();
//     }
// }

template <typename T>
void rotateListRight(list<T>& list, int time) {
    for (int i = 0; i < time; ++i) {
        list.push_front(list.back());
        list.pop_back();
    }
}

template <typename T>
void rotateListleft(list<T>& list, int time) {
    for (int i = 0; i < time; ++i) {
        list.push_back(list.front());
        list.pop_front();
    }
}
//remove function can only remove the number in list, erase functioncan remove the iterator (position) 
void removeFromCityList(list<City>& list, string name) {
    for (auto it = list.begin(); it!=list.end();++it) {
        if( it->getName() == name) {
            list.erase(it);
            break;
        }
        
    }

}

void InsertToCityList(list<City>& list, City cityname, string name) {
    for (auto it = list.begin(); it!=list.end();++it) {
        if( it->getName() == name) {
            list.insert(it, cityname);
        }
    }
}

int main() {
    cout << "Initializing intList with a[]:" << endl;
    initList(intList, a, SIZE);
    printList(intList);

    cout << "Initializing cityList with cityArray[]:" << endl;
    initList(cityList, cityArray, SIZE);
    printCityList(cityList);

    cout <<"Rotating intList to right twice:" <<endl;
    rotateListRight(intList, 2);
    printList(intList);

    cout << "Rotating cityList to right once:" <<endl;
    rotateListRight(cityList,1);
    printCityList(cityList);

    cout <<"Rotating intList to left once:" <<endl;
    rotateListleft(intList,1);
    printList(intList);

    cout <<"Rotating cityList to left twice:" <<endl;
    rotateListleft(cityList,2);
    printCityList(cityList);

    cout << "Removing Sacramento from cityList:" << endl;
    removeFromCityList(cityList, "Sacramento");
    printCityList(cityList);


    cout << "Inserting Redding to cityList before Stockton:" <<endl;
    InsertToCityList(cityList, City("Redding", 90000), "Stockton");
    printCityList(cityList);

    return 0;
}