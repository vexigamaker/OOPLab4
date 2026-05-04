#ifndef CDATE_H
#define CDATE_H
#include <iostream>
class CDate {
private:
    int d, m, y;
    bool laNamNhuan(int y) const;
    int ngayTrongThang(int m, int y) const;
    long toDays() const;
    static CDate fromDays(long days);
public:
    CDate(int d = 1, int m = 1, int y = 1);
    CDate operator+(int days) const;
    CDate operator-(int days) const;
    long operator-(const CDate& other) const;
    CDate& operator++();
    CDate operator++(int);
    CDate& operator--();
    CDate operator--(int);
    friend std::ostream& operator<<(std::ostream& os, const CDate& dt);
    friend std::istream& operator>>(std::istream& is, CDate& dt);
};
#endif
