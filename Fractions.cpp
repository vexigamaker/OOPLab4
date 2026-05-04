#include "Fractions.h"
#include <limits>
#include <iostream>
#include <numeric>
#include <stdexcept>
Fractions::Fractions(int n, int d): num(n), dem(d) {}
Fractions Fractions::operator+ (const Fractions& other) const
{
    Fractions sum;
    sum.num = num * other.dem + dem * other.num;
    sum.dem = dem * other.dem;
    return Fractions (sum.num/gcd(sum.num, sum.dem), sum.dem/gcd(sum.num, sum.dem));
}
Fractions Fractions::operator- (const Fractions& other) const
{
    Fractions diff;
    diff.num = num * other.dem - dem * other.num;
    diff.dem = dem * other.dem;
    return Fractions (diff.num/gcd(diff.num, diff.dem), diff.dem/gcd(diff.num, diff.dem));
}
Fractions Fractions::operator* (const Fractions& other) const
{
    Fractions prod;
    prod.num = num * other.num;
    prod.dem = dem * other.dem;
    return Fractions (prod.num/gcd(prod.num, prod.dem), prod.dem/gcd(prod.num, prod.dem));
}
Fractions Fractions::operator/ (const Fractions& other) const
{
    if (dem == 0 || other.dem == 0 || other.num == 0) return Fractions (std::numeric_limits<int>::quiet_NaN(), std::numeric_limits<int>::quiet_NaN());
    else
    {
        Fractions quo;
        quo.num = num * other.dem;
        quo.dem = dem * other.num;
        return Fractions (quo.num/gcd(quo.num, quo.dem), quo.dem/gcd(quo.num, quo.dem));
    }
}
bool Fractions::operator== (const Fractions& other) const
{
    return (num == other.num && dem == other.dem);
}
bool Fractions::operator!= (const Fractions& other) const
{
    return !(*this == other);
}
std::ostream& operator<<(std::ostream& os, const Fractions& f)
{
    if (f.dem < 0) os << -f.num << "/" << -f.dem;
    else if (f.dem == 1) cout << f.num;
    else os << f.num << "/" << f.dem;
    return os;
}
std::istream& operator>>(std::istream& is, Fractions& f)
{
    is >> f.num >> f.dem;
    return is;
}
Fractions::~Fractions()
{
    //dtor
}
