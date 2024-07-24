#include <iostream>
using namespace std;

int a [] = {2,8,1,7,3};
int b [5] ={};

void printArray(int a[], int size, int index) {
    if (index < size) {
        cout << a[index] << " ";
        ++index;
        printArray(a,size,index);
    }
}

void printReverseArray(int a[], int start, int end) {
    if(start >= 0) {
        cout << a[start] << " ";
        --start;
        printReverseArray(a,start,end);
    }
}

void reverseArray(int a[], int start, int end) {
    if(start <= end) {
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        reverseArray(a, start+1, end-1);
    }
}

int sumArray(int a[], int size, int index) {
    if (index >= size) {
        return 0;  
    }
    int numSum = a[index] + sumArray(a, size, index+1);
    return numSum;
}

int productArray(int a[], int size, int index) {
    if (index >= size) {
        return 1;
    }
    int numProduct = a[index] * productArray(a, size, index+1);
    return numProduct;
}

int minArray(int a[], int size, int index) {
    if (index >= size) {
        return a[0];
    }
    return min(a[index],minArray(a,size,index+1));
    
}

int maxArray(int a[], int size, int index) {
    if (index >= size) {
        return a[0];
    }
    return max(a[index],maxArray(a,size,index+1));
}

int main() {
    cout << "Array a[] content in order:" << endl;
    printArray(a, 5, 0);
    cout << endl;

    cout << "Array a[] content in reverse:" <<endl;
    printReverseArray(a,4,0);
    cout <<endl;

    cout <<"Reversing a[]:" <<endl;
    reverseArray(a,0,4);
    printArray(a, 5, 0);
    cout << endl;

    cout << "Summation of elements in a[]:"<<endl;
    cout << sumArray(a,5,0) << endl;

    cout <<"Product of elements in a[]:" <<endl;
    cout << productArray(a,5,0) << endl;

    cout <<"Copying a[] to b[]:" <<endl;
    for(int i = 0;i <5; ++i) {
        b[i] = a[i];
    }
    printArray(b, 5, 0);
    cout <<endl;

    cout << "Minimum element in a[]:" <<endl;
    cout << minArray(a, 5,0) <<endl;

    cout << "Maximum element in a[]:"<<endl;
    cout <<maxArray(a, 5,0) <<endl;
    return 0;
}