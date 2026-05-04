#include "Complex.h"
#include <limits>
#include <iostream>
Complex::Complex(double r, double i): re(r), im(i) {}
Complex Complex::operator+ (const Complex& other) const
{
    return Complex (re + other.re, im + other.im);
}
Complex Complex::operator- (const Complex& other) const
{
    return Complex (re - other.re, im - other.im);
}
Complex Complex::operator* (const Complex& other) const
{
    return Complex (re * other.re - im * other.im, re * other.im + im * other.re);
}
Complex Complex::operator/ (const Complex& other) const
{
    double denom = other.re * other.re + other.im * other.im;
    if (denom == 0) return Complex(std::numeric_limits<double>::quiet_NaN(),
                       std::numeric_limits<double>::quiet_NaN());
    return Complex ((re * other.re + im * other.im)/denom, (im * other.re - re * other.im)/denom);
}
bool Complex::operator== (const Complex& other) const
{
    return (re == other.re && im == other.im);
}
bool Complex::operator!= (const Complex& other) const
{
    return !(*this == other);
}
std::ostream& operator<<(std::ostream& os, const Complex& z)
{
    os << z.re << (z.im >= 0 ? " + " : " - ") << (z.im >= 0 ? z.im : -z.im) << "i";
    return os;
}
std::istream& operator>>(std::istream& is, Complex& z)
{
    is >> z.re >> z.im;
    return is;
}
Complex::~Complex()
{
    //dtor
}
