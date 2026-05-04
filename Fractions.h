#ifndef FRACTIONS_H
#define FRACTIONS_H
#include <iostream>
using namespace std;
class Fractions
{
    private:
        int num;
        int dem;
    public:
        Fractions(int num = 0, int dem = 1);
        Fractions operator+ (const Fractions& other) const;
        Fractions operator- (const Fractions& other) const;
        Fractions operator* (const Fractions& other) const;
        Fractions operator/ (const Fractions& other) const;
        bool operator== (const Fractions& other) const;
        bool operator!= (const Fractions& other) const;
        friend std::ostream& operator<<(std::ostream& os, const Fractions& f);
        friend std::istream& operator>>(std::istream& is, Fractions& f);
        ~Fractions();
};

#endif // FRACTIONS_H
