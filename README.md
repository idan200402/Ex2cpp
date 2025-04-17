Ex2 in System Programming Cousre
=========================
Overview:
This repository contains the solution to Exercise 2 of the System Programming course. In this excercise ,we had to implement a Square Matrix class , testing it with doctests and check memory leaks using valgrind. The class is implemented in C++ and includes implementation of the rule of three ,  matrix arithmetic operations , scalar operations , matrix transposition , determinant calculation and more. As mentioned , every method and function is tested using doctests. 

Features:
- implenetation of the rule of three:
  - Copy constructor
  - Copy assignment operator
  - Destructor
- Matrix with matrix arithmetic operations:
    - Addition
    - Subtraction
    - Multiplication
    - stright multiplication (%).
- Matrix with scalar operations:
    -multiplication
    - addition
    -modulus
    -exponentiation
- Transpose
- Determinant calculation
-Postfix and prefix increment and decrement operators.
- Comperison operators
-Output operator
-Exception handling for example:
    - operations on two matrices of different sizes.
    -division by zero.
    -out of bounds access.
    -and more.

Files:
- `SquareMatrix.h`: header file for the SquareMatrix class, containing the class definition and method signatures.
- `SquareMatrix.cpp`: implementation file for the SquareMatrix class.
- `main.cpp`: main file for demonstration for the SquareMatrix class and its methods.
- `test.cpp`: file containing doctests for the SquareMatrix class and its methods.
- `Makefile`: file for building the project (test.cpp, main.cpp, valgrind). 

Requirements:
- C++11.
- Doctest library for testing.
- Valgrind for memory leak checking.

Building and Running:
1. to run the main file: make Main
2. to run the tests: make test
3. to check for memory leaks: make valgrind

Author:
Idan Shumski 325693422
idan.shumski@gmail.com


