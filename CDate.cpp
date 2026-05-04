#include "CDate.h"
CDate::CDate(int d, int m, int y) : d(d), m(m), y(y) {}
bool CDate::laNamNhuan(int y) const { return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0); }
int CDate::ngayTrongThang(int m, int y) const {
    int ds[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (m == 2 && laNamNhuan(y)) ? 29 : ds[m];
}
long CDate::toDays() const {
    long total = d;
    for (int i = 1; i < y; ++i) total += (laNamNhuan(i) ? 366 : 365);
    for (int i = 1; i < m; ++i) total += ngayTrongThang(i, y);
    return total;
}
CDate CDate::fromDays(long days) {
    int y = 1, m = 1;
    while (days > (CDate(1, 1, y).laNamNhuan(y) ? 366 : 365)) {
        days -= (CDate(1, 1, y).laNamNhuan(y) ? 366 : 365);
        y++;
    }
    CDate tmp(1, 1, y);
    while (days > tmp.ngayTrongThang(m, y)) {
        days -= tmp.ngayTrongThang(m, y);
        m++;
    }
    return CDate((int)days, m, y);
}
CDate CDate::operator+(int days) const { return fromDays(toDays() + days); }
CDate CDate::operator-(int days) const { return fromDays(toDays() - days); }
long CDate::operator-(const CDate& other) const { return toDays() - other.toDays(); }
CDate& CDate::operator++() { *this = *this + 1; return *this; }
CDate CDate::operator++(int) { CDate tmp = *this; ++(*this); return tmp; }
CDate& CDate::operator--() { *this = *this - 1; return *this; }
CDate CDate::operator--(int) { CDate tmp = *this; --(*this); return tmp; }
std::ostream& operator<<(std::ostream& os, const CDate& dt) {
    os << (dt.d < 10 ? "0" : "") << dt.d << "/" << (dt.m < 10 ? "0" : "") << dt.m << "/" << dt.y;
    return os;
}
std::istream& operator>>(std::istream& is, CDate& dt) {
    int d, m, y;
    if (is >> d >> m >> y) {
        dt = CDate(d, m, y);
    }
    return is;
}
