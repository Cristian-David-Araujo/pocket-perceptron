#include "matrix.h"
#include <iostream>
#include <cassert>

using namespace std;

void test_dot() {
    vector<double> a = {1.0, 2.0, 3.0};
    vector<double> b = {4.0, 5.0, 6.0};
    
    // Resultado esperado del producto punto
    double expected_result = 1.0 * 4.0 + 2.0 * 5.0 + 3.0 * 6.0;

    // Verificamos el resultado de dot
    double result = Matrix::dot(a, b); // Aquí asumimos que tu método regresa un vector con un único elemento.
    assert(result == expected_result);
    cout << "Dot product test passed!" << endl;
}

void test_transpose() {
    vector<vector<double>> a = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };
    vector<vector<double>> expected_result = {
        {1.0, 4.0, 7.0},
        {2.0, 5.0, 8.0},
        {3.0, 6.0, 9.0},
    };

    // Verificamos el resultado de transpose
    vector<vector<double>> result = Matrix::transpose(a);
    assert(result == expected_result);
    cout << "Transpose test passed!" << endl;
}

void test_add() {
    vector<vector<double>> a = {
        {1.0, 2.0},
        {3.0, 4.0}
    };
    vector<vector<double>> b = {
        {5.0, 6.0},
        {7.0, 8.0}
    };
    vector<vector<double>> expected_result = {
        {6.0, 8.0},
        {10.0, 12.0}
    };

    // Verificamos el resultado de add
    vector<vector<double>> result = Matrix::add(a, b);
    assert(result == expected_result);
    cout << "Add test passed!" << endl;
}

void test_subtract() {
    vector<vector<double>> a = {
        {5.0, 6.0},
        {7.0, 8.0}
    };
    vector<vector<double>> b = {
        {1.0, 2.0},
        {3.0, 4.0}
    };
    vector<vector<double>> expected_result = {
        {4.0, 4.0},
        {4.0, 4.0}
    };

    // Verificamos el resultado de subtract
    vector<vector<double>> result = Matrix::subtract(a, b);
    assert(result == expected_result);
    cout << "Subtract test passed!" << endl;
}

void test_multiply() {
    vector<vector<double>> a = {
        {1.0, 2.0},
        {3.0, 4.0}
    };
    vector<vector<double>> b = {
        {5.0, 6.0},
        {7.0, 8.0}
    };
    vector<vector<double>> expected_result = {
        {19.0, 22.0},
        {43.0, 50.0}
    };

    // Verificamos el resultado de multiply
    vector<vector<double>> result = Matrix::multiply(a, b);
    assert(result == expected_result);
    cout << "Multiply test passed!" << endl;

    // Imprimimos el resultado
    Matrix::print(result);
    Matrix::print(expected_result);

}

void test_multiply_escalar() {
    vector<vector<double>> a = {
        {1.0, 2.0},
        {3.0, 4.0}
    };
    double scalar = 2.0;
    vector<vector<double>> expected_result = {
        {2.0, 4.0},
        {6.0, 8.0}
    };

    // Verificamos el resultado de multiply_escalar
    vector<vector<double>> result = Matrix::multiply_escalar(a, scalar);
    assert(result == expected_result);
    cout << "Multiply escalar test passed!" << endl;
}

int main() {
    test_add();
    test_subtract();
    test_dot();
    test_multiply();
    test_multiply_escalar();
    test_transpose();
    
    return 0;
}
