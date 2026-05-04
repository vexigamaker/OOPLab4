#ifndef DATHUC_H
#define DATHUC_H
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class DaThuc {
private:
    std::vector<double> heSo;
    void rutGon();
public:
    DaThuc(int bac = 0);
    DaThuc operator+(const DaThuc& other) const;
    DaThuc operator-(const DaThuc& other) const;
    DaThuc operator*(const DaThuc& other) const;
    DaThuc operator/(const DaThuc& other) const;
    DaThuc operator%(const DaThuc& other) const;
    double tinh(double x) const;
    friend std::ostream& operator<<(std::ostream& os, const DaThuc& dt);
    friend std::istream& operator>>(std::istream& is, DaThuc& dt);
};
#endif
