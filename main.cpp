#include "CMatrix.h"
#include "CVector.h"
#include <iostream>

using namespace std;

int main() {
    CMatrix A, B;
    CVector V;
    double s;

    try {
        cout << "1. Nhap ma tran A (hang cot cac_phan_tu): " << endl;
        cin >> A;
        cout << "2. Nhap ma tran B (cung kich thuoc A): " << endl;
        cin >> B;
        cout << "3. Nhap vector V (so chieu bang so cot cua A): " << endl;
        cin >> V;
        cout << "4. Nhap mot so thuc s: ";
        cin >> s;
        cout << "\n--- KET QUA KIEM TRA ---" << endl;
        cout << "Chuyen vi cua A:\n" << A.transpose() << endl;
        if (A.determinant() != 0 || true) { // Kiem tra dinh thuc neu la ma tran vuong
            cout << "Dinh thuc cua A: " << A.determinant() << endl;
        }
        cout << "A + B:\n" << (A + B) << endl;
        cout << "A * " << s << " (Nhan so thuc):\n" << (A * s) << endl;
        cout << "A * V (Ma tran nhan Vector): " << (A * V) << endl;
        cout << "A * B (Ma tran nhan Ma tran):\n" << (A * B) << endl;
    } catch (const exception& e) {
        cerr << "Co loi xay ra: " << e.what() << endl;
    }
    return 0;
}
