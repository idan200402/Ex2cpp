//idan.shumski@gmail.com

#ifndef SQUAREMAT_HPP
#define SQUAREMAT_HPP

#include <iostream>
#include <stdexcept>
#include <cmath>
//header file for the class SquareMat , which represents a squared matrix.
//more specifically and detailed coommenting is done in the cpp file.
namespace ex2 {
class SquareMat {
private:
//the matrix has 2 attributes , the size of the matrix 
//and 2 dimensional array to store the values of the matrix.
    int size;
    double** matrix;

    //helper functions
    SquareMat getMinor(int row, int col) const;
    static SquareMat identity(int size);
    double sum() const;
public:
//constructor destructor
    SquareMat(int size);
    ~SquareMat();
//copy constructor and assignment operator
    SquareMat(const SquareMat& other);
    SquareMat& operator=(const SquareMat& other);
//setters and getters
    double get(int i, int j) const;
    void set(int i, int j, double value);
    void set(int i, int j);
//operators overloading
    SquareMat operator+(const SquareMat& other) const;
    SquareMat operator-(const SquareMat& other) const;
    SquareMat operator-() const;
    SquareMat operator*(double scalar) const;
    SquareMat operator*(const SquareMat& other) const;
    SquareMat operator/(double scalar) const;
    SquareMat operator%(const SquareMat& other) const;
    SquareMat operator%(int scalar) const;
    SquareMat operator^(int exponent) const;
    friend SquareMat operator*(double scalar, const SquareMat& mat);
    SquareMat& operator++();
    SquareMat& operator--();
    SquareMat operator++(int);
    SquareMat operator--(int);
    SquareMat& operator+=(const SquareMat& other);
    SquareMat& operator-=(const SquareMat& other);
    SquareMat& operator*=(double scalar);
    SquareMat& operator*=(const SquareMat& other);
    SquareMat& operator/=(double scalar);
    SquareMat& operator%=(int scalar);
    SquareMat& operator%=(const SquareMat& other);
    SquareMat& operator~(); // Transpose
    double operator!() const; // Determinant
    // Comparison Operators
    bool operator==(const SquareMat& other) const;
    bool operator!=(const SquareMat& other) const;
    bool operator<(const SquareMat& other) const;
    bool operator>(const SquareMat& other) const;
    bool operator<=(const SquareMat& other) const;
    bool operator>=(const SquareMat& other) const;
    //creating two subclasses to implement the [][] operator.
//the first one is for the const row to read only.
//the second one is for the non const row to modify the values eg.
//mat[0][0] = 5;
    class NonConstRow {
    private:
        double* rowPointer; // pointer to the i-th row
    public:
        NonConstRow(double* rowPointer);
        double& operator[](int j);
    };
    class ConstRow {
    private:
        const double* rowPointer;   
    public:
        ConstRow(const double* rowPointer);
        const double& operator[](int j) const;
    };
    NonConstRow operator[](int i);
    ConstRow operator[](int i) const;
    //overloading the << operator to print the matrix.
    friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);
};
}
#endif
