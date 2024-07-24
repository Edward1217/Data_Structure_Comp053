#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 5;
int a[SIZE] = {6, 10, -4, 11, -2};
char str[7] = {"Hello."};

vector <int> vec1;
vector <char> vec2;
template <typename TheType> 
    void reverseArray(TheType arr[], int size) {
        for (int i = 0; i < (size-1)/2; ++i) {
            swap(arr[i], arr[size-1-i]); 
        }
        
    }

template <typename TheType>
    void printArray(TheType arr[], int size) {
        for (int i = 0; i < size-1; ++i) {
            cout << arr[i] << ", ";
        }
        cout << arr[size-1];
    }

template <typename TheType>
    void initVector(vector<TheType> &vector, TheType arr[], int size ) {
        for (int i = 0; i < size; ++i) {
            vector.push_back(arr[i]);
        }
    }

template <typename TheType>
    void replaceLastThree(vector<TheType>& vector,TheType input1, TheType input2,TheType input3) {
        vector[vector.size()-3] = input1;
        vector[vector.size()-2] = input2;
        vector[vector.size()-1] = input3;
    }

template <typename TheType>
    void printVector(vector<TheType> vector) {
        for (int i = 0; i < vector.size()-1; ++i) {
            cout << vector[i] << ", ";
        }
        cout << vector[vector.size()-1];
    }

template <typename TheType>
class Comparable{
    public:
        Comparable(TheType item1, TheType item2) {
            this->item1 = item1;
            this->item2 = item2;
        }
       bool lt() {
        if (item1 < item2) {
            return true;
        }
        return false;
       }
       bool gt() {
        if (item1 > item2) {
            return true;
        }
        return false;
       }
       bool eq() {
        if (item1 == item2) {
            return true;
        }
        return false;
       }
       
    private:
        TheType item1;
        TheType item2;
};



int main() {
    cout << "Reverse a[]: " <<endl;
    reverseArray(a, SIZE);
    printArray(a, SIZE);
    cout << endl;

    cout << "Reverse str[]: "<< endl;
    reverseArray(str, 7);
    printArray(str, 7);
    cout << endl;

    cout << "Initialize vec1 according to a[]:";
    initVector(vec1, a, SIZE);
    printVector(vec1);
    cout << endl;

    cout << "Initialize vec2 according to str[]:";
    initVector(vec2,str, 7);
    printVector(vec2);
    cout << endl;

    cout <<"Replace last three elements of vec1 with 9, 0 , and 2:" << endl;
    replaceLastThree(vec1, 9,0,2);
    printVector(vec1);
    cout << endl;

    cout << "Replace last three elements of vec2 with ’f’, ’y’ , and ’o’:" <<endl;
    replaceLastThree(vec2, 'f','y','o');
    printVector(vec2);
    cout << endl;

    Comparable<int>  comp1(3,5);
    Comparable<char>  comp2('r','b');

    cout << "Is 1st component of comp1 less than 2nd component of it? ";
    cout <<comp1.lt();
    cout << endl;

    cout << "Is 1st component of comp2 equal to 2nd component of it? ";
    cout <<comp2.eq();
    cout <<endl;


    return 0;
}