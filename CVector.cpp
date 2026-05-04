#include "CVector.h"
using namespace std;

CVector::CVector(int n) { v.assign(n, 0); }

CVector CVector::operator+(const CVector& other) const {
    if (v.size() != other.v.size()) return CVector(0);
    CVector res(v.size());
    for (size_t i = 0; i < v.size(); ++i) res.v[i] = v[i] + other.v[i];
    return res;
}

CVector CVector::operator-(const CVector& other) const {
    if (v.size() != other.v.size()) return CVector(0);
    CVector res(v.size());
    for (size_t i = 0; i < v.size(); ++i) res.v[i] = v[i] - other.v[i];
    return res;
}

double CVector::operator*(const CVector& other) const {
    if (v.size() != other.v.size()) return 0;
    double res = 0;
    for (size_t i = 0; i < v.size(); ++i) res += v[i] * other.v[i];
    return res;
}

CVector CVector::operator*(double scalar) const {
    CVector res(v.size());
    for (size_t i = 0; i < v.size(); ++i) res.v[i] = v[i] * scalar;
    return res;
}

double CVector::module() const {
    double res = 0;
    for (double x : v) res += x * x;
    return sqrt(res);
}

ostream& operator<<(ostream& os, const CVector& cv) {
    os << "(";
    for (size_t i = 0; i < cv.v.size(); ++i) os << cv.v[i] << (i == cv.v.size() - 1 ? "" : ", ");
    return os << ")";
}

istream& operator>>(istream& is, CVector& cv) {
    int n; is >> n;
    cv.v.assign(n, 0);
    for (int i = 0; i < n; ++i) is >> cv.v[i];
    return is;
}
