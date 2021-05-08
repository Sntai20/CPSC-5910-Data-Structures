#include <iostream>
#include <string>

class Person {
public:
    Person(std::string name = "", int age = 0) : m_name(name), m_age(age ) { }
    std::string getName() const { return m_name; }
    int getAge() const { return m_age; }
private:
    std::string m_name;
    int m_age;
};

// BaseballPlayer publicly inheriting Person
class BaseballPlayer : public Person {
public:
    BaseballPlayer(std::string name = "", 
                    int age = 0,
                    double battingAverage = 0.0, 
                    int homeRuns = 0)
            : Person(name, age), // call Person(std::string, int) to initialize these fields
              m_battingAverage(battingAverage), 
              m_homeRuns(homeRuns) { }
    double getBattingAverage() const { return m_battingAverage; }
    int getHomeRuns() const { return m_homeRuns; }
private:
    double m_battingAverage;
    int m_homeRuns;
};

int main() {
    BaseballPlayer pedro("Pedro Cerrano", 32, 0.342, 42);
    std::cout << pedro.getName() << '\n';
    std::cout << pedro.getAge() << '\n';
    std::cout << pedro.getHomeRuns() << '\n';

    // ALSO: Use a base class pointer that points to an instance of the derived class.
    Person * person = &pedro;
    std::cout << person->getAge() << std::endl;

    return 0;
}

// OUTPUT
// Pedro Cerrano
// 32
// 42
