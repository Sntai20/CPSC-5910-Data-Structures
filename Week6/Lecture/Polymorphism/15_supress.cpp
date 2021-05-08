#include <iostream>
using namespace std;

class Diva {
public:
    virtual void sing() { cout << "Diva sing\n"; }
    virtual void hum() { cout << "Diva hum\n"; }
};

class Shy: public Diva {
public:
    virtual void hum() { cout << "Shy hum\n"; }
private:
    virtual void sing() { cout << "Shy sing\n"; } // suppressed
};

int main() {
    Diva b;
    Shy d;

    cout << "Diva functions(b)\n";
    b.sing();
    b.hum();
    cout << "Shy functions(d)\n";
    // d.sing(); 	// this is private and cannot be directly called
    d.hum();

    Diva* bPtr = &b;
    cout << "Diva functions(Diva* bPtr = &b)\n";
    bPtr->sing();
    bPtr->hum();

    bPtr = &d;    
    cout << "Shy functions(bPtr = &d)\n";                              
    bPtr->sing();    
    bPtr->hum(); 
  
    return 0;
}

// OUTPUT
// Diva functions(b)
// Diva sing
// Diva hum
// Shy functions(d)
// Shy hum
// Diva functions(Diva* bPtr = &b)
// Diva sing
// Diva hum
// Shy functions(bPtr = &d)
// Shy sing
// Shy hum

