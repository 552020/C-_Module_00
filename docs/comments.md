## Comments

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

### Exercise 02: The Job of your dreams

We need to reconstruct the lost Account.cpp file.
We have three files:

- Account.hpp
- tests.cpp
- 19920104_091532.log

`tests.cpp` containes the main function and creates the log file. It uses the Account class as defined in the .hpp file, but the implementation of the functions are missing.

#### Account.hpp

##### `#pragma once`

- `#pragma once` is a **preprocessor directive** that ensures the header file where it's placed is included only once in a single compilation unit, regardless of how many times it has been imported with `#include`. This directive is widely supported by most modern C++ compilers as a more convenient alternative to include guards, though it's not officially part of the C++ standard.

`pragma` is a/the preprocessor keyword in both C and C++.
`once` is not a keyword by itself; it is an argument or directive that is used with the #pragma keyword.

##### Include Guards (`#ifndef`, `#define`, `#endif`)

- `#ifndef __ACCOUNT_H__` checks if the macro `__ACCOUNT_H__` has not been defined earlier in the current compilation unit. If it hasn't, the compiler proceeds with the compilation of the content enclosed between `#ifndef` and `#endif`.
- `#define __ACCOUNT_H__` then defines the macro `__ACCOUNT_H__` to prevent the content of the header file from being included again in the same compilation unit. This is necessary because without it, if the header file is included multiple times, the compiler would process its contents each time, leading to multiple definitions of the same classes, functions, etc.
- The header file ends with an `#endif` directive, which marks the end of the conditional compilation started by `#ifndef`. This ensures that the content of the header file is processed only once per compilation unit, even if it's included multiple times.

##### Combining Both Methods

The use of both `#pragma once` and include guards together in the same header file is somewhat redundant, as they serve the same purpose. However, this practice can be seen in codebases aiming for compatibility with a wide range of compilers and build environments, including those where `#pragma once` might not be supported. Generally, `#pragma once` is preferred for its simplicity and efficiency, but include guards (`#ifndef`, `#define`, `#endif`) are universally supported and considered the standard approach by the ISO C++ guidelines.

##### `#include <vector>`

The line `#include <vector>` in a C++ program is a preprocessor directive that includes the header file for the `std::vector` container class from the C++ Standard Library.

The name "vector" in the context of the C++ Standard Library refers to a **dynamic array-like container** that can grow and shrink in size. The term "vector" itself originates from mathematics and physics, where it represents a quantity that has both magnitude and direction. However, in the realm of computer science and programming, the term has been adopted to describe a sequence of elements that can be accessed in a linear fashion, much like an array.

The choice of the name "vector" for this C++ container might be somewhat metaphorical, suggesting a direction (forward sequence of elements) and magnitude (size of the container). It's worth noting that while the mathematical concept of a vector includes direction, the C++ std::vector does not inherently include the notion of direction in the same sense; instead, it emphasizes linear sequence and dynamic resizing capabilities.

C++ is not necessarily the first programming language to use the term "vector," but it is among the languages that popularized the concept of vectors as dynamic array-like containers through its Standard Library. The term "vector" has been used in various contexts and languages with different meanings. For example, Lisp, a much older programming language, uses the term "vector" to refer to a one-dimensional array with a fixed size, highlighting how the interpretation of "vector" can vary significantly between languages.

The std::vector in C++ abstracts and automates several operations that you could manually implement in C or even in C++ without using std::vector. The functionality of dynamically resizing an array, which involves allocating a new, larger array, copying the existing elements to the new array, and then deallocating the old array, is a common requirement in many programming tasks. std::vector encapsulates this process, making it more convenient and less error-prone for developers.

The use of headers without the .h suffix in C++ serves to distinguish them from C headers and to highlight their use of C++-specific features like namespaces and templates. This naming convention is a deliberate design choice to signify the evolution from C to C++, promoting cleaner, namespace-aware, and template-based coding practices.

##### What is `std::vector`?

- **Container Type**: `std::vector` is a sequence container that encapsulates dynamic size arrays. Unlike static arrays, the size of a `std::vector` can change dynamically, with the container automatically managing the storage.
- **Header File**: The `vector` header file defines the `std::vector` class template.
- **Namespace**: It is part of the `std` namespace, hence referred to as `std::vector`.
- **Usage**: Vectors are used to store a collection of elements of the same type. They provide random access to elements, which means you can access any element in constant time using an index. Vectors also allow adding and removing elements at the end in amortized constant time.

##### Features of `std::vector`

- **Dynamic Array**: Automatically resizes itself to accommodate new elements or to shrink when elements are removed.
- **Memory Management**: Manages its own memory allocation and deallocation, providing a simple and efficient way to use dynamic arrays without directly dealing with memory management.
- **Random Access**: Elements can be accessed directly by their position index, similar to arrays.
- **Efficiency**: Provides efficient insertion and deletion at the end. However, inserting or deleting elements at positions other than the end can be less efficient because it may require elements to be shifted.

##### Example Usage of `std::vector`

```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> myVector;

    // Add elements to the vector
    myVector.push_back(10);
    myVector.push_back(20);

    // Access and print elements
    for(int i = 0; i < myVector.size(); i++) {
        std::cout << myVector[i] << std::endl;
    }

    return 0;
}
```

##### Arrays vs Vectors in C++

#### Account.cpp

This section of code in the `_displayTimestamp` function serves to obtain the current time, format it, and output it in a specific format. Let's break down each function and component involved:

##### 1. `std::time()`

- **Functionality**: `std::time(nullptr)` retrieves the current time as a `std::time_t` object. The argument `nullptr` indicates that we're not providing a storage location for the time; instead, we're just getting the current time as a return value.
- **Return Value**: The current time since the Epoch (00:00:00 UTC on 1 January 1970), measured in seconds.

##### 2. `std::localtime(&currentTime)`

- **Functionality**: `std::localtime` converts a `std::time_t` object into a `std::tm` structure representing local time.
- **Argument**: `&currentTime` is the address of the `std::time_t` object holding the time value returned by `std::time()`.
- **Return Value**: A pointer to a `std::tm` structure filled with the local time corresponding to the `std::time_t` value.

##### 3. `std::setfill()`

- **Functionality**: `std::setfill('0')` sets the fill character for the output stream to '0'. This means that when the output width (set by `std::setw`) is greater than the number of characters to be printed, the extra space will be filled with '0'.
- **Usage**: It's used here to ensure that all parts of the timestamp are zero-padded to maintain the correct format, especially for single-digit months, days, hours, minutes, and seconds.

##### 4. `std::setw`

- **Functionality**: `std::setw(n)` sets the width of the next output field to `n` characters. It ensures that the output occupies at least `n` characters, which, combined with `std::setfill('0')`, ensures proper zero-padding.
- **Usage**: It's used multiple times to format the date and time components of the timestamp, ensuring a consistent field width.

##### 5. LocalTime Object (`std::tm *localTime`)

- **Description**: `localTime` is a pointer to a `std::tm` structure that represents the local time broken down into its components (year, month, day, hour, minute, second, etc.).
- **Components Usage**:
  - `localTime->tm_year + 1900`: Years since 1900, so adding 1900 gives the actual year.
  - `localTime->tm_mon + 1`: Months since January, ranging from 0 to 11, so adding 1 gives the 1-based month.
  - `localTime->tm_mday`: Day of the month (1-31).
  - `localTime->tm_hour`, `localTime->tm_min`, `localTime->tm_sec`: Hour (0-23), minute (0-59), and second (0-59).

##### Is This the Easiest Way to Achieve the Format `[19920104_091532]`?

From a didactical perspective, this method effectively demonstrates the use of standard C++ library functions to manipulate dates and times, and format output. However, for beginners or those seeking simplicity, this approach might seem complex due to the direct manipulation of C-style date and time structures and formatting operations.

An alternative, more modern approach might involve using the C++11 (or later) `<chrono>` library along with `<iomanip>` for formatting. However, without direct formatting facilities for date and time in `<chrono>` prior to C++20, the use of third-party libraries or manual formatting (as shown) would still be necessary.

In C++20, the introduction of the `<chrono>` library's calendar and timezone features significantly simplifies working with dates and times, including formatting. Yet, the approach shown remains a valid and educational method for understanding and using C++'s date and time capabilities prior to C++20.

## Concepts

- _OOP_ [Object Oriented Programming](https://en.wikipedia.org/wiki/Object-oriented_programming)

- _Namespace_ is a feature of C++ that allows to group identifiers (functions, variables, types) to avoid naming collisions. It is very similar to the scope of a function.

### The `std` namespace` and the C++ Standard Library

**std** is the namespace through which the components of the C++ Standard Library are made available.

The C++ Standard Library is a collection of utilities, in form of classes, functions, algoritms and other constructs.

The C++ Standard Library is not part of the C++ language but is mantained by the ISO C++ committee which is also responsible for the C++ language.

To use the `std` namespace and one of its components we need to include the appropriate header file from the Standard Library.

### std::cout << "Hello World!";

`<<` In the context of `std::cout`, the `<<` operator is an overloaded operator that serves as an **insertion operator**, not a bit shift operator. It is used to insert data into the output stream. This operator is overloaded to accept various types of data, including primitive types and objects like std::string.

### std:endl

std::endl is an I/O manipulator used with std::cout to insert a newline character into the output stream and flush the stream. It's more than just a simple newline because of the flushing operation, which ensures that all output is written to the destination immediately.

### Functions and objects

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
