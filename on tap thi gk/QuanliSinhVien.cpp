#include <iostream>
#include <string>
#define MAX 100
using namespace std;


struct SinhVien {
    string hoTen;
    string Mssv;
    string Lop;
    string Sdt;
    float diemTB;

};

void inPutSinhVien(SinhVien &sv){
    cout <<"Nhap ho va ten: ";
    getline(cin, sv.hoTen);
    cout <<"Nhap MSSV: ";
    getline(cin, sv.Mssv);
    cout << "Nhap lop: ";
    getline(cin, sv.Lop);

    cout << "Nhap so dien thoai: ";
    getline(cin, sv.Sdt);

    cout << "Nhap diem trung binh: ";
    cin >> sv.diemTB;
    cin.ignore(); // Để bỏ qua ký tự '\n' sau khi nhập điểm

    
}
void outputSinhVien(const SinhVien &sv) {
    cout << "\nThong tin sinh vien:\n";
    cout << "Ho va ten: " << sv.hoTen << endl;
    cout << "MSSV: " << sv.Mssv << endl;
    cout << "Lop: " << sv.Lop << endl;
    cout << "So dien thoai: " << sv.Sdt << endl;
    cout << "Diem trung binh: " << sv.diemTB << endl;
}

int main(){
    SinhVien sv;
    inPutSinhVien(sv);
    outputSinhVien(sv);
    

    return 0;
}