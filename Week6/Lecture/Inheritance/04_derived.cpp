#include <iostream>
 
class Base {
public:
    int m_id;
    Base(int id = 0) : m_id(id) { std::cout << "Base\n"; }
    int getId() const { return m_id; }
};
 
class Derived: public Base {
public:
    double m_cost;
    Derived(double cost = 0.0) : m_cost(cost) { std::cout << "Derived\n"; }
    double getCost() const { return m_cost; }
};
 
int main() {
    std::cout << "Instantiating Base" << std::endl;
    Base cBase; 
    std::cout << "Instantiating Derived" << std::endl;
    Derived cDerived;
    return 0;
}

// OUTPUT
// Instantiating Base
// Base
// Instantiating Derived
// Base
// Derived


/*
 * Derived is really two parts: a Base part, and a Derived part. When C++ 
 * constructs derived objects, it does so in phases. First, the most-base class 
 * (at the top of the inheritance tree) is constructed first. Then each child 
 * class is constructed in order, until the most-child class (at the bottom of 
 * the inheritance tree) is constructed last.
 *
 * So when we instantiate an instance of Derived, first the Base portion of 
 * Derived is constructed (using the Base default constructor). Once the Base 
 * portion is finished, the Derived portion is constructed (using the Derived 
 * default constructor). At this point, there are no more derived classes, 
 * so we are done.
 */
