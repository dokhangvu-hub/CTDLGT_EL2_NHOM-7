#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

/* ====== CẤU TRÚC DỮ LIỆU ====== */

struct NhanVien {
    string ma;
    string hoTen;
    string ngaySinh;
    string email;
    string diaChi;
    string sdt;
    int soNgayCong;
    double luongNgay;
    double thucLinh;
};

struct Node {
    NhanVien nv;
    Node* next;
};

Node* head = NULL;

/* ====== HÀM TIỆN ÍCH ====== */

double tinhThucLinh(NhanVien nv) {
    return nv.soNgayCong * nv.luongNgay;
}

string chuyenThuong(string s) {
    for (char& c : s) c = tolower(c);
    return s;
}

bool trungMa(string ma) {
    Node* p = head;
    while (p != NULL) {
        if (p->nv.ma == ma) return true;
        p = p->next;
    }
    return false;
}

void themCuoiDanhSach(NhanVien nv) {
    nv.thucLinh = tinhThucLinh(nv);
    Node* node = new Node;
    node->nv = nv;
    node->next = NULL;

    if (head == NULL) {
        head = node;
        return;
    }

    Node* p = head;
    while (p->next != NULL)
        p = p->next;
    p->next = node;
}

void inTieuDe() {
    cout << left
         << setw(8) << "Ma"
         << setw(20) << "Ho ten"
         << setw(12) << "Ngay sinh"
         << setw(20) << "Email"
         << setw(15) << "SDT"
         << setw(15) << "Dia chi"
         << setw(8) << "Cong"
         << setw(10) << "Luong"
         << setw(12) << "Thuc linh" << endl;
}

void inNhanVien(NhanVien nv) {
    cout << left
         << setw(8) << nv.ma
         << setw(20) << nv.hoTen
         << setw(12) << nv.ngaySinh
         << setw(20) << nv.email
         << setw(15) << nv.sdt
         << setw(15) << nv.diaChi
         << setw(8) << nv.soNgayCong
         << setw(10) << nv.luongNgay
         << setw(12) << nv.thucLinh << endl;
}

/* ====== XỬ LÝ FILE ====== */

void ghiFile(string tenFile) {
    ofstream f(tenFile);
    Node* p = head;
    while (p != NULL) {
        f << p->nv.ma << "|"
          << p->nv.hoTen << "|"
          << p->nv.ngaySinh << "|"
          << p->nv.email << "|"
          << p->nv.diaChi << "|"
          << p->nv.sdt << "|"
          << p->nv.soNgayCong << "|"
          << p->nv.luongNgay << endl;
        p = p->next;
    }
    f.close();
}

void docFile(string tenFile) {
    ifstream f(tenFile);
    if (!f.is_open()) return;

    head = NULL;
    while (!f.eof()) {
        NhanVien nv;
        getline(f, nv.ma, '|');
        if (nv.ma == "") break;
        getline(f, nv.hoTen, '|');
        getline(f, nv.ngaySinh, '|');
        getline(f, nv.email, '|');
        getline(f, nv.diaChi, '|');
        getline(f, nv.sdt, '|');
        f >> nv.soNgayCong;
        f.ignore();
        f >> nv.luongNgay;
        f.ignore();

        themCuoiDanhSach(nv);
    }
    f.close();
}

/* ====== CÁC CHỨC NĂNG ====== */

void nhapDanhSach() {
    int n;
    cout << "Nhap so nhan vien: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        NhanVien nv;
        cout << "\nNhan vien thu " << i + 1 << endl;

        do {
            cout << "Ma NV: ";
            getline(cin, nv.ma);
        } while (trungMa(nv.ma));

        cout << "Ho ten: ";
        getline(cin, nv.hoTen);
        cout << "Ngay sinh: ";
        getline(cin, nv.ngaySinh);
        cout << "Email: ";
        getline(cin, nv.email);
        cout << "Dia chi: ";
        getline(cin, nv.diaChi);
        cout << "So dien thoai: ";
        getline(cin, nv.sdt);
        cout << "So ngay cong: ";
        cin >> nv.soNgayCong;
        cout << "Luong ngay: ";
        cin >> nv.luongNgay;
        cin.ignore();

        themCuoiDanhSach(nv);
    }
    ghiFile("DSNV.txt");
}

void xuatDanhSach() {
    inTieuDe();
    Node* p = head;
    while (p != NULL) {
        inNhanVien(p->nv);
        p = p->next;
    }
}

void timTheoMa() {
    string ma;
    cout << "Nhap ma can tim: ";
    cin >> ma;

    Node* p = head;
    while (p != NULL) {
        if (p->nv.ma == ma) {
            inTieuDe();
            inNhanVien(p->nv);
            return;
        }
        p = p->next;
    }
}

void timTheoTen() {
    string ten;
    cin.ignore();
    cout << "Nhap ten can tim: ";
    getline(cin, ten);
    ten = chuyenThuong(ten);

    inTieuDe();
    Node* p = head;
    while (p != NULL) {
        if (chuyenThuong(p->nv.hoTen).find(ten) != string::npos)
            inNhanVien(p->nv);
        p = p->next;
    }
}

void thucLinhThapNhat() {
    if (head == NULL) return;

    double minTL = head->nv.thucLinh;
    Node* p = head->next;
    while (p != NULL) {
        if (p->nv.thucLinh < minTL)
            minTL = p->nv.thucLinh;
        p = p->next;
    }

    inTieuDe();
    p = head;
    while (p != NULL) {
        if (p->nv.thucLinh == minTL)
            inNhanVien(p->nv);
        p = p->next;
    }
}

void sapXepGiamDan() {
    for (Node* i = head; i != NULL; i = i->next)
        for (Node* j = i->next; j != NULL; j = j->next)
            if (i->nv.thucLinh < j->nv.thucLinh)
                swap(i->nv, j->nv);

    ghiFile("DSNV_SAPXEP.txt");
}

void xoaTheoMa() {
    string ma;
    cout << "Nhap ma can xoa: ";
    cin >> ma;

    Node* p = head;
    Node* truoc = NULL;

    while (p != NULL) {
        if (p->nv.ma == ma) {
            if (truoc == NULL)
                head = p->next;
            else
                truoc->next = p->next;
            delete p;
            break;
        }
        truoc = p;
        p = p->next;
    }
    ghiFile("DSNV_XOA.txt");
}

void themNhanVienMoi() {
    cin.ignore();
    NhanVien nv;

    do {
        cout << "Ma NV: ";
        getline(cin, nv.ma);
    } while (trungMa(nv.ma));

    cout << "Ho ten: ";
    getline(cin, nv.hoTen);
    cout << "Ngay sinh: ";
    getline(cin, nv.ngaySinh);
    cout << "Email: ";
    getline(cin, nv.email);
    cout << "Dia chi: ";
    getline(cin, nv.diaChi);
    cout << "So dien thoai: ";
    getline(cin, nv.sdt);
    cout << "So ngay cong: ";
    cin >> nv.soNgayCong;
    cout << "Luong ngay: ";
    cin >> nv.luongNgay;

    themCuoiDanhSach(nv);
    ghiFile("DSNV_THEM.txt");
}

void suaNhanVien() {
    string ma;
    cout << "Nhap ma can sua: ";
    cin >> ma;
    cin.ignore();

    Node* p = head;
    while (p != NULL) {
        if (p->nv.ma == ma) {
            cout << "Ho ten moi: ";
            getline(cin, p->nv.hoTen);
            cout << "Ngay sinh moi: ";
            getline(cin, p->nv.ngaySinh);
            cout << "Email moi: ";
            getline(cin, p->nv.email);
            cout << "Dia chi moi: ";
            getline(cin, p->nv.diaChi);
            cout << "So dien thoai moi: ";
            getline(cin, p->nv.sdt);
            cout << "So ngay cong moi: ";
            cin >> p->nv.soNgayCong;
            cout << "Luong ngay moi: ";
            cin >> p->nv.luongNgay;

            p->nv.thucLinh = tinhThucLinh(p->nv);
            break;
        }
        p = p->next;
    }
    ghiFile("DSNV_SUA.txt");
}

/* ====== MENU ====== */

int main() {
    int chon;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Nhap danh sach va ghi file\n";
        cout << "2. Doc file va xuat danh sach\n";
        cout << "3. Tim nhan vien theo ma\n";
        cout << "4. Tim nhan vien theo ten\n";
        cout << "5. Nhan vien co thuc linh thap nhat\n";
        cout << "6. Sap xep giam dan theo thuc linh\n";
        cout << "7. Xoa nhan vien theo ma\n";
        cout << "8. Them nhan vien moi\n";
        cout << "9. Sua thong tin nhan vien\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> chon;

        switch (chon) {
            case 1: nhapDanhSach(); break;
            case 2: docFile("DSNV.txt"); xuatDanhSach(); break;
            case 3: timTheoMa(); break;
            case 4: timTheoTen(); break;
            case 5: thucLinhThapNhat(); break;
            case 6: sapXepGiamDan(); break;
            case 7: xoaTheoMa(); break;
            case 8: themNhanVienMoi(); break;
            case 9: suaNhanVien(); break;
        }
    } while (chon != 0);

    return 0;
}
