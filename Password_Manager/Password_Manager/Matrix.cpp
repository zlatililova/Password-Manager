#include "Matrix.h"
#include <stdexcept>
#include <iostream>
#include "Utils.h"

//for the development help from https://www.tutorialspoint.com/cryptography/cryptography_hill_cipher.htm was used

namespace Constants {
    const unsigned MOD = 26;
};
Matrix::Matrix(int r, int c) : rows(r), cols(c), data(r, std::vector<int>(c)) {}

Matrix::Matrix(const std::vector<std::vector<int>>& d) : rows(d.size()), cols(d[0].size()), data(d) {}

int& Matrix::operator()(int r, int c) {
    return data[r][c];
}

int Matrix::operator()(int r, int c) const {
    return data[r][c];
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows) {
        throw std::runtime_error("Matrix dimensions mismatch for multiplication!");
    }

    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            int sum = 0;
            for (int k = 0; k < cols; ++k) {
                sum += data[i][k] * other.data[k][j];
            }
            result(i, j) = sum % Constants::MOD;
            if (result(i, j) < 0) {
                result(i, j) += Constants::MOD;
            }
        }
    }
    return result;
}

void Matrix::print() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int Matrix::determinant() const {
    if (rows != cols) {
        throw std::runtime_error("Cannot calculate determinant for non-square matrix!");
    }

    if (rows == 1) {
        return data[0][0];
    }
    else if (rows == 2) {
        int det = data[0][0] * data[1][1] - data[0][1] * data[1][0];
        return (det % Constants::MOD + Constants::MOD) % MOD; // Ensure positive modulo
    }
    else if (rows == 3) {
        int det = data[0][0] * (data[1][1] * data[2][2] - data[1][2] * data[2][1]) -
            data[0][1] * (data[1][0] * data[2][2] - data[1][2] * data[2][0]) +
            data[0][2] * (data[1][0] * data[2][1] - data[1][1] * data[2][0]);
        return (det % Constants::MOD + Constants::MOD) % MOD;
    }
    else {
        throw std::runtime_error("Determinant calculation for n > 3 not implemented!");
    }
}

Matrix Matrix::adjugate() const {
    if (this->rows != this->cols) {
        throw std::runtime_error("Cannot calculate adjugate for non-square matrix!");
    }
    Matrix adj(rows, cols);

    if (rows == 2) {
        adj(0, 0) = data[1][1];
        adj(0, 1) = -data[0][1];
        adj(1, 0) = -data[1][0];
        adj(1, 1) = data[0][0];
    }
    else if (rows == 3) {
        adj(0, 0) = (data[1][1] * data[2][2] - data[1][2] * data[2][1]);
        adj(0, 1) = -(data[1][0] * data[2][2] - data[1][2] * data[2][0]); // Should be adj(1,0) for the transpose
        adj(0, 2) = (data[1][0] * data[2][1] - data[1][1] * data[2][0]);

        adj(1, 0) = -(data[0][1] * data[2][2] - data[0][2] * data[2][1]);
        adj(1, 1) = (data[0][0] * data[2][2] - data[0][2] * data[2][0]);
        adj(1, 2) = -(data[0][0] * data[2][1] - data[0][1] * data[2][0]);

        adj(2, 0) = (data[0][1] * data[1][2] - data[0][2] * data[1][1]);
        adj(2, 1) = -(data[0][0] * data[1][2] - data[0][2] * data[1][0]);
        adj(2, 2) = (data[0][0] * data[1][1] - data[0][1] * data[1][0]);

        Matrix temp_adj = adj;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                adj(i, j) = (temp_adj(j, i) % Constants::MOD + Constants::MOD) % MOD;
            }
        }

    }
    else {
        throw std::runtime_error("Adjugate calculation for n > 3 not implemented!");
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            adj(i, j) = (adj(i, j) % Constants::MOD + Constants::MOD) % MOD;
        }
    }
    return adj;
}

Matrix Matrix::inverse() const {
    int det = determinant();
    int det_inv = modInverse(det, Constants::MOD);

    if (det_inv == -1) {
        throw std::runtime_error("Matrix is not invertible modulo 26!");
    }

    Matrix adj = adjugate();
    Matrix inv(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            inv(i, j) = (adj(i, j) * det_inv) % Constants::MOD;
            if (inv(i, j) < 0) {
                inv(i, j) += Constants::MOD;
            }
        }
    }
    return inv;
}