# C++ Module 00

## Exercises

### Exercise 00: Megaphone

#### Headers

- Headers vs libraries

In C++, the terms "library" and "header" are often used interchangeably, but more precisely, iostream is a header file that is part of the C++ Standard Library. The library includes not just iostream but also other components for various functionalities, such as containers, algorithms, and strings.

- iostream

<iostream>: This header file is used for input and output operations in C++. The program uses it for writing to the standard output (console) using **std::cout** and for manipulating the output (like inserting line breaks) using **std::endl**. iostream in C++ serves a similar purpose to stdio.h in C, in that both are used for input and output operations. However, they represent two different programming paradigms: stdio.h follows a procedural approach typical of C, using functions like printf and scanf, while iostream uses an object-oriented approach, utilizing obje

<string>: This header includes the definition of the **std::string** class, which is a part of the C++ Standard Library.

<cctype>: This includes functions to perform character classification and conversion. In your program, std::toupper is used, which is a function to convert a character to uppercase if possible. It is included in this header.

#### std::string vs `char *`

std::string is a much more user-friendly and safer alternative to C-style strings (`char *`). It provides automatic memory management and many member functions for string manipulation.

In C strings are handled as arrays of characters, in C++ we use a 'class'

In C, strings are handled as arrays of characters terminated by a null character (\0). This approach does not provide built-in safety or convenience features, and operations like concatenation, comparison, or length calculation require explicit function calls (strcat, strcmp, strlen, etc.).

In C++, std::string is indeed a class provided by the C++ Standard Library (<string> header), making strings first-class citizens of the language. A std::string object encapsulates not only the character data but also provides numerous member functions for manipulating string data, such as adding to a string, comparing strings, accessing characters, and more. This is a significant abstraction over C-style strings, offering both safety (e.g., automatic memory management) and convenience (e.g., easy concatenation).

We have different ways to declare a string in C++.

`std::string myString = "Hello, String!"`

`std::string str(argv[i]);` // Initializes `str` with the contents of `argv[i]`

#### methods vs functions

- .length() is a **method** of the `std::string`` class. In C we normally use strlen to define the length of a string, in C++ in str string class we have a method ad hoc that gives back the size of the string.

- std::toupper() is not a **method** but a function, which takes as argument a char and returns the uppercase equivalent if it is lowercase.

#### Write a Nnw line in C++

1. std::endl
   Description: std::endl is an I/O manipulator used with output streams like std::cout. It performs two actions: it inserts a newline character into the output stream, and then it flushes the stream.
   Usage: std::cout << "Hello, World!" << std::endl;
   Implications: Because it flushes the stream, using std::endl can be slightly less efficient than other methods if used repeatedly in a tight loop, due to the overhead of flushing. However, it's useful for ensuring that the output is immediately visible, especially in interactive programs or when debugging.

2. Newline Character ('\n')
   Description: The newline character ('\n') can be inserted directly into the output stream. It only inserts a newline without flushing the stream.
   Usage: std::cout << "Hello, World!\n";
   Implications: This method is more efficient than std::endl if many lines are being written in a loop because it avoids the overhead of flushing the stream after each line. However, the output may not appear immediately on the console in some buffering scenarios.

3. std::flush
   Description: While not directly a method for writing a newline, std::flush is used to flush the stream without inserting any characters.
   Usage: std::cout << "Hello, World!\n" << std::flush;
   Implications: This allows you to control when the stream is flushed. It's useful if you want to manually manage when the buffer is cleared, for instance, after writing several lines of output with '\n'.

C 4. Platform-Specific Newline Sequences
Description: Depending on the platform, the actual character sequence used to represent a newline might differ (e.g., "\r\n" on Windows vs. "\n" on Unix/Linux). C++ abstracts this away by using '\n' in your code, but when writing to files in text mode, the C++ runtime will convert '\n' to the platform-specific newline sequence.
Usage: Same as the newline character; the distinction is handled automatically.

### Exercise 01: My Awesome Phonebook

- What is a class?
- What is an object?
- How to define a class?
- Header files and implementation files

"Write class names in UpperCamelCase format. Files containing class code will
always be named according to the class name. For instance:
ClassName.hpp/ClassName.h, ClassName.cpp, or ClassName.tpp. Then, if you
have a header file containing the definition of a class "BrickWall" standing for a
brick wall, its name will be BrickWall.hpp."

## Concepts

- _OOP_ [Object Oriented Programming](https://en.wikipedia.org/wiki/Object-oriented_programming)

- _Namespace_ is a feature of C++ that allows to group identifiers (functions, variables, types) to avoid naming collisions. It is very similar to the scope of a function.

## The `std` namespace` and the C++ Standard Library

**std** is the namespace through which the components of the C++ Standard Library are made available.

The C++ Standard Library is a collection of utilities, in form of classes, functions, algoritms and other constructs.

The C++ Standard Library is not part of the C++ language but is mantained by the ISO C++ committee which is also responsible for the C++ language.

To use the `std` namespace and one of its components we need to include the appropriate header file from the Standard Library.

## std::cout << "Hello World!";

`<<` In the context of `std::cout`, the `<<` operator is an overloaded operator that serves as an **insertion operator**, not a bit shift operator. It is used to insert data into the output stream. This operator is overloaded to accept various types of data, including primitive types and objects like std::string.

## std:endl

std::endl is an I/O manipulator used with std::cout to insert a newline character into the output stream and flush the stream. It's more than just a simple newline because of the flushing operation, which ensures that all output is written to the destination immediately.

## Functions and objects

- **std::cout**
- **std::getline**
- **std::cin**

### std::cout

`std::cout` is an object of type `std::ostream` (output stream) that represents the standard output stream. It is defined in the <iostream> header.

`std::cout` is the most idiomatic and the most commonly used 'tool' for writing to the standard output. It replaces the `write` and `printf` C functions.

`std::cout` is mostly used in combination with `<<`, the insertion operator (or stream insertion operator).

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
