#ifndef CVECTOR_H
#define CVECTOR_H
#include <iostream>
#include <vector>
#include <cmath>

class CVector {
    friend class CMatrix;
private:
    std::vector<double> v;
public:
    CVector(int n = 0);
    CVector operator+(const CVector& other) const;
    CVector operator-(const CVector& other) const;
    double operator*(const CVector& other) const;
    CVector operator*(double scalar) const;
    double module() const;
    friend std::ostream& operator<<(std::ostream& os, const CVector& cv);
    friend std::istream& operator>>(std::istream& is, CVector& cv);
};
#endif
