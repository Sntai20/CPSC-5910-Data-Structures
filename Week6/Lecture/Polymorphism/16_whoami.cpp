#include <iostream>
using namespace std;

class One {
public:
  void whoami() { cout << "One" << endl; }
};

class Two: public One {
public:
  void whoami() { cout << "Two" << endl; }
};

class Three: public Two {
public:
  void whoami() { cout << "Three" << endl; }
};

int main() {
  One a;
  Two b;
  Three c;
  One * collection[3];
  One objectSlided[3];
  
  collection[0] = &a;
  collection[1] = &b;
  collection[2] = &c;
 
  objectSlided[0] = a;
  objectSlided[1] = b;
  objectSlided[2] = c;

  for (int i = 0; i < 3; i++)
    collection[i]->whoami();
  for (int i = 0; i < 3; i++)
    objectSlided[i].whoami(); 
}
