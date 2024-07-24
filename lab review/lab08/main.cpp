#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 10;
int a[] ={5, 7, -2, 8, 11, -9, 4, 6, 12, -1};
vector <int> vec1;

// for loop range can't use in array
void initVector(vector<int>& vector, int arr[], int size) {
    for(int i = 0; i < size; ++i) {
        vector.push_back(arr[i]);
    }
}

void printVector(vector <int> vector) {
    for(auto it = vector.begin(); it != vector.end()-1;++it) {
        cout <<*it <<", ";
    }
    cout << vector[vector.size()-1];
    cout << endl;
}

int minVector(vector <int> vector) {
    int minNum = vector[0];
    for(int elements:vector) {
        if(elements < minNum) {
            minNum = elements;
        }
    }
    return minNum;
}

int productVector(vector <int> vector) {
    int productNum = 1;
    for(int &elements:vector) {
        elements = elements*2;
    }
    return productNum;
}

void doubleVector(vector <int>& vector) {
    for(int& elements:vector) {
        elements = elements * 2;
    }
}

void aggregationVector(vector <int>& vector) {
    int firstNum = 0;
    for(int& elements:vector) {
        firstNum +=  elements;
        elements = firstNum;
    }
}
int main() {
    cout << "vec1 content: ";
    initVector( vec1, a,SIZE);
    printVector(vec1);

    cout <<"minimum of vec1: ";
    cout << minVector(vec1) <<endl;

    cout << "product of vec1: ";
    cout << productVector(vec1) <<endl;
    
    cout << "doubling each element of vec1: " ;
    doubleVector(vec1);
    printVector(vec1);

    cout <<"aggregating element values in vec1: ";
    aggregationVector(vec1);
    printVector(vec1);
    return 0;
}
