#include "CMatrix.h"
using namespace std;

CMatrix::CMatrix(int r, int c) : row(r), col(c) {
    data.assign(r, vector<double>(c, 0));
}

CVector CMatrix::operator*(const CVector& vec) const {
    if (this->col != (int)vec.v.size()) return CVector(0);

    CVector res(this->row);
    for (int i = 0; i < this->row; ++i) {
        double sum = 0;
        for (int j = 0; j < this->col; ++j) {
            sum += this->data[i][j] * vec.v[j];
        }
        res.v[i] = sum;
    }
    return res;
}

CMatrix CMatrix::operator*(const CMatrix& other) const {
    if (this->col != other.row) return CMatrix(0, 0);

    CMatrix res(this->row, other.col);
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < other.col; ++j) {
            for (int k = 0; k < this->col; ++k) {
                res.data[i][j] += this->data[i][k] * other.data[k][j];
            }
        }
    }
    return res;
}

ostream& operator<<(ostream& os, const CMatrix& m) {
    for (int i = 0; i < m.row; ++i) {
        for (int j = 0; j < m.col; ++j) os << m.data[i][j] << " ";
        os << (i == m.row - 1 ? "" : "\n");
    }
    return os;
}

istream& operator>>(istream& is, CMatrix& m) {
    is >> m.row >> m.col;
    m.data.assign(m.row, vector<double>(m.col, 0));
    for (int i = 0; i < m.row; ++i)
        for (int j = 0; j < m.col; ++j) is >> m.data[i][j];
    return is;
}
CMatrix CMatrix::operator+(const CMatrix& other) const {
    if (this->row != other.row || this->col != other.col) return CMatrix(0, 0);
    CMatrix res(row, col);
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            res.data[i][j] = this->data[i][j] + other.data[i][j];
    return res;
}

CMatrix CMatrix::operator*(double scalar) const {
    CMatrix res(row, col);
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            res.data[i][j] = this->data[i][j] * scalar;
    return res;
}

CMatrix CMatrix::transpose() const {
    CMatrix res(col, row);
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            res.data[j][i] = this->data[i][j];
    return res;
}
double CMatrix::determinant() const {
    if (row != col) return 0; // Chỉ tính cho ma trận vuông
    int n = row;
    vector<vector<double>> temp = data;
    double det = 1;
    for (int i = 0; i < n; ++i) {
        int pivot = i;
        for (int j = i + 1; j < n; ++j)
            if (abs(temp[j][i]) > abs(temp[pivot][i])) pivot = j;
        swap(temp[i], temp[pivot]);
        if (pivot != i) det *= -1;
        if (abs(temp[i][i]) < 1e-9) return 0;
        det *= temp[i][i];
        for (int j = i + 1; j < n; ++j) {
            double factor = temp[j][i] / temp[i][i];
            for (int k = i + 1; k < n; ++k)
                temp[j][k] -= factor * temp[i][k];
        }
    }
    return det;
}
