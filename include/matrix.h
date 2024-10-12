#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

using namespace std;

/**
 * @brief Implementation of matrix operations.
 * 
 */
class Matrix {
public:
    /**
     * @brief Dot product of two vectors.
     * 
     * @param a Vector a.
     * @param b Vector b.
     * @return vector<double>
     */
    static double dot(const vector<double>& a, const vector<double>& b);

    /**
     * @brief Transpose a matrix.
     * 
     * @param a Matrix a.
     * @return vector<vector<double>> 
     */
    static vector<vector<double>> transpose(const vector<vector<double>>& a);

    /**
     * @brief Add two matrices.
     * 
     * @param a Matrix a.
     * @param b Matrix b.
     * @return vector<vector<double>> 
     */
    static vector<vector<double>> add(const vector<vector<double>>& a, const vector<vector<double>>& b);

    /**
     * @brief Subtract two matrices.
     * 
     * @param a Matrix a.
     * @param b Matrix b.
     * @return vector<vector<double>> 
     */
    static vector<vector<double>> subtract(const vector<vector<double>>& a, const vector<vector<double>>& b);

    /**
     * @brief Multiply two matrices.
     * 
     * @param a Matrix a.
     * @param b Matrix b.
     * @return vector<vector<double>> 
     */
    static vector<vector<double>> multiply(const vector<vector<double>>& a, const vector<vector<double>>& b);

    /**
     * @brief Multiply a matrix by a scalar.
     * 
     * @param a Matrix a.
     * @param scalar Scalar.
     * @return vector<vector<double>> 
     */
    static vector<vector<double>> multiply_escalar(const vector<vector<double>>& a, double scalar);

    /**
     * @brief Print a matrix.
     * 
     * @param a Matrix a.
     */
    static void print(const vector<vector<double>>& a);
};

#endif // MATRIX_H