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

cout << sum(a,b);
```
output

```cpp
15 //Vì kiểu dữ liệu trả về là int
```

- Tiếp đến là 1 tính chất khác của Function Template, quay lại một chút với phương thức trong class, nếu như chúng ta có các kiểu khai báo phương thức: tham số mặc định, tham số không mặc định. Thì bên function template này cũng sẽ tương tự.
- Khi đó giá trị mặc định của typename sẽ là 1 kiểu dữ liệu, khi truyền vào tham số với kiểu dữ liệu bất kỳ, trình biên dịch vẫn sẽ tự động hiểu và sử dụng kiểu dữ liệu đó.
- Và nếu muốn ép kiểu trả về, ta sẽ ép kiểu hằng sau hàm với cú pháp function<dataType>()
- Lấy ví dụ:

```cpp
#include <iostream>
using namespace std;

// tham số mặc định
template <typename T = int, typename T1 = int> //Gán mặc định là int
T square(T1 x)
{
    return x * x;
}

int main()
{
    cout << square(4) << endl; // Kiểu dữ liệu truyền vào là int và trả cũng kiểu dữ liệu int
    cout << square(4.5) << endl; // Kiểu dữ liệu truyền vào là double --> Tính toán ra 20.25 --> nhưng kiểu dữ liệu trả về lại là int nên kết quả sẽ là 20
    cout << square<double>(4.5) << endl; // Ta ép kiểu dữ liệu trả về là double thì kết quả sẽ là 20.25
    return 0;      
}
```

output

```cpp
16
20
20.25
```

## 2.2 Class Template
- Class templates trong C++ là một khái niệm tương tự như function templates, nhưng được áp dụng cho class thay vì function. Class templates cho phép tạo các class có thể làm việc với nhiều kiểu dữ liệu mà không cần viết lại code.
- Template chỉ áp dụng cho một định nghĩa cụ thể của class, không áp dụng cho tất cả các class.
- Cú pháp:

```cpp
template <typename T>
class <name_of_class>
{
    private:
        T var;
}
```

- Lấy ví dụ:

```cpp
#include <iostream>
using namespace std;

template <typename T>
class Sensor{
    private:
        T value;
    public:
        Sensor(T init): value(init){}
        void readSensor(T newValue){ value = newValue; }
        T getValue() const { return value; }
        void display(){ cout << "Gia tri cam bien: " << value << endl; }
};

int main(int argc, char const *argv[]){
    Sensor tempSensor(36.5);
    tempSensor.display();

    Sensor lightSensor(512);
    lightSensor.display();

    Sensor stateSensor("OFF");
    stateSensor.display();
    return 0;
}

```
