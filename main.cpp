#include <iostream>
#include <stdexcept>
#include <cmath>
#include "squareMat.hpp"
using namespace ex2;
int main(){
    SquareMat mat(2);
    mat[0][0] = 1;
    mat[0][1] = 2;
    mat[1][0] = 3;
    mat[1][1] = 4;
    std::cout << "Matrix:" << std::endl;
    std::cout << mat << std::endl;
    SquareMat mat2(2);
    mat2[0][0] = 1;
    mat2[0][1] = 0;
    mat2[1][0] = 0;
    mat2[1][1] = 1;
    std::cout << "Matrix 2:" << std::endl;
    std::cout << mat2 << std::endl;
    SquareMat result = mat * mat2;
    std::cout << "Result of multiplication:" << std::endl;
    std::cout << result << std::endl;
    SquareMat mat3(3);
    mat3[0][0] = 1;
    mat3[0][1] = 2;
    mat3[0][2] = 3;
    mat3[1][0] = 4;
    mat3[1][1] = 5;
    mat3[1][2] = 6;
    mat3[2][0] = 7;
    mat3[2][1] = 8;
    mat3[2][2] = 9;
    try{
        std::cout << "Matrix 3:" << std::endl;
        std::cout << mat3 << std::endl;
        SquareMat result2 = mat * mat3; // This should throw an exception
        std::cout << "Result of multiplication:" << std::endl;
        std::cout << result2 << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    double det = !mat;
    std::cout << "Determinant of matrix 1: " << det << std::endl;
    mat += mat2;
    std::cout << "Result of addition:" << std::endl;
    std::cout << mat << std::endl;
}