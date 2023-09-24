#include <iostream>

namespace MyNamespace {
void myFunction() { std::cout << "Inside MyNamespace" << std::endl; }
} // namespace MyNamespace

void myFunction() { std::cout << "Inside global scope" << std::endl; }

int main() {
  using namespace MyNamespace;

  myFunction(); // This wildl be ambiguous!
}

// namespaceAmbiguity.cpp:12:3: error: call to 'myFunction' is ambiguous
//   myFunction(); // This will be ambiguous!
//   ^~~~~~~~~~
// namespaceAmbiguity.cpp:4:6: note: candidate function
// void myFunction() { std::cout << "Inside MyNamespace" << std::endl; }
//      ^
// namespaceAmbiguity.cpp:7:6: note: candidate function
// void myFunction() { std::cout << "Inside global scope" << std::endl; }
//      ^
// 1 error generated.