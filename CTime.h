#ifndef CTIME_H
#define CTIME_H
#include <iostream>
class CTime {
private:
    int gio, phut, giay;
    void chuanHoa();
public:
    CTime(int h = 0, int m = 0, int s = 0);
    CTime operator+(int s) const;
    CTime operator-(int s) const;
    CTime& operator++();
    CTime& operator--();
    CTime operator++(int);
    CTime operator--(int);
    friend std::ostream& operator<<(std::ostream& os, const CTime& t);
    friend std::istream& operator>>(std::istream& is, CTime& t);
};
#endif
