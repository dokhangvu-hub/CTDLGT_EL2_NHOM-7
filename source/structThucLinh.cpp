
struct NhanVien {
    string maNV;        // Mã nhân viên (không trùng)
    string hoTen;       // Họ tên nhân viên
    string ngaySinh;    // Ngày tháng năm sinh (dd/mm/yyyy)
    string email;       // Email liên hệ
    string diaChi;      // Địa chỉ liên lạc
    string soDienThoai; // Số điện thoại
    int soNgayCong;     // Số ngày công trong tháng
    double luongNgay;   // Lương theo ngày
    double thucLinh;    // Lương thực lĩnh
};
struct Node {
    NhanVien data;  // Dữ liệu nhân viên
    Node* next;     // Con trỏ trỏ đến node tiếp theo
};
void tinhThucLinh(NhanVien &nv) {
    nv.thucLinh = nv.soNgayCong * nv.luongNgay; //Thực lĩnh = số ngày công * lương ngày
}