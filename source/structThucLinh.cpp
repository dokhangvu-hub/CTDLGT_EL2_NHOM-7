struct NhanVien {
    char MaNV[20];        // Mã nhân viên
    char HoTen[50];       // Họ và tên
    int NamSinh;          // Năm sinh
    char ChucVu[30];      // Chức vụ
    float LuongNgay;      // Lương 1 ngày
    int SoNgayCong;       // Số ngày làm việc trong tháng
    float ThucLinh;       // Lương thực lĩnh
};
struct Node {
    NhanVien data;   // Lưu thông tin 1 nhân viên
    Node* next;      // Con trỏ trỏ đến node kế tiếp
};
if (nv.SoNgayCong >= 0 && nv.LuongNgay >= 0) {
    nv.ThucLinh = nv.SoNgayCong * nv.LuongNgay;
}


