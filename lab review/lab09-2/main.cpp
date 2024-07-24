#include <iostream>
#include <set>
#include <utility>
#include "city.h"

int a[] = {2,8,1,7,3};

City cityArray1[] = {  
  City("Los Angeles", 4000000), 
  City("San Diego", 1500000), 
  City("San Francisco", 900000), 
  City("Sacramento", 500000), 
  City("Stockton", 300000) 
};

City cityArray2[] = {  
  City("Redding", 90000), 
  City("Stockton", 300000), 
  City("Las Vegas", 700000), 
  City("Reno", 300000), 
  City("Portland", 700000),
  City("Sacramento", 500000),
  City("Eugene", 200000)
};

set<int> intSet;
set<City> citySet1;
set<City> citySet2;
set<City> citySet3;
set<string> cityNames;

template<typename T>
void initSet(set<T> &baseset , T arr[], int size) {
  for (int i = 0; i < size; i++) {
    baseset.insert(arr[i]);
  }
}

template<typename T>
void printSet(const set<T> baseset) {
  for (auto setElements : baseset) {
    cout << setElements << " ";
  }
  cout << endl << endl;
}

void printCitySet(const set<City> cityset) {
  for (auto setCityElements : cityset) {
    setCityElements.printInfo();
  }
  cout << endl;
}

void cityNameset(set<City> cityset, set<string>& nameset) {
    for (auto setCityElements : cityset) {
        nameset.insert(setCityElements.getName());
  }
}

template<typename T>
void setIntersection(set<T> set1, set<T> set2,set<T> &set3) {
    for (auto elements1:set1) {
        for(auto elements2:set2){
            if (elements1.getName() == elements2.getName()) {
                set3.insert(elements1);
            }
        }
    }
}

template<typename T>
void setUnion(set<T> set1, set<T> set2,set<T> &set3) {
    for (auto elements1:set1) {
        set3.insert(elements1);
    }
    for(auto elements2:set2) {
        set3.insert(elements2);
    }
}

template<typename T>
bool isSubset(set<T> set1, set<T> set2) {
    for(auto elements:set1) {
        if(set2.count(elements)==0) {
            return 0;
        }
    }
    return 1;
}

void removeFromCitySet(set<City> &set, string cityname) {
    for (auto element:set) {
        if (element.getName() == cityname) {
            set.erase(element);
        }
    }
}


int main() {
    cout << "Initializing intSet with a[]:" <<endl;
    initSet(intSet, a, 5);
    printSet(intSet);

    cout <<"Initializing citySet1 with cityArray1[]:" << endl;
    initSet(citySet1, cityArray1,5);
    printCitySet(citySet1);

    cout << "Initializing citySet2 with cityArray2[]:" <<endl;
    initSet(citySet2, cityArray2,7);
    printCitySet(citySet2);

    cout << "Populate cityNames according to the cities in citySet1:" <<endl;
    cityNameset(citySet1, cityNames);
    printSet(cityNames);

    cout << "Intersect citySet1 and citySet2, and store the result in citySet3:" <<endl;
    setIntersection(citySet1, citySet2, citySet3);
    printCitySet(citySet3);

    cout <<"Union citySet1 and citySet2, and store the result in citySet3:" <<endl;
    setUnion(citySet1, citySet2, citySet3);
    printCitySet(citySet3);

    cout << "citySet1 is a subset of citySet2? ";
    cout << isSubset(citySet1, citySet2) <<endl;
     
    cout << "citySet2 is a subset of citySet3? ";
    cout << isSubset(citySet2, citySet3) <<endl;

    cout << "Removing Sacramento from citySet1:" << endl;
    removeFromCitySet(citySet1, "Sacramento");
    printCitySet(citySet1);
    return 0;
}