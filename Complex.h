#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
class Complex
{
    private:
        double re;
        double im;
    public:
        Complex(double r = 0, double i = 0);
        Complex operator+ (const Complex& other) const;
        Complex operator- (const Complex& other) const;
        Complex operator* (const Complex& other) const;
        Complex operator/ (const Complex& other) const;
        bool operator== (const Complex& other) const;
        bool operator!= (const Complex& other) const;
        friend std::ostream& operator<<(std::ostream& os, const Complex& z);
        friend std::istream& operator>>(std::istream& is, Complex& z);
        ~Complex();
};

#endif // COMPLEX_H
