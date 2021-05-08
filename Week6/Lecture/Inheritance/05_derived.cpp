#include <iostream>

class Base {
public:
    Base(int id=0) : m_id(id) { }
    int getId() const { return m_id; }
private: 
    int m_id; // our member is now private
};

class Derived: public Base { 
public:
    Derived(double cost=0.0, int id=0)
        : Base(id), // Call Base(int) constructor with value id!
          m_cost(cost) { }
    double getCost() const { return m_cost; }
private: // our member is now private
    double m_cost;
};
 
int main() {
    Derived derived(1.3, 5); // use Derived(double, int) constructor
    std::cout << "Id: " << derived.getId() << '\n';
    std::cout << "Cost: " << derived.getCost() << '\n';
    return 0;
}

// OUTPUT
// Id: 5
// Cost: 1.3
