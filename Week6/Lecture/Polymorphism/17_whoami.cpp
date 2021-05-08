#include <iostream>
using namespace std;

class One {
public:
  virtual void whoami() { cout << "One" << endl; }
};

class Two: public One {
public:
  virtual void whoami() { cout << "Two" << endl; }
};

class Three: public Two {
public:
  virtual void whoami() { cout << "Three" << endl; }
};

int main() {
  One a;
  Two b;
  Three c;
  One * collection[3];
  Two * childCollect[2];
  
  collection[0] = &a;
  collection[1] = &b;
  collection[2] = &c;
 
  childCollect[0] = &b;
  childCollect[1] = &c;

  for (int i = 0; i < 3; i++)
    collection[i]->whoami();
  for (int i = 0; i < 2; i++)
    childCollect[i]->whoami(); 
}
