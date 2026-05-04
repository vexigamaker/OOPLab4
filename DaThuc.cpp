#include "DaThuc.h"
using namespace std;

DaThuc::DaThuc(int bac) {
    heSo.resize(bac < 0 ? 1 : bac + 1, 0);
}

void DaThuc::rutGon() {
    while (heSo.size() > 1 && heSo.back() == 0) heSo.pop_back();
}

DaThuc DaThuc::operator+(const DaThuc& other) const {
    DaThuc res(max(heSo.size(), other.heSo.size()) - 1);
    for (size_t i = 0; i < res.heSo.size(); ++i) {
        if (i < heSo.size()) res.heSo[i] += heSo[i];
        if (i < other.heSo.size()) res.heSo[i] += other.heSo[i];
    }
    res.rutGon();
    return res;
}

DaThuc DaThuc::operator-(const DaThuc& other) const {
    DaThuc res(max(heSo.size(), other.heSo.size()) - 1);
    for (size_t i = 0; i < res.heSo.size(); ++i) {
        if (i < heSo.size()) res.heSo[i] += heSo[i];
        if (i < other.heSo.size()) res.heSo[i] -= other.heSo[i];
    }
    res.rutGon();
    return res;
}

DaThuc DaThuc::operator*(const DaThuc& other) const {
    DaThuc res(heSo.size() + other.heSo.size() - 2);
    for (size_t i = 0; i < heSo.size(); ++i)
        for (size_t j = 0; j < other.heSo.size(); ++j)
            res.heSo[i + j] += heSo[i] * other.heSo[j];
    res.rutGon();
    return res;
}

DaThuc DaThuc::operator/(const DaThuc& other) const {
    if (other.heSo.empty() || other.heSo.back() == 0) return DaThuc(0);
    DaThuc r = *this, q(max(0, (int)(heSo.size() - other.heSo.size())));
    if (heSo.size() < other.heSo.size()) return DaThuc(0);
    for (int i = r.heSo.size() - other.heSo.size(); i >= 0; --i) {
        double f = r.heSo[i + other.heSo.size() - 1] / other.heSo.back();
        q.heSo[i] = f;
        for (size_t j = 0; j < other.heSo.size(); ++j)
            r.heSo[i + j] -= f * other.heSo[j];
    }
    q.rutGon();
    return q;
}

DaThuc DaThuc::operator%(const DaThuc& other) const {
    if (heSo.size() < other.heSo.size()) return *this;
    DaThuc res = *this - ((*this / other) * other);
    res.rutGon();
    return res;
}

double DaThuc::tinh(double x) const {
    double res = 0;
    for (int i = heSo.size() - 1; i >= 0; --i) res = res * x + heSo[i];
    return res;
}

ostream& operator<<(ostream& os, const DaThuc& dt) {
    bool f = true;
    for (int i = dt.heSo.size() - 1; i >= 0; --i) {
        if (dt.heSo[i] == 0) continue;
        if (!f && dt.heSo[i] > 0) os << " + ";
        if (dt.heSo[i] < 0) os << " - ";
        if (abs(dt.heSo[i]) != 1 || i == 0) os << abs(dt.heSo[i]);
        if (i > 0) os << "x";
        if (i > 1) os << "^" << i;
        f = false;
    }
    return f ? os << "0" : os;
}

istream& operator>>(istream& is, DaThuc& dt) {
    int b; is >> b;
    dt.heSo.assign(b + 1, 0);
    for (int i = b; i >= 0; --i) is >> dt.heSo[i];
    dt.rutGon();
    return is;
}
