# TÌM HIỂU VỀ TỪ KHÓA TEMPLATE
- Hôm nay hãy cùng tìm hiểu về Generic và từ khóa Template.
- Các khái niệm:
  - Function Template
  - Các cơ chế của template
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

- Tiếp đến là 1 tính chất khác của Function Template, quay lại một chút với phương thức trong class, nếu như chúng ta có các kiểu khai báo phương thức: tham số mặc định, tham số không mặc định. Thì bên function template này cũng sẽ tương tự. Và không được phép để typename cuối không có mặc định nếu như bạn đã để mặc định trước đó.
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

template <typename A = int, typename B> //Lỗi vì B không được phép không có mặc định nếu A có mặc định, nếu muốn có thể đổi thứ tự <typename B, typename A = int>
...

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

## Các cơ chế của Template
- Để có thể hiểu sâu hơn về Template, ta cần nắm các cơ chế của template với các ví dụ của function template.
- Các cơ chế:
  - **Deduction**: Compiler tự suy

    ```cpp
    template<typename T>
    void print(T value) {
        cout << "T is: " << typeid(T).name() << endl;
    }
    
    print(42);        // T = int  ← compiler **deduces** T
    print(3.14);      // T = double
    ```

  - **Explicit Instantiation:** Bạn chỉ rõ hay có thể hiểu là bạn đang ép kiểu cho nó.

      ```cpp
      template <typename T = int, typename T1 = int>
      T return_a(T1 a)
      {
        return a*a;
      }
      
      return_a<double>(4); //Trả về 16.0
      ```

    - Tuy nhiên, hiểu rõ hơn một chút, đối với ví dụ trên, thực chất đã xảy ra 2 cơ chế.
    - Có khi nào bạn đặt câu hỏi nếu như ta chỉ định <double> như vậy thì liệu khi tính toán, T1 là kiểu dữ liệu gì? Liệu nó có phải là double*double.
    - Câu trả lời là **không**, khi chúng ta truyền tham số vào T1 a, thì khi này đã xảy ra cơ chế **Deduction**, trình biên dịch đã tự suy T1 là int thì nó sẽ mãi là int, không thể bị ép kiểu nữa.
Hay nói cách khác, thứ bị ép kiểu là T vì nó đang không được **chỉ định hay tự suy**, hàm sẽ hoạt động như kiểu là (double)(int*int).
    - Điều này cũng đúc kết được một điều rằng là các cơ chế sẽ hoạt động riêng biệt, tức là chúng **không được phép tác động lên nhau**.
    - Và nếu như hàm không có gì để chỉ định hay suy luận, thì nó sẽ xét đến **số lượng biến typename**.

- Lấy ví dụ rõ hơn:

```cpp
#include <iostream>
using namespace std;

template <typename T>
void print()
{
    T a;
    cout << "Kiểu dữ liệu của T là: " << typeid(a).name() << endl;
}

template <typename T, typename T1 = int>
void print_a(T1 a)
{
    T b;
    cout << "Kiểu dữ liệu của T1 sau khi đã được deduced là: " << typeid(a).name() << endl;
    cout << "Kiểu dữ liệu của T là: " << typeid(b).name() << endl;
}

template <typename T>
void display()
{
    cout << "Đây là hàm 1 biến!" << endl;
}

template <typename T, typename T1>
void display()
{
    cout << "Đây là hàm 2 biến!" << endl;
}

int main()
{
    // Kiểm tra tính độc lập của cơ chế
    cout << "=== Kiểm tra tính độc lập ===" << endl;
    print<int>();
    print<double>();

    cout << endl;

    print_a<double>(12);
    print_a<int>(3.5);

    cout << endl;

    cout << "=== Kiểm tra nếu đếm số lượng biến ===" << endl;
    
    // Kiểm tra nếu đếm số lượng biến
    display<int>();
    display<double>();

    cout << endl;

    display<int, double>();
    display<int, int>();
    return 0;
}

```

output

```
=== Kiểm tra tính độc lập ===
Kiểu dữ liệu của T là: i
Kiểu dữ liệu của T là: d

Kiểu dữ liệu của T1 sau khi đã được deduced là: i
Kiểu dữ liệu của T là: d
Kiểu dữ liệu của T1 sau khi đã được deduced là: d
Kiểu dữ liệu của T là: i

=== Kiểm tra nếu đếm số lượng biến ===
Đây là hàm 1 biến!
Đây là hàm 1 biến!

Đây là hàm 2 biến!
Đây là hàm 2 biến!
```

  - **Specialization:** Chuyên biệt hóa - Chúng ta sẽ tìm hiểu kỹ hơn ở bên dưới.

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

## 2.3 Template Specialization - Chuyên Biệt Hóa
- 

- Template chuyên biệt hóa (Template Specialization) trong C++ cho phép tùy chỉnh hành vi của template cho một kiểu dữ liệu cụ thể.
- Cú pháp:

```cpp
template <>
class name_of_class<data_type>
{
    private:
        data_type var;
}
```

- Khi sử dụng Chuyên Biệt Hóa Template ta cần có một hàm tổng quát trước.
- Lấy ví dụ:

```cpp
template<>
void A<int>(){}; //Báo lỗi

template <typename T>
void B(){};

template <>
void B<int>(){}; //Không báo lỗi
```

- Lấy một ví dụ cụ thể:

```cpp
#include <iostream>
using namespace std;

// Template tổng quát
template <typename T>
void display(T value){
    cout << "Generic: " << value << endl;
}

// Chuyên biệt hóa cho kiểu `int`
template <>
void display<int>(int value){
    cout << "Specialized for int: " << value << endl;
}

// Chuyên biệt hóa cho kiểu `char*`
template <>
void display<char*>(char* value){
    cout << "Specialized for string: " << value << endl;
}

int main(){
    display(42);        // Sử dụng chuyên biệt hóa cho int
    display(3.14);      // Sử dụng template tổng quát
    display("Hello");   // Sử dụng chuyên biệt hóa cho char*
    return 0;
}
```

- Nhìn vào ví dụ trên, câu hỏi đặt ra là vậy việc sử dụng chuyên biệt hóa khác gì với sử dụng hàm/phương thức bình thường.
- Câu trả lời đó chính là không có sự khác biệt NHƯNG chỉ đối với các trường hợp đơn giản trên thôi. Khi ta sử dụng với các toán tử phức tạp hơn, điển hình như varadic.
- Varadic như đã tìm hiểu ở các nội dung trước, nó cho phép ta điền số lượng tham số không cụ thể. Đối với class cũng vậy, nó cũng có một khái niệm tên varadic template.

## 2.4 Varadic Template
- Variadic Template cho phép bạn tạo các hàm template hoặc lớp template có thể nhận một số lượng tham số không xác định. Điều này giúp bạn viết mã linh hoạt hơn khi làm việc với danh sách tham số có kích thước động.
- Lấy ví dụ:

```cpp
#include <iostream>
using namespace std;

// Function Template khi chỉ có một tham số
template<typename T>
T sum(T value)
{
    return value;
}

// Function Template sử dụng Variadic Template, ít nhất 2 tham số
template<typename T, typename... Args>  
auto sum(T first, Args... args)
{        
    return first + sum(args...);        
}


int main()
{
    cout << sum(1, 2, 3.6, 5.7, 40) << endl;
    return 0;
}
```

- Quay trở lại với vấn đề ban đầu, việc sử dụng chuyên biệt hóa kết hợp với Varadic Template sẽ diễn ra như thế nào. Hãy cùng phân tích 1 ví dụ:

```cpp
#include <iostream>
using namespace std;

template <typename T>
void display()
{
    cout << "Đây là kiểu chưa được chuyên biệt" << endl;
};

template <>
void display<int>()
{
    cout << "Đây là kiểu int" << endl;
}

template <>
void display<bool>()
{
    cout << "Đây là kiểu bool" << endl;
}

template <>
void display<double>()
{
    cout << "Đây là kiểu double" << endl;
}

template <>
void display<float>()
{
    cout << "Đây là kiểu float" << endl;
}

// Trường hợp 1 kiểu
template <typename T>
void display_all()
{
    display<T>();
}

// Trường hợp từ 2 kiểu trở lên
template <typename First, typename Second, typename... Rest>
void display_all()
{
    display<First>();
    display_all<Second, Rest...>();
}

int main()
{
    display_all<bool, double, int>();

    return 0;
}
```

- Ở đây chúng ta đã vận dụng các cơ chế ở trên để viết chương trình này.
- Bây giờ hãy cùng phân tích từng bước:

```cpp
B1: display_all<bool, double, int>
Phân tích: ở đây xét thấy có 3 biến typename --> trình biên dịch hiểu đây là hàm display_all với trường hợp 2 kiểu trở lên.
B2: display<First> --> display<bool> --> Đây là kiểu bool
B3: display<double, int>
Phân tích: tương tự như ở trên, trình biên dịch vẫn hiểu đây là hàm display_all với trường hợp 2 kiểu trở lên.
B4: display<First> --> display<double> --> Đây là kiểu double
B5: display<int> --> Khi này trình biên dịch sẽ chuyển sang hiểu rằng đây là display_all với trường hợp 1 kiểu.
B6: display<int> --> display<int> --> Đây là kiểu int
```

- Vậy câu hỏi đặt ra ở đây là, tại sao ta phải dùng đến typename Second, sao không để là <typename First, typename... Rest> thôi, như ở ví dụ cho Varadic Template trên.
- Câu trả lời đó là, chương trình sẽ báo lỗi overload cho hai hàm y hệt nhau. Vì đặc điểm của template parameters là **Rest vẫn nhận giá trị {}**. Tức là khi không còn tham số đằng sau nữa thì Rest vẫn sẽ hiểu là đằng sau còn rỗng. Còn đối với hàm bình thường thì varadics sẽ không hiểu giá trị rỗng, và nếu có rỗng thì varadic sẽ không tồn tại.
- Cùng lấy ví dụ để trực quan hơn:

```cpp
Nếu như tôi viết:
template <typename First, typename... Rest>
void display_all()
{
    display<First>();
    display_all<Rest...>();
}
thì khi đến display_all<float> thì khi này trình biên dịch vẫn hiểu đây là display_all<float, (rỗng)> và khi này hàm display_all này vẫn hoạt động, và nó sẽ bị trùng với hàm trường hợp 1 kiểu đã được định nghĩa ở trên.
Dẫn đến báo lỗi.

Còn với hàm bình thường như hàm sum thì ví dụ như sum(3) thì trình biên sẽ hiểu là chẳng còn giá trị nào đằng sau nữa và gọi hàm sum(T value) với 1 tham số.
```
