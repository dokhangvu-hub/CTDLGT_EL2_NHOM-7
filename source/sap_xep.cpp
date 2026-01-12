// Chuc nang sap xep danh sach nhan vien
// Sap xep giam dan theo thuc linh
// Tim nhan vien co thuc linh thap nhat
void swap_nv(NhanVien &a, NhanVien &b) {
    NhanVien temp = a;
    a = b;
    b = temp;
}

// SẮP XẾP GIẢM DẦN THEO THỰC LĨNH
void sap_xep_giam_dan(LIST l) {
    // Nếu danh sách rỗng hoặc chỉ có 1 phần tử thì không cần sắp xếp
    if (l == NULL || l->pNext == NULL) {
        cout << "Danh sach chua du du lieu de sap xep.\n";
        return;
    }

    // Sử dụng thuật toán Interchange Sort (Đổi chỗ trực tiếp)
    for (NODE* p = l; p->pNext != NULL; p = p->pNext) {
        for (NODE* q = p->pNext; q != NULL; q = q->pNext) {
            // So sánh: Nếu lương người trước < người sau -> Đổi chỗ (để người lương cao lên trước)
            if (p->data.thucLinh < q->data.thucLinh) {
                swap_nv(p->data, q->data);
            }
        }
    }

    cout << "Da sap xep danh sach giam dan theo thuc linh.\n";
    
    // Ghi file kết quả vào tệp txt
    ghi_file(l,"DSNV_SAPXEP.txt");
}

//TÌM NHÂN VIÊN CÓ THỰC LĨNH THẤP NHẤT
void tim_thuc_linh_thap_nhat(LIST l) {
    if (l == NULL) {
        cout << "Danh sach trong!\n";
        return;
    }

    // Bước 1: Tìm giá trị thực lĩnh thấp nhất (min) trong danh sách
    double minLuong = l->data.thucLinh; // Giả sử người đầu tiên là thấp nhất
    NODE* p = l->pNext;
    
    while (p != NULL) {
        if (p->data.thucLinh < minLuong) {
            minLuong = p->data.thucLinh;
        }
        p = p->pNext;
    }

    // Bước 2: Duyệt lại danh sách để in ra TẤT CẢ những người có mức lương = min
    // (Đề phòng trường hợp có nhiều người cùng thấp nhất)
    cout << "\n--- NHAN VIEN CO THUC LINH THAP NHAT (" << minLuong << ") ---\n";
    
    p = l; // Quay lại đầu danh sách
    bool timThay = false;
    
    while (p != NULL) {
        if (p->data.thucLinh == minLuong) {
            xuat_nv(p->data); // Gọi hàm xuất 1 NV đã viết trước đó
            timThay = true;
        }
        p = p->pNext;
    }
}