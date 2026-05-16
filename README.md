# 🚌 ĐỒ ÁN: PHẦN MỀM QUẢN LÝ VÉ XE KHÁCH

**Môn học:** Kỹ thuật Lập trình  
**Ngôn ngữ triển khai:** C (Chuẩn C99)  
**Cấu trúc dữ liệu áp dụng:** Danh sách liên kết đơn (Singly Linked List) & Thao tác Tệp tin nhị phân.

---

## 👥 1. Phân công nhiệm vụ thành viên
Dự án được chia thành 4 module độc lập, tương ứng với nhiệm vụ của 4 thành viên như sau:

| STT | Họ và Tên | MSSV | Phân công (Theo File) | Chi tiết công việc thực hiện |
| :---: | :--- | :---: | :--- | :--- |
| **1** | **Trần Vũ Thanh Triển** | 6651071082 | **File header – main**<br>(`vexe.h`, `main.c`) | Định nghĩa cấu trúc `struct VeXe`, khai báo thư viện/hằng số. Xây dựng Menu điều hướng Console và luồng chạy chính. |
| **2** | **Nguyễn Bảo Trị** | 6651071081 | **File chức năng**<br>(`function.c`) | Xây dựng logic quản lý danh sách: Hàm cấp phát Node, Thêm vé mới (tích hợp chọn ghế), Hiển thị danh sách và Xóa vé. |
| **3** | **Ngô Đức Tuấn** | 6651071088 | **File lưu trữ**<br>(`storage.c`) | Xử lý File I/O: Hàm ghi dữ liệu DSLK ra tệp nhị phân (`luuFile`) và hàm tự động load dữ liệu khi khởi động (`docFile`). |
| **4** | **Nguyễn Quốc Tuấn** | 6651071089 | **File tiện ích**<br>(`utils.c`) | Cung cấp các hàm hỗ trợ: Thống kê bằng **Đệ quy**, Validate dữ liệu, **kiểm tra ghế trống (chống trùng lặp)** và giải phóng RAM. |

---

## 📂 2. Cấu trúc mã nguồn
* `vexe.h`: Tệp Header trung tâm kết nối toàn bộ dự án.
* `main.c`: Giao diện tương tác người dùng (Menu).
* `function.c`: Module xử lý nghiệp vụ chính (CRUD).
* `storage.c`: Module tương tác với bộ nhớ vật lý (`data_vexe.dat`).
* `utils.c`: Module chứa các thuật toán và công cụ phụ trợ.

---

## ✨ 3. Các tính năng nổi bật
- [x] **Quản lý vé:** Thêm, xóa và hiển thị vé xe với định dạng bảng ngay ngắn.
- [x] **Quản lý chỗ ngồi:** Cho phép chọn số ghế (1-50) và có thuật toán tự động bắt lỗi, từ chối cấp vé nếu ghế đã có người đặt.
- [x] **Thuật toán Đệ quy:** Áp dụng đệ quy để thống kê tổng số lượng vé (`demVeDeQuy`) và tìm kiếm (`timTheoTenDeQuy`).
- [x] **Lưu trữ tự động:** Không lo mất dữ liệu. Tự động lưu vào `data_vexe.dat` khi thoát và nạp lại khi mở phần mềm.
- [x] **Quản lý bộ nhớ an toàn:** Có cơ chế `free()` giải phóng từng Node khi xóa vé và giải phóng toàn bộ danh sách khi thoát chương trình, chống Leak RAM.

---

## 🛠 4. Hướng dẫn Biên dịch và Khởi chạy

### Môi trường yêu cầu
- Trình biên dịch: **GCC** (MinGW)
- Hệ điều hành: Windows / macOS / Linux

### Các bước chạy code trên Terminal/PowerShell
**Bước 1: Tải mã nguồn về máy**
```bash
git clone https://github.com/TranVuThanhTrien/BTL-quan-ly-ve-xe.git 
cd BTL-quan-ly-ve-xe
```
**Bước 2: Biên dịch liên kết đa tệp (Compile)**
```bash
gcc main.c function.c storage.c utils.c -o QuanLyVeXe
```
**Bước 3: Khởi chạy chương trình (Run)**
```bash
Trên Windows: .\QuanLyVeXe.exe
Trên macOS/Linux: ./QuanLyVeXe
```
*Dự án thực hiện bởi Nhóm 20 - Lớp CQ.66.CNTT - Trường Đại học Giao thông Vận tải Phân hiệu tại TP.HCM.*

