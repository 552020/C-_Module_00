# Namespace

## Definition

We can define a namespace with the `namespace` keyword. Inside the namespace we then define the members of that namespace.

```c++

namespace MyNamespace
{
	int myFunction()
		return 42;
	char myChar = 'a';
}

```

## Access

Is it possible to access the members of a namespace (outside the namespace) using the **scope resolution operator** `::`.

```c++
int result = MyNamespace::myFunction;
```

```c++
#include <iostream>

namespace MyNamespace
{
	int myFunction()
		return 42;
	char myChar = 'a';
}

int main()
{
	int result = MyNamespace::myFunction;
	std::cout << result << std::endl;
	std::cout << MyNamespace::myChar << std::endl;

}
```

It is possible to make a namespace 'implicit' with the use of the keyword `using` followed by the identifier of the namespace.

```c++
using namespace MyNamespace;
int result = myFunction(); // instead of MyNamespace::myFunction
```

But if we have a function 'myFunction' declared in the global scope the compiler will throw an error.

```c++

#include <iostream>

namespace MyNamespace {
    void myFunction() {
        std::cout << "Inside MyNamespace" << std::endl;
    }
}

void myFunction() {
    std::cout << "Inside global scope" << std::endl;
}

int main() {
    using namespace MyNamespace;

    myFunction();
}

```

## Naming

Namespaces' identifiers are lowercase or CamelCase.
