#include <iostream>
#include <string>

class Person {
public:
    Person(const int a, const std::string& n) : age(a), name(n) {
    }

    int getAge() const { return age; }
    std::string getName() const { return name; }
    std::string toString() const {
       std::string data = name + ": " + std::to_string(age);
       return data;
    }
private:
    int age;
    std::string name;
};

void insertionSort(Person* theArray[], int n)
{
    for (int unsorted = 1; unsorted < n; unsorted++)
    {
        Person* nextItem = theArray[unsorted];
        int loc = unsorted;
        while ((loc > 0) && (theArray[loc - 1]->getAge() > nextItem->getAge())) {
            theArray[loc] = theArray[loc - 1];
            loc--;
        }
        theArray[loc] = nextItem;
        loc--;
    }
}

int main() {
    Person p1(50, std::string("Scott"));
    Person p2(30, std::string("Bill"));
    Person p3(40, std::string("Ted"));

    Person* people[] = {&p1, &p2, &p3};
    insertionSort(people, 3);

    std::cout << people[0]->toString() << std::endl;
    std::cout << people[1]->toString() << std::endl;
    std::cout << people[2]->toString() << std::endl;

    return 0;
}
