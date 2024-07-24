#include <iostream>
#include <string>

using namespace std;
  class State {
    public:
      State();
      void setName(string nameState) {
        name = nameState;
      } 
      void setPopulation (int popNum) {
        population = popNum;
      }
      string getName() const {
        return name;
      }
      int getPopulation() const {
        return population;
      }
      void printSize() const;
    private:
      string name;
      int population;
      string size() const;
  };

State::State() {
  name = "N/A";
  population = 0;
}
string State::size() const {
  if (population >1000000) {
    return "small";
  }
  else if (population >1000000 && population <5000000) {
    return "medium";
  }
  return "large";
}
void State::printSize() const{
  cout << name << ": " << population << endl;
}
int main() {
  State state1;
  state1.printSize();
  state1.setName("California");
  state1.setPopulation(40000000);
  state1.printSize();
  return 0;
}