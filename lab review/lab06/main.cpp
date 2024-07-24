#include <iostream>
using namespace std;

const int SIZE = 10;
int a[SIZE] = {5, 7, -2, 8, 11, -9, 4, 6, 12, -1};
int b[SIZE] = {4, 16, 9, -2, 1, 14, -4, 8, 10, 0};
int c[SIZE] ={};

void printArray(int arr[], int size) {
    for (int i = 0; i < size-1; ++i) {
        cout << arr[i] << ", ";
    }
    cout << arr[size-1];
}

int minArray(int arr[], int size) {
    int minNum = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minNum) {
            minNum = arr[i];
        }
    }
    return minNum;
}

int maxArray(int arr[], int size) {
    int MaxNum = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > MaxNum) {
            MaxNum = arr[i];
        }
    }
    return MaxNum;
}

int sumArray(int arr[], int size) {
    int sumNum = 0;
    for (int i = 0; i < size; i++) {
        sumNum += arr[i];
    }
    return sumNum;
}

int productArray(int arr[], int size) {
    int productNum = 1;
    for (int i = 0; i < size; ++i) {
        productNum *= arr[i];
    }
    return productNum;
}

void copyArray(int arr1[], int arr2[],int size) {
    for (int i = 0; i < size; ++i) {
        arr2[i] = arr1[i];
    }

}

void greaterArray(int arr1[], int arr2[],int arr3[], int size) {
    for (int i = 0; i < size; ++i) {
        if (arr1[i] > arr2[i]) {
            arr3[i] = arr1[i];
        }
        if (arr2[i] > arr1[i]) {
            arr3[i] = arr2[i];
        }
    }
}

int main() {
    cout << "minimum of a[]: " ;
    cout << minArray(a, SIZE) << endl;

    cout << "maximum of a[]: " ;
    cout << maxArray(a, SIZE) << endl;

    cout << "sum of a[]: ";
    cout << sumArray(a, SIZE) << endl;

    cout << "product of a[]: ";
    cout << productArray(a, SIZE) << endl;

    copyArray(a, c, SIZE);
    cout << "copy a[] to c[]: ";
    printArray(c, SIZE);
    cout << endl;

    cout << "collect larger elements from a[] and b[] to c[]: " ;
    greaterArray(a,b,c, SIZE);
    printArray(c, SIZE);
    cout << endl;
    
    return 0;
}