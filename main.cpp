//idan.shumski@gmail.com
#include <iostream>
#include <stdexcept>
#include <cmath>
#include "squareMat.hpp"
using namespace ex2;
SquareMat createMatrix(int size) {
    SquareMat mat(size);
    int counter = 1;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            mat.set(i, j, counter++);
        }
    }
    return mat;
} 
int main(){
    SquareMat mat1 = createMatrix(2);
    std::cout << "Matrix 1:" << std::endl;
    std::cout << mat1<< std::endl;
    SquareMat mat2 = createMatrix(2);
    mat2[1][1] = 5;
    std::cout << "Matrix 2:" << std::endl;
    std::cout << mat2<< std::endl;
    SquareMat addition = mat1 + mat2;
    SquareMat subtraction = mat1 - mat2;
    SquareMat multiplication = mat1 * mat2;
    std::cout << "When mentioning the matrix 1 and 2 we mean their original values." << std::endl;
    std::cout << "lets see the addition , subtraction and multiplication of the two matrices:(to see all the arrthmetics run make test)" << std::endl;
    std::cout << "Addition:" << std::endl;
    std::cout << addition << std::endl;
    std::cout << "Subtraction:" << std::endl;
    std::cout << subtraction << std::endl;
    std::cout << "Multiplication:" << std::endl;
    std::cout << multiplication << std::endl;
    SquareMat scalarMultiplication = mat1 * 2;
    std::cout << "Scalar Multiplication:" << std::endl;
    std::cout << scalarMultiplication << std::endl;
    SquareMat temp = mat1;
    std::cout << "Matrix 1 after prefix incrementation:" << std::endl;
    std::cout << ++mat1 << std::endl;
    std::cout << "Matrix 1 after postfix incrementation(should be the original values):" << std::endl;
    std::cout << temp++ << std::endl;
    std::cout << "Matrix 1 after transposition:" << std::endl;
    mat1--;
    std::cout << ~mat1 << std::endl;
    std::cout << "Lets calculate the determinant of the matrices:" << std::endl;
    SquareMat mat3 = createMatrix(2);
    std::cout << "Matrix 1 determinant: " <<!mat3<< std::endl;
    std::cout << "Matrix 2 determinant: " <<!mat2<< std::endl;

    std::cout << "Now lets do some invalid operations:" << std::endl;
    std::cout << "Exponentiation with negative number:" << std::endl;
    try {
        SquareMat result = mat1 ^ -2;
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "Subtraction of two matrices with different sizes:" << std::endl;
    SquareMat mat4 = createMatrix(3);
    try {
        SquareMat result = mat1 - mat4;
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "out of bounds access:" << std::endl;
    try {
        std::cout << mat1[2][2] << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "Now lets do +=, -=, *=, /= and %= operations: for this part every operation is for the previos result , operation chaining " << std::endl;
    SquareMat mat5 = createMatrix(2);
    SquareMat mat6 = createMatrix(2);
    std::cout << "Matrix 5 and Mat 6:" << std::endl;
    std::cout << mat5 << std::endl;
    std::cout << mat6 << std::endl;
    mat5 += mat6;
    std::cout << "Matrix 5 after addition of mat 6:" << std::endl;
    std::cout << mat5 << std::endl;
    mat5 -= mat6;
    std::cout << "Matrix 5 after subtraction of mat 6:" << std::endl;
    std::cout << mat5 << std::endl;
    mat5 *= mat6;
    std::cout << "Matrix 5 after multiplication of mat 6:" << std::endl;
    std::cout << mat5 << std::endl;
    mat5 /= 9;
    std::cout << "Matrix 5 after division with 9" << std::endl;
    std::cout << mat5 << std::endl;
    mat5 %= mat6;
    std::cout << "Matrix 5 after modulo (strictly multiplication) of mat 6:" << std::endl;
    std::cout << mat5 << std::endl;
    mat5 %= 2;
    std::cout << "Matrix 5 after mod 2:" <<std::endl;
    std::cout << mat5 << std::endl; 
    std::cout << "Thank you for reading! , if you would want to see all the operations implemented run make test" << std::endl;
    return 0;
}