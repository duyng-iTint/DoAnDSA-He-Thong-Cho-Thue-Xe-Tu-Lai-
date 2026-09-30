# TV3 — RF2 — MyMaxHeap

## 1. Vai trò

**Thành viên:** TV3  
**Requirement:** RF2 — Xử lý yêu cầu thuê xe theo mức độ ưu tiên  
**Ngôn ngữ:** C++17  
**Cấu trúc dữ liệu:** Binary Max-Heap  
**OOP:** Class `MyMaxHeap`

---

## 2. Mục tiêu RF2

RF2 xử lý trường hợp có nhiều yêu cầu thuê xe cần được xem xét theo thứ tự ưu tiên.

Thứ tự ưu tiên được xác định như sau:

1. `membershipTier` cao hơn → ưu tiên cao hơn.
2. Nếu cùng `membershipTier` → `bookingTimestamp` nhỏ hơn → ưu tiên cao hơn.

Ví dụ:

```text
Request A: Tier 1, Timestamp 100
Request B: Tier 3, Timestamp 200
Request C: Tier 3, Timestamp 100
```
## 3. Cấu trúc dữ liệu

RF2 sử dụng Binary Max-Heap tự cài đặt.

Request có độ ưu tiên cao nhất luôn nằm tại:

heap[0]

Các thao tác chính:

InsertRequest() — thêm yêu cầu.
ExtractMax() — lấy yêu cầu có độ ưu tiên cao nhất.
RemoveById() — xóa yêu cầu theo bookingId.
BuildHeap() — xây dựng Heap từ danh sách có sẵn.
Top() — xem yêu cầu ưu tiên cao nhất.
Empty() — kiểm tra Heap rỗng.
Size() — lấy số lượng phần tử.
## 4. Quy tắc ưu tiên

Hàm HigherPriority() được sử dụng để so sánh hai request.

Tier khác nhau:
    Tier lớn hơn → ưu tiên hơn

Tier giống nhau:
    Timestamp nhỏ hơn → ưu tiên hơn

Ví dụ:

RENT_003
Tier = 3
Timestamp = 1690000004

RENT_004
Tier = 3
Timestamp = 1690000001

Hai request cùng Tier 3 nên RENT_004 được ưu tiên vì có timestamp nhỏ hơn.

## 5. OOP

Cấu trúc Max-Heap được đóng gói trong class:

class MyMaxHeap
Private
vector<RentalRequest> heap;
unordered_map<string, int> indexMap;

Hai thành phần này được quản lý bên trong class.

Public

Các thao tác được cung cấp cho bên ngoài:

InsertRequest()
ExtractMax()
RemoveById()
BuildHeap()
Top()
Empty()
Size()

OOP được sử dụng chủ yếu để đóng gói dữ liệu và các thao tác của Max-Heap.

## 6. indexMap

indexMap lưu ánh xạ:

bookingId → vị trí trong Heap

Ví dụ:

RENT_001 → 3
RENT_002 → 1
RENT_003 → 0

Mục đích là hỗ trợ tìm nhanh vị trí của request khi thực hiện:

RemoveById()

Khi các phần tử trong Heap được đổi chỗ, vị trí tương ứng trong indexMap cũng được cập nhật.

## 7. Độ phức tạp
Thao tác	Độ phức tạp
Top()	        O(1)
InsertRequest()	O(log n)
ExtractMax()	O(log n)
RemoveById()	O(log n) trung bình
BuildHeap()	    O(n)
## 8. Các file
File	Vai trò
MyMaxHeap.h	Cài đặt cấu trúc Binary Max-Heap và các thuật toán xử lý
MyMaxHeap.cpp	File module, include MyMaxHeap.h
demo_rf2.cpp	Chương trình demo RF2, chứa main()
README.md	Tài liệu mô tả RF2
## 9. Biên dịch và chạy

Đứng trong thư mục MyMaxHeap:

g++ -std=c++17 -Wall -Wextra MyMaxHeap.cpp demo_rf2.cpp -o demo_rf2

Chạy:

demo_rf2
## 10. Kết quả demo

Kết quả chạy thử:

===== RF2 - BUILD HEAP =====
Yeu cau uu tien nhat: RENT_004 | CUS_004 | CAR_01 | Tier: 3 | Time: 1690000001

===== RF2 - REMOVE BY ID =====
Da xoa RENT_002

===== RF2 - XU LY THEO THU TU UU TIEN =====
1. RENT_004 | CUS_004 | CAR_01 | Tier: 3 | Time: 1690000001
2. RENT_003 | CUS_003 | CAR_01 | Tier: 3 | Time: 1690000004
3. RENT_005 | CUS_005 | CAR_01 | Tier: 2 | Time: 1690000003
4. RENT_001 | CUS_001 | CAR_01 | Tier: 1 | Time: 1690000005

Kết quả cho thấy các request được xử lý theo đúng quy tắc:

Tier cao hơn → ưu tiên trước
Cùng Tier → Timestamp nhỏ hơn → ưu tiên trước
## 11. Nội dung bảo vệ chính

Khi bảo vệ RF2 cần nắm được:

Lý do sử dụng Binary Max-Heap.
Quy tắc ưu tiên của request.
Cách InsertRequest() và SiftUp() hoạt động.
Cách ExtractMax() và SiftDown() hoạt động.
Vai trò của indexMap.
Cách RemoveById() hoạt động.
Độ phức tạp của các thao tác.
Cách OOP được sử dụng để đóng gói MyMaxHeap.

**Bản này là vừa đủ cho GitHub**: có chức năng, cấu trúc dữ liệu, OOP, độ phức tạp, cách chạy và kết quả; còn phần giải thích từng dòng `SiftUp/SiftDown` bạn học để bảo vệ là được.