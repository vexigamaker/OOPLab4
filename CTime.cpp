#include "CTime.h"
CTime::CTime(int h, int m, int s) : gio(h), phut(m), giay(s) { chuanHoa(); }
void CTime::chuanHoa() {
    long tong = (long)gio * 3600 + phut * 60 + giay;
    if (tong < 0) tong = 0;
    gio = (tong / 3600) % 24;
    phut = (tong % 3600) / 60;
    giay = tong % 60;
}
CTime CTime::operator+(int s) const { return CTime(gio, phut, giay + s); }
CTime CTime::operator-(int s) const { return CTime(gio, phut, giay - s); }
CTime& CTime::operator++() { giay++; chuanHoa(); return *this; }
CTime CTime::operator++(int) { CTime tmp = *this; ++(*this); return tmp; }
CTime& CTime::operator--() { giay--; chuanHoa(); return *this; }
CTime CTime::operator--(int) { CTime tmp = *this; --(*this); return tmp; }
std::ostream& operator<<(std::ostream& os, const CTime& t) {
    if (t.gio < 10) os << "0"; os << t.gio << ":";
    if (t.phut < 10) os << "0"; os << t.phut << ":";
    if (t.giay < 10) os << "0"; os << t.giay;
    return os;
}
std::istream& operator>>(std::istream& is, CTime& t) {
    is >> t.gio >> t.phut >> t.giay;
    t.chuanHoa();
    return is;
}
