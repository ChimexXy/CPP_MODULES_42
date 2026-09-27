# CPP Modules 42

A collection of C++ exercises completed as part of the **42 School C++ Modules**.

This repository contains implementations and exercises from **CPP Module 00 through CPP Module 09**, covering the fundamentals of C++ and progressively introducing object-oriented programming, inheritance, exceptions, casting, templates, STL containers, and algorithms.

---

## Table of Contents

* [About](#about)
* [Modules](#modules)
* [Module Overview](#module-overview)
* [Technologies](#technologies)
* [Compilation](#compilation)
* [Makefile Commands](#makefile-commands)
* [Project Structure](#project-structure)
* [C++ Concepts Covered](#c-concepts-covered)
* [Learning Progression](#learning-progression)
* [Testing](#testing)
* [Repository](#repository)
* [Author](#author)

---

## About

The **C++ Modules** are a series of 42 School exercises designed to introduce C++ programming progressively.

The modules start with basic C++ syntax and object-oriented programming and gradually move toward more advanced concepts such as:

* Classes and objects
* Encapsulation
* Constructors and destructors
* References
* Pointers
* Inheritance
* Polymorphism
* Abstract classes
* Exceptions
* Type casting
* Templates
* STL containers
* Iterators
* Algorithms
* Advanced sorting techniques

Each exercise is organized independently and generally contains its own `Makefile`.

---

# Modules

The repository contains:

```text
cpp_00
cpp_01
cpp_02
cpp_03
cpp_04
cpp_05
cpp_06
cpp_07
cpp_08
cpp_09
```

The progression is:

```text
CPP 00
  ↓
CPP 01
  ↓
CPP 02
  ↓
CPP 03
  ↓
CPP 04
  ↓
CPP 05
  ↓
CPP 06
  ↓
CPP 07
  ↓
CPP 08
  ↓
CPP 09
```

---

# Module Overview

## CPP 00 — Introduction to C++

Introduces the basic syntax and programming style of C++.

### Exercises

* `ex00` — **Megaphone**
* `ex01` — **PhoneBook**
* `ex02` — **Account**

### Main concepts

* C++ compilation
* `std::cout` / `std::cin`
* Strings
* Classes
* Objects
* Private/public members
* Member functions
* Basic encapsulation
* `static` members

---

## CPP 01 — Memory Allocation and References

Introduces dynamic memory management and references.

### Exercises

* `ex00` — Zombie
* `ex01` — Zombie Horde
* `ex02` — Brain
* `ex03` — HumanA / HumanB / Weapon
* `ex04` — Sed
* `ex05` — Harl
* `ex06` — Harl Filter

### Main concepts

* Stack vs heap allocation
* `new` and `delete`
* References
* Pointers
* Constructors and destructors
* File streams
* Member functions
* Function pointers
* Dynamic object creation

Example concepts:

```cpp
Zombie* zombie = newZombie("Foo");

zombie->announce();

delete zombie;
```

---

## CPP 02 — Orthodox Canonical Form and Fixed-Point Numbers

Focuses on class design and operator overloading.

### Exercises

* `ex00` — Fixed-point class
* `ex01` — Fixed-point conversions
* `ex02` — Fixed-point arithmetic and comparisons

### Main concepts

* Orthodox Canonical Form
* Constructors
* Copy constructor
* Copy assignment operator
* Destructor
* Operator overloading
* Fixed-point representation
* Conversion between types
* Comparison operators
* Arithmetic operators
* Increment/decrement operators

The canonical class structure includes:

```cpp
Class();
Class(const Class& other);
Class& operator=(const Class& other);
~Class();
```

---

## CPP 03 — Inheritance

Introduces inheritance and class hierarchies.

### Exercises

* `ex00` — ClapTrap
* `ex01` — ScavTrap
* `ex02` — FragTrap
* `ex03` — DiamondTrap

### Main concepts

* Inheritance
* Base classes
* Derived classes
* Constructor/destructor order
* Multiple inheritance
* Virtual inheritance
* Method overriding
* Protected members

The exercises progressively build a hierarchy around the `ClapTrap` class.

---

## CPP 04 — Polymorphism

Focuses on runtime polymorphism and abstract classes.

### Exercises

* `ex00` — Animal
* `ex01` — Brain
* `ex02` — Abstract Animal

### Main concepts

* Polymorphism
* Virtual functions
* Virtual destructors
* Abstract classes
* Pure virtual functions
* Deep copying
* Dynamic allocation
* Class hierarchies

A typical polymorphic hierarchy:

```text
Animal
├── Cat
└── Dog
```

The module also introduces the importance of using virtual destructors when deleting derived objects through base-class pointers.

---

## CPP 05 — Exceptions and Form Classes

Introduces exception handling and increasingly complex class relationships.

### Exercises

* `ex00` — Bureaucrat
* `ex01` — Form
* `ex02` — Concrete forms
* `ex03` — Intern

### Main concepts

* Exceptions
* `try`
* `catch`
* `throw`
* Nested classes
* Exception classes
* Form validation
* Class interaction
* Factory-like object creation

Example:

```cpp
try
{
    Bureaucrat bureaucrat("Moad", 1);
}
catch (std::exception& e)
{
    std::cerr << e.what() << std::endl;
}
```

---

## CPP 06 — C++ Casts

Focuses on the different casting mechanisms available in C++.

### Exercises

* `ex00` — ScalarConverter
* `ex01` — Serializer
* `ex02` — Base

### Main concepts

* `static_cast`
* `reinterpret_cast`
* `dynamic_cast`
* Type identification
* Pointer conversion
* Reference conversion
* Serialization
* Runtime type identification

The module explores how C++ handles conversions between different types and class hierarchies.

---

## CPP 07 — Templates

Introduces function and class templates.

### Exercises

* `ex00` — `whatever`
* `ex01` — `iter`
* `ex02` — `Array`

### Main concepts

* Function templates
* Class templates
* Generic programming
* Template instantiation
* Iterating over generic data
* Template exceptions
* Dynamic arrays

Example:

```cpp
template <typename T>
void swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}
```

---

## CPP 08 — STL Containers

Introduces the Standard Template Library and container-oriented programming.

### Exercises

* `ex00` — `easyfind`
* `ex01` — `Span`
* `ex02` — `MutantStack`

### Main concepts

* STL containers
* Iterators
* `std::vector`
* `std::list`
* `std::stack`
* Algorithms
* Iterator ranges
* Container manipulation
* Exception handling with containers

Example:

```cpp
std::vector<int> numbers;
numbers.push_back(10);
numbers.push_back(20);
```

---

## CPP 09 — Advanced Algorithms and Containers

The final module focuses on practical use of STL containers and algorithms.

### Exercises

* `ex00` — Bitcoin Exchange
* `ex01` — Reverse Polish Notation
* `ex02` — PmergeMe

### Main concepts

* `std::map`
* `std::stack`
* `std::vector`
* `std::deque`
* Parsing
* File processing
* Reverse Polish Notation
* Algorithmic complexity
* Sorting algorithms
* Ford-Johnson / merge-insert sorting
* Container performance comparison

### Bitcoin Exchange

Processes historical Bitcoin exchange-rate data using associative containers.

### RPN

Evaluates mathematical expressions written in **Reverse Polish Notation**.

Example:

```text
8 9 * 9 - 9 - 9 - 4 - 1 +
```

### PmergeMe

Implements and compares a sorting algorithm using different STL containers.

The project uses:

```text
std::vector
std::deque
```

and measures their execution times.

---

# Technologies

| Technology  | Usage                              |
| ----------- | ---------------------------------- |
| C++         | Main programming language          |
| C++98       | Required language standard         |
| Make        | Build system                       |
| STL         | Standard containers and algorithms |
| Git         | Version control                    |
| Linux/macOS | Development environment            |

The exercises use the C++98 standard.

Typical compiler flags used throughout the repository are:

```text
-Wall -Wextra -Werror -std=c++98
```

---

# Compilation

Each exercise is an independent project with its own `Makefile`.

First, enter the exercise directory:

```bash
cd cpp_modules/cpp_00/ex00
```

Then compile:

```bash
make
```

The executable name depends on the exercise.

For example:

```bash
cd cpp_modules/cpp_00/ex00
make
./megaphone
```

Another example:

```bash
cd cpp_modules/cpp_09/ex02
make
./PmergeMe
```

---

# Makefile Commands

Most exercises provide the standard Makefile targets.

### Build

```bash
make
```

### Remove object files

```bash
make clean
```

### Remove object files and executable

```bash
make fclean
```

### Full rebuild

```bash
make re
```

Typical structure:

```make
all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
```

---

# Project Structure

The repository is organized by module and exercise:

```text
CPP_MODULES_42/
│
└──cpp_modules/
│   │
│   ├── cpp_00/
│   │   ├── ex00/
│   │   └── ex01/
│   │
│   ├── cpp_01/
│   │   ├── ex00/
│   │   ├── ex01/
│   │   ├── ex02/
│   │   ├── ex03/
│   │   ├── ex04/
│   │   └── ex05/
│   │
│   ├── cpp_02/
│   │   ├── ex00/
│   │   ├── ex01/
│   │   └── ex02/
│   │
│   ├── cpp_03/
│   │   ├── ex00/
│   │   ├── ex01/
│   │   └── ex02/
│   │
│   ├── cpp_04/
│   │   ├── ex00/
│   │   ├── ex01/
│   │   ├── ex02/
│   │   └── ex03/
│   │
│   ├── cpp_05/
│   │   ├── ex00/
│   │   ├── ex01/
│   │   ├── ex02/
│   │   └── ex03/
│   │
│   ├── cpp_06/
│   │   ├── ex00/
│   │   ├── ex01/
│   │   └── ex02/
│   │
│   ├── cpp_07/
│   │   ├── ex00/
│   │   ├── ex01/
│   │   └── ex02/
│   │
│   ├── cpp_08/
│   │   ├── ex00/
│   │   ├── ex01/
│   │   └── ex02/
│   │
│   └── cpp_09/
│       ├── ex00/
│       ├── ex01/
│       └── ex02/
│
└── .vscode/
```

---

# C++ Concepts Covered

The repository provides a progression through many core C++ concepts.

### Fundamentals

* C++ syntax
* Streams
* Strings
* Classes
* Objects
* Encapsulation
* Member functions

### Memory

* Stack allocation
* Heap allocation
* `new`
* `delete`
* Pointers
* References
* Deep copies

### Object-Oriented Programming

* Constructors
* Destructors
* Copy constructors
* Assignment operators
* Inheritance
* Multiple inheritance
* Polymorphism
* Virtual functions
* Abstract classes

### Operators

* Operator overloading
* Comparison operators
* Arithmetic operators
* Increment/decrement operators
* Assignment operators

### Error Handling

* Exceptions
* `try`
* `catch`
* `throw`
* Custom exception classes

### Type System

* `static_cast`
* `dynamic_cast`
* `reinterpret_cast`
* Runtime type identification
* Serialization

### Generic Programming

* Function templates
* Class templates
* Generic algorithms

### STL

* `std::vector`
* `std::list`
* `std::stack`
* `std::deque`
* `std::map`
* Iterators
* Generic algorithms

### Algorithms

* Searching
* Sorting
* Parsing
* Reverse Polish Notation
* Merge-insert sorting
* Complexity analysis

---

# Learning Progression

The modules form a progressive learning path:

```text
             C++ Basics
                 │
                 ▼
        Classes & Objects
                 │
                 ▼
       Memory & References
                 │
                 ▼
      Operator Overloading
                 │
                 ▼
            Inheritance
                 │
                 ▼
           Polymorphism
                 │
                 ▼
            Exceptions
                 │
                 ▼
             C++ Casts
                 │
                 ▼
             Templates
                 │
                 ▼
          STL Containers
                 │
                 ▼
       Advanced Algorithms
```

By the end of the modules, the exercises have moved from simple classes to programs using generic programming, STL containers, parsing, and algorithmic optimization.

---

# Testing

Each exercise should be tested independently.

A typical workflow is:

```bash
cd cpp_modules/cpp_XX/exYY
make
./program
```

Clean the compiled files afterward:

```bash
make fclean
```

For exercises involving invalid input, exceptions, parsing, or edge cases, test both valid and invalid cases.

For algorithmic exercises such as `PmergeMe`, test:

* Small input
* Large input
* Already sorted input
* Reverse-sorted input
* Duplicate values when applicable
* Invalid values
* Boundary cases

---

# Repository

GitHub:

https://github.com/ChimexXy/CPP_MODULES_42

---

# Author

**Moad Zahnoun**

42 School / 1337

---

# License

This repository was created for educational purposes as part of the **42 School curriculum**.
