#pragma once
#include <vector>

class Matrix {

public:
    Matrix(int r, int c);
    Matrix(const std::vector<std::vector<int>>& d);

    int getRows() const;
    int getCols() const;

    int& operator()(int r, int c);
    int operator()(int r, int c) const;
    Matrix operator*(const Matrix& other) const;
    void print() const;
    int determinant() const;
    Matrix adjugate() const;
    Matrix inverse() const;

private:
    int rows, cols;
    std::vector<std::vector<int>> data;
};