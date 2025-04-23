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

- Trong đó, typename T này có thể hiểu là một kiểu dữ liệu tổng Quát, khi truyền tham số với kiểu dữ liệu bất kỳ, trình biên dịch sẽ tự động hiểu chỗ đó là cần kiểu dữ liệu nào. Và chúng ta có thể khai báo nhiều typename cùng 1 lúc.
- Lấy ví dụ cho khai báo 1 typename:

```cpp
template <typename T>
T sum(T a, T b)
{
    return a + b;
}

int result1 = sum(5, 10);           // Tự động biết T là int
double result2 =sum(3.14, 2.71);
```

output

```cpp
result1 = 15
result2 = 5.85
```

- Lấy ví dụ cho khai báo nhiều typename, cũng tương tự với 1, nó chỉ quan tâm đến kiểu dữ liệu tham số truyền vào:

```cpp
template <typename T1, typename T2>
T1 sum(T1 a, T2 b)
{
    return a + b;
}

int a = 10;
double b = 15.5;

int result = sum(a,b);
```
output

```cpp
result = 15 //Vì đây là kiểu dữ liệu int
```

