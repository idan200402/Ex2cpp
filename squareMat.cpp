#include <iostream>
#include <stdexcept>
#include <cmath>
namespace ex2{
class SquareMat{
//the matrix has to attributes 
private:
    int size;
    double** matrix;
//constructor
public:
    SquareMat(int size) : size(size) {
        if (size <= 0) {
            throw std::invalid_argument("Size must be positive");
        }
        //allocating the needed amount of memory
        matrix = new double*[size];
        try{
            for (int i=0; i < size; ++i) {
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
    ~SquareMat() {
        for (int i = 0; i < size; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    //set values in complilation.
    void set(int i, int j, double value) {
        if (i < 0 || i >= size || j < 0 || j >= size) {
            throw std::out_of_range("Index out of range, please enter a valid index between 0 and size-1");
        }
        matrix[i][j] = value;
    }
    //set values in run time.
    void set(int i, int j){
        if (i < 0 || i >= size || j < 0 || j >= size) {
            throw std::out_of_range("Index out of range, please enter a valid index between 0 and size-1");
        }
        std::cout << "Enter the value for matrix[" << i << "][" << j << "]: ";
        std::cin >> matrix[i][j];
    }
    //overloading assignment operator.
    SquareMat& operator=(const SquareMat& other) {
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
    double get(int i, int j) const {
        if (i < 0 || i >= size || j < 0 || j >= size) {
            throw std::out_of_range("Index out of range, please enter a valid index between 0 and size-1");
        }
        return matrix[i][j];
    }
    //copy constructor
    SquareMat(const SquareMat& other) : size(other.size) {
        matrix = new double*[size];
        for (int i = 0; i < size; ++i) {
            matrix[i] = new double[size];
            for (int j = 0; j < size; ++j) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }
    //overloading the + operator.
    SquareMat operator+(const SquareMat& other) const {
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
    SquareMat operator-(const SquareMat& other) const {
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
    SquareMat operator-() const {
        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.matrix[i][j] = -matrix[i][j];
            }
        }
        return result;
    }
    //overloading the * operator when the matrix is multiplied by a scalar.
    SquareMat operator*(double scalar) const {
        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.matrix[i][j] = matrix[i][j] * scalar;
            }
        }
        return result;
    }




    //overloading the * operator when a scalar is multiplied by the matrix.
    friend SquareMat operator*(double scalar, const SquareMat& mat) {
        return mat * scalar;
    }
    //overloading the * operator when two matrices are multiplied , aka the dot product.
    SquareMat operator*(const SquareMat& other) const {
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
    SquareMat operator%(const SquareMat& other) const {
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
    SquareMat operator%(int scalar) const {
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


        
        

}


}

