#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 10;
int a[SIZE] = {5, 7, -2, 8, 11, -9, 4, 6, 12, -1};
int b[SIZE] = {4, 16, 9, -2, 1, 1, -2, 9, 16, 4};

vector <int> vec1;
vector <int> vec2;
vector <int> vec3;

void initVector(int arr[], vector <int> &vector, int size){
    for(int i = 0; i < size; ++i) {
        vector.push_back(arr[i]);
    }
}

void printVector (vector <int> vector) {
    for(int i = 0; i < vector.size()-1; ++i) {
        cout << vector[i] << ", ";
    }
    cout << vector[vector.size()-1];
}

int minVector(vector <int> vector) {
    int minNum = vector[0];
    for(int i = 1; i < vector.size()-1; ++i) {
        if (vector[i] < minNum) {
            minNum = vector[i];
        }
    }
    return minNum;
}

int productVector(vector <int> vector) {
    int productNum = 1;
    for(int i = 0; i < vector.size(); ++i) {
        productNum *= vector[i];
    }
    return productNum;
} 

void copyVector(vector <int> vector1, vector <int>& vector2) {
    vector2 = vector1;
}

void greaterVector (vector <int> vector1, vector <int> vector2, vector<int>& vector3) {
    for (int i = 0; i < vector1.size(); ++i) {
        if (vector1[i] > vector2[i]) {
            vector3[i] = vector1[i];
        }
        if (vector2[i] > vector1[i]) {
            vector3[i] = vector2[i];
        }
    }
}

bool isPalindrome(vector <int> vector) {
    int i = 0;
    int j = vector.size() -1 ;

    while (i< j) {
        if (vector[i] == vector[j]) {
            ++i;
            --j;
        }
        else {
            return false;
        }
    }
    return true;
}

void updateLast(vector <int>& vector, int data) {
    vector[vector.size()-1] = data;
}

int main() {
    cout << "initial size of vec1: " ;
    cout << vec1.size() << endl;

    cout << "size of vec1 after initialization: ";
    initVector( a, vec1,SIZE);
    cout << vec1.size() << endl;

    cout << "vec1 content: ";
    printVector(vec1);
    cout << endl;

    cout << "vec2 content: ";
    initVector( b, vec2,SIZE);
    printVector(vec2);
    cout << endl;

    cout << "minimum of vec1: ";
    cout << minVector(vec1) << endl;
    
    cout << "product of vec1: ";
    cout << productVector(vec1) << endl;

    cout << "copy vec1 to vec3: ";
    copyVector(vec1, vec3);
    printVector(vec3);
    cout << endl;

    cout << "collect larger elements from vec1 and vec2 to vec3: ";
    greaterVector(vec1, vec2, vec3);
    printVector(vec3);
    cout << endl;

    if (isPalindrome(vec1) == true) {
        cout << "vec1 is Palindrome" << endl;
    }
    else {
        cout << "vec1 is not Palindrome" << endl;
    }

    if (isPalindrome(vec2) == true) {
        cout << "vec2 is Palindrome" << endl;
    }
    else {
        cout << "vec2 is not Palindrome" << endl;
    }

    cout << "Updating the last element of vec3: ";
    updateLast(vec3, 7);
    printVector(vec3);
    cout << endl;
    return 0;
}