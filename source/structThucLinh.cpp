struct NhanVien {
    char maNV[20];        // Mã nhân viên
    char hoTen[50];       // Họ và tên
    int namSinh;          // Năm sinh
    char chucVu[30];      // Chức vụ
    float luongNgay;      // Lương 1 ngày
    int soNgayCong;       // Số ngày làm việc trong tháng
    float thucLinh;       // Lương thực lĩnh
};
struct Node {
    NhanVien data;   // Lưu thông tin 1 nhân viên
    Node* next;      // Con trỏ trỏ đến node kế tiếp
};
if (nv.soNgayCong >= 0 && nv.luongNgay >= 0) {
    nv.thucLinh = nv.soNgayCong * nv.luongNgay;
}

