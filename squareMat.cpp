//idan.shumski@gmail.com

#include <iostream>
#include <stdexcept>
#include <cmath>
#include "squareMat.hpp"
namespace ex2{
//helper function to extract the minor.
SquareMat SquareMat::getMinor(int row, int col) const {
    SquareMat minor(size - 1);
    int k = 0;
    for (int i = 0; i < size; ++i) {
        if (i == row) continue;
        int l = 0;
        for (int j = 0; j < size; ++j) {
            if (j == col) continue;
            minor.matrix[k][l] = matrix[i][j];
            l++;
        }
        k++;
    }
    return minor;
}
//helper function to make the identity matrix for complex operations.
SquareMat SquareMat::identity(int size) {
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == j) {
                result.matrix[i][j] = 1;
            } else {
                result.matrix[i][j] = 0;
            }
        }
    }
    return result;
}
 //helper method to calculate the sum of a matrix.
double SquareMat::sum() const {
    double total = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            total += matrix[i][j];
        }
    }
    return total;
}
//constructor
SquareMat::SquareMat(int size) : size(size) {
    if (size <= 0) {
        throw std::invalid_argument("Size must be positive");
    }
    //allocating the needed amount of memory
    matrix = new double*[size];
    int i;
    try{
        for (i=0; i < size; ++i) {
            //for each row, allocate an array of doubles and initialize it to 0s.
            matrix[i] = new double[size]();
        }
    } catch (const std::bad_alloc& exception) {
        // freeing the memory we could allocate.
        for (int j = 0; j < i; ++j) {
            delete[] matrix[j];
        }
        delete[] matrix;
        throw std::runtime_error("more memory is needed , failed to allocate");
    }

}
//destructor
//frreing the allocated memory for each entry in the matrix and then the matrix itself.
SquareMat::~SquareMat() {
    for (int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
//set values in complilation.
void SquareMat:: set(int i, int j, double value) {
    if (i < 0 || i >= size || j < 0 || j >= size) {
        throw std::out_of_range("Index out of range, please enter a valid index between 0 and size-1");
    }
    matrix[i][j] = value;
}
//set values in run time.
void SquareMat::set(int i, int j){
    if (i < 0 || i >= size || j < 0 || j >= size) {
        throw std::out_of_range("Index out of range, please enter a valid index between 0 and size-1");
    }
    std::cout << "Enter the value for matrix[" << i << "][" << j << "]: ";
    std::cin >> matrix[i][j];
}
//overloading assignment operator.
SquareMat& SquareMat::operator=(const SquareMat& other) {
    if (this != &other) {
        // freeing the current memory
        for (int i = 0; i < size; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
        // allocating new memory
        size = other.size;
        matrix = new double*[size];
        for (int i = 0; i < size; ++i) {
            matrix[i] = new double[size];
            for (int j = 0; j < size; ++j) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }
    return *this;
}
//getting a value in position i,j.
double SquareMat::get(int i, int j) const {
    if (i < 0 || i >= size || j < 0 || j >= size) {
        throw std::out_of_range("Index out of range, please enter a valid index between 0 and size-1");
    }
    return matrix[i][j];
}
//copy constructor
SquareMat::SquareMat(const SquareMat& other) : size(other.size) {
    matrix = new double*[size];
    for (int i = 0; i < size; ++i) {
        matrix[i] = new double[size];
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}
//overloading the + operator.
SquareMat SquareMat::operator+(const SquareMat& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must be of the same size for addition");
    }
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
        }
    }
    return result;
}
//overloading the - operator.
SquareMat SquareMat::operator-(const SquareMat& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must be of the same size for subtraction");
    }
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
        }
    }
    return result;
}
//overloading the unary - operator.
SquareMat SquareMat::operator-() const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.matrix[i][j] = -matrix[i][j];
        }
    }
    return result;
}
//overloading the * operator when the matrix is multiplied by a scalar.
SquareMat SquareMat::operator*(double scalar) const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.matrix[i][j] = matrix[i][j] * scalar;
        }
    }
    return result;
}





//overloading the * operator when a scalar is multiplied by the matrix.
SquareMat operator*(double scalar, const SquareMat& mat) {
    return mat * scalar;
}
//overloading the * operator when two matrices are multiplied , aka the dot product.
SquareMat SquareMat::operator*(const SquareMat& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must be  the same size for matrix multiplication");
    }
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.matrix[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
            }
        }
    }
    return result;
}
//implementing multiplication of a mat1[i][j] by a mat2[i][j] and storing the result in mat3[i][j].
SquareMat SquareMat::operator%(const SquareMat& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must be the same size for matrix multiplication");
    }
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.matrix[i][j] = matrix[i][j] * other.matrix[i][j];
        }
    }
    return result;
}
//overloading the % operator when a scalar is modulo on every entry of the matrix.
SquareMat SquareMat::operator%(int scalar) const {
    if (scalar <= 0) {
        throw std::invalid_argument("Scalar must be positive for modulo operation");
    }
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.matrix[i][j] = fmod(matrix[i][j], scalar);
        }
    }
    return result;
}
//overloading the / operator when every entry of the matrix is divided by a scalar.
SquareMat SquareMat::operator/(double scalar) const {
    if (scalar == 0) {
        throw std::invalid_argument("cant divide by zero");
    }
    SquareMat result(size);
    for(int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.matrix[i][j] = matrix[i][j] / scalar;
        }
    }
    return result;
}
//overloading the ^ operator when the matrix is raised to a power.
//implementing it with the overloaded * operator.
//using binary exponentiation o(log(n)) for efficiency instead of the naive approach.
SquareMat SquareMat::operator^(int num) const {
    if (num < 0) {
        throw std::invalid_argument("Power must be non-negative");
    }
    if (num == 0) {
        return identity(size); 
    }
    if (num == 1) {
        return *this; 
    }
    SquareMat result = identity(size); // when num = 0 this is the identity matrix.
    SquareMat base = *this;
    while (num > 0) {
        if (num % 2 == 1) {
            result = result * base;
        }
        base = base * base;
        num /= 2;
    }
    return result;
}
//overloading the prefix ++ operator to increment every entry of the matrix by 1.
SquareMat& SquareMat::operator++() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j]++;
        }
    }
    return *this;
}
//overloading the postfix ++ operator to increment every entry of the matrix by 1.
SquareMat SquareMat::operator++(int) {
    SquareMat temp = *this; 
    ++(*this); //increment the current object
    return temp; //return the old values
} 
//overloading the prefix -- operator to decrement every entry of the matrix by 1.
SquareMat& SquareMat::operator--() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j]--;
        }
    }
    return *this;
}       
//overloading the postfix -- operator to decrement every entry of the matrix by 1.
SquareMat SquareMat::operator--(int) {
    SquareMat temp = *this; 
    --(*this); //decrement the current object
    return temp; //return the old values
}
//constructing the NonConstRow class.
SquareMat::NonConstRow::NonConstRow(double* rowPointer) : rowPointer(rowPointer) {}
//overloading the [] operator to return a reference to the j-th element of the row.
double& SquareMat::NonConstRow:: operator[](int j) {
    return rowPointer[j];
}


SquareMat::ConstRow::ConstRow(const double* rowPointer) : rowPointer(rowPointer) {}
//overloading the [] operator to return a reference to the j-th element of the row.
const double& SquareMat::ConstRow:: operator[](int j) const {
    return rowPointer[j];
}

//overloading the [] operator to return a NonConstRow and a ConstRow object.
SquareMat::NonConstRow SquareMat::operator[](int i) {
    if (i < 0 || i >= size) {
        throw std::out_of_range("Index out of range, please enter a valid index between 0 and " + std::to_string(size - 1));
    }
    return NonConstRow(matrix[i]);
}
SquareMat::ConstRow SquareMat::operator[](int i) const {
    if (i < 0 || i >= size) {
        throw std::out_of_range("Index out of range, please enter a valid index between 0 and " + std::to_string(size - 1));
    }
    return ConstRow(matrix[i]);
}
//overloading the ~ operator to transpose the matrix ,
// returning the address of the matrix for the destructor to free the memory
//and method chaining.
SquareMat& SquareMat::operator~() {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
    return *this;
}

//overloading the == operator to compare two matrices.
bool SquareMat::operator==(const SquareMat& other) const {
    const double epsilon = 1e-6; //floating point comparison tolerance.
    return std::abs(sum() - other.sum()) < epsilon;
}
//overloading the != operator to compare two matrices.
bool SquareMat::operator!=(const SquareMat& other) const {
    return !(*this == other);
}
//overloading the < operator to compare two matrices.
bool SquareMat::operator<(const SquareMat& other) const {
    return sum() < other.sum();
}
//overloading the > operator to compare two matrices.
bool SquareMat::operator>(const SquareMat& other) const {
    return sum() > other.sum();
}
//overloading the <= operator to compare two matrices.
bool SquareMat::operator<=(const SquareMat& other) const {
    return sum() <= other.sum();
}
//overloading the >= operator to compare two matrices.
bool SquareMat::operator>=(const SquareMat& other) const {
    return sum() >= other.sum();
}
//overloading the ! operator to calculate the determinant of the matrix.
//using the Laplace recursion method.
double SquareMat::operator!() const {
    if (size == 1) {
        return matrix[0][0];
    }
    if (size == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    double det = 0;
    for (int j = 0; j < size; ++j) {
        det += (j % 2 == 0 ? 1 : -1) * matrix[0][j] * !getMinor(0, j);
    }
    return det;
}

//overloading the += operator to add a matrix to the current matrix.
SquareMat& SquareMat::operator+=(const SquareMat& other) {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must be the same size for addition");
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] += other.matrix[i][j];
        }
    }
    return *this;
}
//overloading the -= operator to subtract a matrix from the current matrix.
SquareMat& SquareMat::operator-=(const SquareMat& other) {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must be the same size for subtraction");
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] -= other.matrix[i][j];
        }
    }
    return *this;
}
//overloading the *= operator to multiply a matrix by a scalar.
SquareMat& SquareMat::operator*=(double scalar) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] *= scalar;
        }
    }
    return *this;
}
//overloading the *= operator to multiply a matrix by another matrix.
SquareMat& SquareMat::operator*=(const SquareMat& other) {
    *this = *this * other; // using the overloaded * operator.
    return *this;
}
//overloading the /= operator to divide a matrix by a scalar.
SquareMat& SquareMat::operator/=(double scalar) {
    *this = *this / scalar; // using the overloaded / operator.
    return *this;
}
//overloading the %= operator to modulo a matrix by a scalar.
SquareMat& SquareMat::operator%=(int scalar) {
    *this = *this % scalar; // using the overloaded % operator.
    return *this;
}
//overloading the %= operator to multiply the ij-th entry of the matrix by the ij-th entry of another matrix.
SquareMat& SquareMat::operator%=(const SquareMat& other) {
    *this = *this % other; // using the overloaded % operator.
    return *this;
}
//overloading the << operator to print the matrix.
std::ostream& operator<<(std::ostream& os, const SquareMat& mat) {
    for (int i = 0; i < mat.size; ++i) {
        for (int j = 0; j < mat.size; ++j) {
            os << mat.matrix[i][j];
            if (j < mat.size - 1) {
                os << " ";
            }
        }
        if (i < mat.size - 1) {
            os << "\n";
        }
    }
    return os;
}
}

