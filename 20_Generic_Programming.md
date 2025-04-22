# TÌM HIỂU VỀ TỪ KHÓA TEMPLATE
- Hôm nay hãy cùng tìm hiểu về Generic và từ khóa Template.
- Các khái niệm:
  - Function Template
  - Class Template
  - Varadic Template

# 1. VẤN ĐỀ
- Như đã tìm hiểu trong các nội dung trước về OOP. Có một khái niệm đó chính là chồng chất hàm - function overloading.
- Ví dụ như này:

```cpp
int sum (int a, int b)
{
  return a+b;
};

double sum (double a, double b)
{
  return a+b;
};
```
- Vậy thì overloading giúp chúng ta khai báo các hàm cùng tên nhưng khác nhau tính chất như tham số truyền vào. Vậy thì câu hỏi đặt ra là có cách nào để tổng quát hóa các hàm lại hay không? Câu trả lời là có. Và chúng ta sẽ tìm hiểu đến khái niệm Generic Programming.

# 2. GENERIC PROGRAMMING
- Generic Programming (Lập trình tổng quát) là một phương pháp lập trình sử dụng các tham số kiểu dữ liệu (type parameter) để viết mã có thể tái sử dụng và hoạt động với nhiều kiểu dữ liệu khác nhau. Kỹ thuật này giúp loại bỏ sự trùng lặp code và tăng tính linh hoạt trong thiết kế phần mềm.
- Lập trình tổng quát thường được áp dụng trong các ngôn ngữ hỗ trợ Generics (như Java, Rust) hoặc Templates (C++).
- C++ sử dụng Templates để triển khai Generic Programming. Templates có hai loại:
  - Function Templates (Hàm tổng quát)
  - Class Templates (Lớp tổng quát)

## 2.1 Function Templates - Hàm Tổng Quát
- Trong C++, Templates giúp viết hàm có thể làm việc với nhiều kiểu dữ liệu mà không cần overload nhiều lần.
- Template chỉ áp dụng cho một định nghĩa cụ thể của hàm, không áp dụng cho tất cả các hàm.
- Cú pháp như sau:

```cpp
template <typename T>
T func(T a, T b){}

template <typename T1, typename T2, typename T3>
T1 func(T1 a, T2 b, T3 c){}

```

