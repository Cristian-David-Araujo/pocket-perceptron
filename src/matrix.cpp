#include "matrix.h"

using namespace std;

double Matrix::dot(const vector<double> &a, const vector<double> &b)
{
    // Check if the vectors have the same size.
    int a_size = a.size();
    int b_size = b.size();

    if (a_size != b_size)
    {
        throw invalid_argument("Vectors must have the same size.");
    }

    // Perform the dot product.
    double result = 0;
    for (int i = 0; i < a_size; i++)
    {
        result += a[i] * b[i];
    }

    return result;
}

vector<vector<double>> Matrix::transpose(const vector<vector<double>> &a)
{
    // Get the dimensions of the matrix.
    int rows = a.size();
    int cols = a[0].size();

    // Initialize the result matrix.
    vector<vector<double>> result(cols, vector<double>(rows, 0));

    // Perform the transpose.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[j][i] = a[i][j];
        }
    }

    return result;
}

vector<vector<double>> Matrix::add(const vector<vector<double>> &a, const vector<vector<double>> &b)
{
    // Check if the matrices have the same dimensions.
    int a_rows = a.size();
    int a_cols = a[0].size();
    int b_rows = b.size();
    int b_cols = b[0].size();

    if ((a_rows != b_rows) || (a_cols != b_cols))
    {
        throw invalid_argument("Matrices must have the same dimensions.");
    }

    // Perform the addition.
    vector<vector<double>> result(a_rows, vector<double>(a_cols, 0));

    for (int i = 0; i < a_rows; i++)
    {
        for (int j = 0; j < a_cols; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    return result;
}

vector<vector<double>> Matrix::subtract(const vector<vector<double>> &a, const vector<vector<double>> &b)
{
    // Check if the matrices have the same dimensions.
    int a_rows = a.size();
    int a_cols = a[0].size();
    int b_rows = b.size();
    int b_cols = b[0].size();

    if ((a_rows != b_rows) || (a_cols != b_cols))
    {
        throw invalid_argument("Matrices must have the same dimensions.");
    }

    // Perform the subtraction.
    vector<vector<double>> result(a_rows, vector<double>(a_cols, 0));

    for (int i = 0; i < a_rows; i++)
    {
        for (int j = 0; j < a_cols; j++)
        {
            result[i][j] = a[i][j] - b[i][j];
        }
    }

    return result;
}

vector<vector<double>> Matrix::multiply(const vector<vector<double>> &a, const vector<vector<double>> &b)
{
    // Check if the matrices can be multiplied.
    int a_rows = a.size();
    int a_cols = a[0].size();
    int b_rows = b.size();
    int b_cols = b[0].size();

    if (a_cols != b_rows)
    {
        throw invalid_argument("Matrices cannot be multiplied.");
    }

    // Initialize the result matrix.
    vector<vector<double>> result(a_rows, vector<double>(b_cols, 0));

    // Perform the dot product.
    for (int i = 0; i < a_rows; i++)
    {
        for (int j = 0; j < b_cols; j++)
        {
            for (int k = 0; k < a_cols; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return result;
}

vector<vector<double>> Matrix::multiply_escalar(const vector<vector<double>> &a, double scalar)
{
    // Get the dimensions of the matrix.
    int rows = a.size();
    int cols = a[0].size();

    // Initialize the result matrix.
    vector<vector<double>> result(rows, vector<double>(cols, 0));

    // Perform the multiplication.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = a[i][j] * scalar;
        }
    }

    return result;
}

void Matrix::print(const vector<vector<double>> &a)
{
    // Get the dimensions of the matrix.
    int rows = a.size();
    int cols = a[0].size();

    // Print the matrix to the console with a nice format (rows and columns). Same separator as Python.
    cout << "Matrix (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "[";
        for (int j = 0; j < cols; j++)
        {
            cout << a[i][j];
            if (j < cols - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    
}
