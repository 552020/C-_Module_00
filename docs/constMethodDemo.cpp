#include <iostream>
#include <string>

class Person {
private:
    std::string first_name;

public:
    Person(const std::string& name) : first_name(name) {}

    std::string getFirstName() const {
        // first_name = "Changed";  // Uncommenting this would produce a compile-time error
        return first_name;
    }
};

int main() {
    Person john("John");
    std::cout << "John's first name: " << john.getFirstName() << std::endl;

    Person alice("Alice");
    std::cout << "Alice's first name: " << alice.getFirstName() << std::endl;

    return 0;
}

