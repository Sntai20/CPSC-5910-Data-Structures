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

template <class Item, class KeyType>
void insertionSort(Item* theArray[], int n, KeyType extractor(Item*))
{
    for (int unsorted = 1; unsorted < n; unsorted++)
    {
        Item* nextItem = theArray[unsorted];
        int loc = unsorted;
        while ((loc > 0) && (extractor(theArray[loc - 1]) > extractor(nextItem))) {
            theArray[loc] = theArray[loc - 1];
            loc--;
        }
        theArray[loc] = nextItem;
        loc--;
    }
}

int extractAge(Person* person) {
    return person->getAge();
}

std::string extractName(Person* person) {
    return person->getName();
}

int main() {
    Person p1(50, std::string("Scott"));
    Person p2(30, std::string("Bill"));
    Person p3(40, std::string("Ted"));

    Person* people[] = {&p1, &p2, &p3};
    insertionSort<Person, int>(people, 3, extractAge);

    std::cout << people[0]->toString() << std::endl;
    std::cout << people[1]->toString() << std::endl;
    std::cout << people[2]->toString() << std::endl;
    std::cout << std::endl;

    insertionSort<Person, std::string>(people, 3, extractName);

    std::cout << people[0]->toString() << std::endl;
    std::cout << people[1]->toString() << std::endl;
    std::cout << people[2]->toString() << std::endl;
    std::cout << std::endl;

    return 0;
}
