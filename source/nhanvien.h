#include <iostream>
#include <string>

using namespace std;
// CẤU TRÚC NHÂN VIÊN
struct NhanVien {
    string ma;        // Mã nhân viên
    string hoTen;     // Họ tên
    string ngaySinh;  // Ngày sinh
    string email;     // Email
    string diaChi;    // Địa chỉ
    string sdt;       // Số điện thoại
    int soNgayCong;   // Số ngày công
    double luongNgay; // Lương theo ngày
    double thucLinh;  // Lương thực lĩnh
};
// NODE DANH SÁCH LIÊN KẾT ĐƠN
struct Node {
    NhanVien nv;  // Dữ liệu nhân viên
    Node* next;   // Con trỏ node kế tiếp
};
// Con trỏ đầu danh sách
Node* head = NULL;
// HÀM TÍNH LƯƠNG THỰC LĨNH
// Thực lĩnh = số ngày công * lương ngày
double tinhThucLinh(const NhanVien& nv) {
    return nv.soNgayCong * nv.luongNgay;
}
// HÀM TẠO NODE MỚI
Node* taoNode(const NhanVien& nv) {
    Node* p = new Node;
    p->nv = nv;
    p->nv.thucLinh = tinhThucLinh(nv);
    p->next = NULL;
    return p;
}
