#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "squareMat.hpp"
#include <iostream>
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

TEST_CASE("Constructor and Destructor") {
    SUBCASE("Valid size") {
        CHECK_NOTHROW(SquareMat mat(3));
        //check if the matrix is initialized to 0s.
        SquareMat mat(2);
        for(int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                CHECK(mat.get(i, j) == 0);
            }
        }
    }
    SUBCASE("Invalid size") {
        CHECK_THROWS([]() {
            SquareMat mat(0);
        }());
        CHECK_THROWS([]() {
            SquareMat mat(-1);
        }());
    }
    SUBCASE("Copy Constructor") {
        SquareMat mat1(3);
        mat1.set(0, 0, 1);
        mat1.set(1, 1, 2);
        mat1.set(2, 2, 3);
        SquareMat mat2(mat1);
        CHECK(mat2.get(0, 0) == 1);
        CHECK(mat2.get(1, 1) == 2);
        CHECK(mat2.get(2, 2) == 3);
        //check if the matrix that copied is not altered when the original matrix is altered.
        mat1.set(0, 0, 4);
        CHECK(mat2.get(0, 0) == 1);
    }
    SUBCASE("Assignment Operator") {
        SquareMat mat1 = createMatrix(3);
        SquareMat mat2(4);
        //assaign mat1 to mat2 even if mat2 is not the same size.
        mat2 = mat1;
        CHECK(mat2 == mat1);
    }
    SUBCASE("Destructor") {
        SquareMat* mat = new SquareMat(3);
        CHECK_NOTHROW(delete mat);
    }

}
TEST_CASE("Setters and Getters") {
    SUBCASE("Set and Get") {
        SquareMat mat = createMatrix(2);
    mat.set(0, 0, 5);
    CHECK(mat.get(0, 0) == 5);
    CHECK_THROWS(mat.set(2, 2, 5));
    CHECK_THROWS(mat.get(2, 2)); 
    CHECK_THROWS(mat.set(-1, -1, 5));
    }
    SUBCASE("checking the [] operator") {
        SquareMat mat = createMatrix(2);
        mat[0][0] = 5;
        CHECK(mat[0][0] == 5);
        CHECK_THROWS(mat[-1][-1] = 5);
        CHECK_THROWS(mat[2][2] = 5);
        CHECK(mat[0][0] ==mat.get(0, 0));
        CHECK(mat[0][1] == 2);
    }

}
TEST_CASE(" Arithmetic operations") {
    SUBCASE("Addition") {
        SquareMat mat1 = createMatrix(2);
        SquareMat mat2 = createMatrix(2);
        SquareMat result = mat1 + mat2;
        CHECK(result.get(0, 0) == 2);
        CHECK(result.get(1, 1) == 8);
    }
    SUBCASE("Subtraction") {
        SquareMat mat1 = createMatrix(2);
        SquareMat mat2 = createMatrix(2);
        SquareMat result = mat1 - mat2;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                CHECK(result.get(i, j) == 0);
            }
        }
        SquareMat mat3 = createMatrix(3);
        CHECK_THROWS(mat1 - mat3);
    }
    SUBCASE("Negation") {
        SquareMat mat = createMatrix(2);
        SquareMat result = -mat;
        CHECK(result.get(0, 0) == -1);
        CHECK(result.get(1, 1) == -4);
    }
    SUBCASE("Scalar Multiplication") {
        SquareMat mat = createMatrix(2);
        SquareMat result = mat * 2;
        CHECK(result.get(0, 0) == 2);
        CHECK(result.get(1, 1) == 8);
        CHECK(result == 2 * mat);
        CHECK(result == mat +mat);
    }
    SUBCASE("Matrix Multiplication") {
        SquareMat mat1 = createMatrix(2);
        SquareMat mat2 = createMatrix(2);
        SquareMat mat3 = createMatrix(3);
        SquareMat result = mat1 * mat2;
        CHECK(result[0][0] == 7);
        CHECK(result[1][1] == 22);
        CHECK_THROWS(mat1 * mat3);  
    }
    SUBCASE("Matrix Modulo with scalar") {
        SquareMat mat1 = createMatrix(3);
        SquareMat result = mat1 % 2;
        CHECK(result[0][0] == 1);
        CHECK(result[0][1] == 0);
        CHECK(result[2][2] == 1);
        CHECK_THROWS(mat1 % 0);
        CHECK_THROWS(mat1 % -1);
    }
    SUBCASE("Matrix Modulo (multiplication) with another matrix") {
        SquareMat mat1 = createMatrix(3);
        SquareMat mat2 = createMatrix(3);
        SquareMat result = mat1 % mat2;
        CHECK(result[0][0] == 1);
        CHECK(result[1][1] == 25);
        CHECK(result[2][2] == 81);
    }
    SUBCASE("Matrix Division") {
        SquareMat mat1 = createMatrix(2);
        SquareMat result = mat1 / 2;
        CHECK(result[0][0] == 0.5);
        CHECK(result[1][1] == 2);
        CHECK_THROWS(mat1 / 0);
    }
    SUBCASE("Matrix Exponentiation") {
        SquareMat mat1 = createMatrix(2);
        SquareMat result = mat1 ^ 2;
        CHECK(result[0][0] == 7);
        CHECK(result[1][1] == 22);
        CHECK_THROWS(mat1 ^ -1);
    }

          
} 
    
    
