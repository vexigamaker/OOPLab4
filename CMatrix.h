#ifndef CMATRIX_H
#define CMATRIX_H
#include <iostream>
#include <vector>
#include "CVector.h"

class CMatrix {
private:
    int row, col;
    std::vector<std::vector<double>> data;
public:
    CMatrix(int r = 0, int c = 0);
    CMatrix operator*(double scalar) const;
    CMatrix transpose() const;
    CMatrix operator+(const CMatrix& other) const;
    CMatrix operator*(const CMatrix& other) const;
    CVector operator*(const CVector& v) const;
    double determinant() const;

    friend std::ostream& operator<<(std::ostream& os, const CMatrix& m);
    friend std::istream& operator>>(std::istream& is, CMatrix& m);
};
#endif
