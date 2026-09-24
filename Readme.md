# Lab 3: Dynamic Casting in C++

## Overview

This lab explores **dynamic casting** and **runtime type information (RTTI)** in C++. These are essential concepts for working with polymorphic types and performing safe type conversions at runtime.

## Topics Covered

### 1. Dynamic Casting (`dynamic_cast`)
- **Purpose**: Safely convert pointers/references of polymorphic types at runtime
- **Key Feature**: Returns `nullptr` if the cast is invalid (for pointers) or throws `std::bad_cast` (for references)
- **Requirements**: Base class must have at least one virtual function (typically the destructor)
- **Use Case**: Downcasting in a class hierarchy to access derived class functionality

### 2. Runtime Type Information (RTTI)
- **Mechanism**: Provides type information during program execution
- **Components**:
  - `typeid` operator: Returns type information as a `std::type_info` object
  - `std::type_info`: Contains type name and comparison operators
- **Purpose**: Determine the dynamic type of an object at runtime

### 3. Polymorphism
- **Base Class**: `Fruit` with virtual destructor (enables polymorphism)
- **Derived Classes**: `Apple` and `Orange` inherit from `Fruit`
- **Virtual Functions**: Enable runtime binding based on actual object type

### 4. Type Identification
- **`typeid` operator**: Returns the actual type of an object
- **Name Extraction**: The `name()` method returns an implementation-defined string representing the type
- **Comparison**: `type_info` objects can be compared using `==` and `!=` operators

## Code Structure

### Class Hierarchy (fruits.hh)
```
Fruit (base class)
├── Apple (derived class)
└── Orange (derived class)
```

### Key Files
- **fruits.hh**: Class declarations with virtual destructor
- **fruits.cc**: Class implementations
- **main.cpp**: Demonstrates dynamic casting and type identification

## Learning Objectives

1. Understand when and how to use `dynamic_cast` for safe type conversion
2. Learn to work with RTTI using the `typeid` operator
3. Recognize the importance of virtual functions for polymorphism
4. Practice safe downcasting in class hierarchies
5. Handle type information at runtime for debugging and type checking

## Important Notes

- **Performance**: `dynamic_cast` and RTTI have runtime overhead; use judiciously
- **Safety**: Always check the result of `dynamic_cast<Pointer>` against `nullptr`
- **Portability**: The string returned by `typeid(...).name()` is implementation-dependent
- **Virtual Destructor**: Required for proper polymorphic behavior and safe deletion

## Compilation

This lab requires a C++ compiler with RTTI support (enabled by default in most compilers).

```bash
# Compile with g++
g++ -std=c++11 -o demo main.cpp fruits.cc

# Run the program
./demo
```

## Expected Output

The program demonstrates:
1. Successful upcast from `Apple*` to `Fruit*`
2. Successful downcast from `Fruit*` back to `Apple*`
3. Failed downcast from `Fruit*` to `Orange*` (returns nullptr)
4. Type names for each variable using `typeid`
