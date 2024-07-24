#include"state.cpp"
#include <iostream>
int main () {
State state;
string stateName;
  
cout << "state: ";
cin >> stateName;
cout << "The state has the following cities/populations:" << endl;

state.readStateCities();
cout << "The state " << stateName << " has the following cities/populations: " << endl;
state.printStateCities();

return 0;
}