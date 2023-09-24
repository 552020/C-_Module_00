# C++ Module 00

## Exercises

## Exercise 00: Megaphone

### Exercise 01: My Awesome Phonebook

## Concepts

- _Namespace_ is a feature of C++ that allows to group identifiers (functions, variables, types) to avoid naming collisions. It is very similar to the scope of a function.

## The `std` namespace` and the C++ Standard Library

**std** is the namespace through which the components of the C++ Standard Library are made available.

The C++ Standard Library is a collection of utilities, in form of classes, functions, algoritms and other constructs.

The C++ Standard Library is not part of the C++ language but is mantained by the ISO C++ committee which is also responsible for the C++ language.

To use the `std` namespace and one of its components we need to include the appropriate header file from the Standard Library.

## Functions and objects

- **std::cout**
- **std::getline**
- **std::cin**

### std::cout

`std::cout` is an object of type `std::ostream` (output stream) that represents the standard output stream. It is defined in the <iostream> header.

`std::cout` is the most idiomatic and the most commonly used 'tool' for writing to the standard output. It replaces the `write` and `printf` C functions.

`std::out` is mostly used in combination with `<<`, the insertion operator (or stream insertion operator).

#### Notes on std::coun

- `printf` and `write` in C++
- `>>`

#### `printf` and `write` in C++

It is still possible to use `write` and `printf` in C++.

```c++

#include <cstdio> // or <stdio.h>

int main() {
    printf("Hello, world!\n");
    return 0;
}


```

```c++
#include <unistd.h>

int main() {
    const char *message = "Hello, world!\n";
    write(STDOUT_FILENO, message, 13);  // 13 is the length of the message
    return 0;
}


```

But note that `write` being POSIX-specific may not work on not Unix-like systems.

#### `<<` as Left Shift Operator, Insertion Operator and as heredoc

`<<` used in shell scripting to collect an heredoc in commands like `echo << EOF` is restricted to shell scripting and doesn't concern C or C++.
