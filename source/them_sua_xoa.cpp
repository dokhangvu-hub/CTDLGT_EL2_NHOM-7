 // Chuc nang them, sua va xoa nhan vien
// Them nhan vien moi theo ma
// Sua thong tin nhan vien
// Xoa nhan vien theo ma
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "nhanvien.h"

using namespace std;

// Them nhan vien moi vao vi tri chinh xac theo thu tu ma
void themNhanVienTheoMa(Node*& head, NhanVien nv) {
    Node* p = taoNode(nv);
    
    // Neu danh sach rong hoac ma nhan vien moi nho hon ma dau tien
    if (head == NULL || p->data.maNV < head->data.maNV) {
        p->next = head;
        head = p;
        cout << "Da them nhan vien thanh cong!\n";
        return;
    }
    
    // Tim vi tri chen
    Node* q = head;
    while (q->next != NULL && q->next->data.maNV < p->data.maNV) {
        q = q->next;
    }
    
    // Kiem tra trung ma
    if (q->data.maNV == p->data.maNV || 
        (q->next != NULL && q->next->data.maNV == p->data.maNV)) {
        cout << "Ma nhan vien da ton tai! Khong the them.\n";
        delete p;
        return;
    }
    
    // Chen vao vi tri thich hop
    p->next = q->next;
    q->next = p;
    cout << "Da them nhan vien thanh cong!\n";
}

// Sua thong tin theo nhan vien ma
bool suaNhanVienTheoMa(Node* head, string ma) {
    Node* p = head;
    
    while (p != NULL) {
        if (p->data.maNV == ma) {
            cout << "\n=== SUA THONG TIN NHAN VIEN ===\n";
            cout << "Nhan vien hien tai:\n";
            xuat1NhanVien(p->data);
            
            cout << "\nNhap thong tin moi (de trong neu giu nguyen):\n";
            
            // Luu thong tin cu
            NhanVien nv = p->data;
            
            // Nhap thong tin moi
            cout << "Nhap ho ten moi: ";
            string hoTenMoi;
            getline(cin, hoTenMoi);
            if (!hoTenMoi.empty()) nv.hoTen = hoTenMoi;
            
            cout << "Nhap ngay sinh moi: ";
            string ngaySinhMoi;
            getline(cin, ngaySinhMoi);
            if (!ngaySinhMoi.empty()) nv.ngaySinh = ngaySinhMoi;
            
            cout << "Nhap email moi: ";
            string emailMoi;
            getline(cin, emailMoi);
            if (!emailMoi.empty()) nv.email = emailMoi;
            
            cout << "Nhap dia chi moi: ";
            string diaChiMoi;
            getline(cin, diaChiMoi);
            if (!diaChiMoi.empty()) nv.diaChi = diaChiMoi;
            
            cout << "Nhap so dien thoai moi: ";
            string sdtMoi;
            getline(cin, sdtMoi);
            if (!sdtMoi.empty()) nv.sdt = sdtMoi;
            
            cout << "Nhap so ngay cong moi: ";
            string ngayCongStr;
            getline(cin, ngayCongStr);
            if (!ngayCongStr.empty()) {
                nv.soNgayCong = stoi(ngayCongStr);
            }
            
            cout << "Nhap luong ngay moi: ";
            string luongNgayStr;
            getline(cin, luongNgayStr);
            if (!luongNgayStr.empty()) {
                nv.luongNgay = stod(luongNgayStr);
            }
            
            // Tinh lai thuc linh
            nv.thucLinh = nv.soNgayCong * nv.luongNgay;
            
            // Cap nhat thong tin
            p->data = nv;
            
            cout << "\nDa cap nhat thong tin nhan vien thanh cong!\n";
            cout << "Thong tin sau khi cap nhat:\n";
            xuat1NhanVien(p->data);
            
            return true;
        }
        p = p->next;
    }
    
    cout << "Khong tim thay nhan vien co ma: " << ma << endl;
    return false;
}

// Xoa nhan vien theo ma
bool xoaNhanVienTheoMa(Node*& head, string ma) {
    if (head == NULL) {
        cout << "Danh sach rong!\n";
        return false;
    }
    
    // Truong hop xoa node dau
    if (head->data.maNV == ma) {
        Node* temp = head;
        head = head->next;
        
        cout << "Da xoa nhan vien:\n";
        xuat1NhanVien(temp->data);
        
        delete temp;
        return true;
    }
    
    // Tim node can xoa
    Node* p = head;
    while (p->next != NULL && p->next->data.maNV != ma) {
        p = p->next;
    }
    
    // Neu tim thay
    if (p->next != NULL && p->next->data.maNV == ma) {
        Node* temp = p->next;
        p->next = p->next->next;
        
        cout << "Da xoa nhan vien:\n";
        xuat1NhanVien(temp->data);
        
        delete temp;
        return true;
    }
    
    cout << "Khong tim thay nhan vien co ma: " << ma << endl;
    return false;
}

// Hien thi menu sua xoa
void hienThiMenuThemSuaXoa(Node*& head) {
    int choice;
    do {
        cout << "\n=== CHUC NANG THEM, SUA, XOA NHAN VIEN ===\n";
        cout << "1. Them nhan vien moi\n";
        cout << "2. Sua thong tin nhan vien\n";
        cout << "3. Xoa nhan vien\n";
        cout << "4. Xem danh sach hien tai\n";
        cout << "5. Luu thay doi vao file\n";
        cout << "0. Quay lai menu chinh\n";
        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore();
        
        switch(choice) {
            case 1: {
                cout << "\n=== THEM NHAN VIEN MOI ===\n";
                NhanVien nv = nhap1NhanVien(head);
                themNhanVienTheoMa(head, nv);
                break;
            }
            case 2: {
                cout << "\n=== SUA THONG TIN NHAN VIEN ===\n";
                if (head == NULL) {
                    cout << "Danh sach rong!\n";
                    break;
                }
                
                string ma;
                cout << "Nhap ma nhan vien can sua: ";
                getline(cin, ma);
                
                if (suaNhanVienTheoMa(head, ma)) {
                    ghiFile(head); // Tu dong luu sau khi sua
                }
                break;
            }
            case 3: {
                cout << "\n=== XOA NHAN VIEN ===\n";
                if (head == NULL) {
                    cout << "Danh sach rong!\n";
                    break;
                }
                
                string ma;
                cout << "Nhap ma nhan vien can xoa: ";
                getline(cin, ma);
                
                if (xoaNhanVienTheoMa(head, ma)) {
                    ghiFile(head); // Tu dong luu sau khi xoa
                }
                break;
            }
            case 4: {
                cout << "\n=== DANH SACH NHAN VIEN HIEN TAI ===\n";
                xuatDanhSach(head);
                break;
            }
            case 5: {
                ghiFile(head);
                cout << "Da luu thay doi vao file!\n";
                break;
            }
            case 0:
                cout << "Quay lai menu chinh...\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);
}
