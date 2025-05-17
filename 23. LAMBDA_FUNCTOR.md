# NỘI DUNG TÌM HIỂU
- Hôm nay chúng ta sẽ cùng tìm hiểu về các nội dung trong C++ sau:
- Lambda:
  - Khái niệm
  - Đặc điểm
  - Các cách sử dụng Lambda
- Functor:
  - Khái niệm
  - Đặc điểm
- Giờ cùng bắt đầu tìm hiểu thôi!

# 1. LAMBDA EXPRESSION
## 1.1 Khái niệm
- Lambda là một hàm ẩn danh (anonymous function), tức là một hàm không cần tên và có thể khai báo ngay tại nơi cần dùng.
- Cú pháp:

```cpp
[capture](parameters) --> return type {
  //function body
}
```

- Trong đó:
  - parameter_lists: danh sách tham số (giống hàm toàn cục).
  - return_type: kiểu trả về (có thể tự động suy diễn, thường không cần ghi rõ).
  - {...}: thân hàm.
  - capture: cho biết cách sử dụng các biến xung quanh lambda.

## 1.2 Các cách sử dụng
### 1. Cách gọi và khai báo

- Lambda sẽ có 2 cách gọi:
  - Gọi trực tiếp: gọi trực tiếp sẽ chỉ được gọi cục bộ, không gọi được toàn cục.
  - Trong đó ta phải kết hợp với sử dụng toán tử () để có thể gọi nội dung bên trong lambda nhưng gọi một hàm bình thường.
    - Lấy ví dụ:

    ```cpp
    #include <iostream>
    using namespace std;

    []()
    {
      cout << Hello World << endl;
    }; //Báo lỗi chưa định nghĩa
    
    int main()
    {
      []()
      {
        cout << "Hello World" << endl;
      }();
    
      return 0;
    }
    
    ```

    output

    ```
    Hello World
    ```
    
  - Kết hợp với biến: có thể gọi toàn cục hoặc cục bộ đều được.
  - Bên cạnh đó, kết hợp với biến cũng có 2 cách sử dụng:
    - nếu như gọi hàm một cách trực tiếp bằng toán tử () thì khi này biến sẽ bằng giá trị trả về của lambda.
    - nếu như gán lambda bằng biến thì biến đó sẽ như một hàm bình thường.
  - Lấy ví dụ:

  ```cpp
    #include <iostream>
    using namespace std;

    auto funct = []()
    {
      cout << Hello World << endl;
    }; // Không còn báo lỗi nữa

    funct(); //Gọi biến khi nãy như một hàm bình thường
    
    int main()
    {
      auto funct2 = []()
      {
        return 1 + 2;
      }(); // Đã gọi trực tiếp như này bằng toán tử () thì biến funct2 khi này sẽ bằng giá trị trả về của lambda.

      cout << funct2 << endl; 
    
      return 0;
    }
  ```

  output

  ```
  Hello World
  3
  ```
 
### 2. Cách sử dụng
- Bây giờ chúng ta sẽ tìm hiểu cách sử dụng lambda, thao tác với các từ khóa capture, para ở trên.

#### Lambda đơn giản (Không capture - para - không return-type)
- Nó sẽ là lambda mà chúng ta đã sử dụng ở trên.

```cpp
auto funct = []()
{
  cout << "Hello World";
};

funct();
```

#### Lambda có tham số

- Chúng ta sẽ truyền tham số như một hàm bình thường.

```cpp
auto square = [](int x) {
    return x * x;
};

cout << square(5);  // 25
```

#### Lambda có capture
- Lambda sử dụng capture sẽ có 4 loại nữa:
  - [<name_variable>]: truyền giá trị của biến cụ thể sẽ sử dụng.
  - [=]: truyền giá trị tất cả các biến bên ngoài.
  - [&<name_variable>]	: truyền tham chiếu của biến cụ thể
  - [&]: truyền tham chiếu của tất cả biến bên ngoài
  - Phối hợp các dạng trên.

_**Capture by Value**_
- Capture by value sẽ chỉ **đọc** được giá trị tham số truyền vào, **không tác động** được giá trị.
- Và capture by value này sẽ có thể đọc được giá trị của tất cả biến xung quanh.

```cpp
int a = 5;
int b = 4;
auto lam = [=]() {
  cout << a << " ";
  int c = b;
  cout << c << endl;
}; 
lam();  // 5 4
```

**_Capture by Reference_**
- Capture by reference sẽ tác động trực tiếp đến biến gốc.
- Và capture by reference này sẽ có thể nhận được giá trị của tất cả biến xung quanh.

```cpp
int a = 5;
int b = 4;
auto swap = [&]() {
  int c = b;
  b = a;
  a = c;
}; 
swap();
cout << a << endl; // 4
cout << b << endl; // 5
```

_**Capture cụ thể**_
- Nó sẽ chỉ đọc hoặc ghi giá trị lên biến cụ thể được truyền vào.
- Có phối hợp giữa by value và by reference.

```cpp
int a = 3, b = 4;
auto lam = [a, &b]() {
  cout << a << endl; // 3
  b = 5;
};
cout << b; // 5
```

#### Capture có return-type cụ thể
- Như các ví dụ trên return-type sẽ được trình biên dịch tự suy ra. Vậy thì return-type này có ý nghĩa gì nữa?
- Thực chất là nó sẽ rất quan trọng trong những tình huống cụ thể.
- Lấy ví dụ:

```cpp
auto f = [](bool flag) {
    if (flag) return 3;      // int
    else return 3.5;         // double
}; // Báo lỗi vì conflict kiểu trả về
```

- Trong trường hợp trên thì trình biên dịch sẽ không thể tự suy được nữa, vậy nên ta cần chỉ định rõ kiểu trả về là gì.

```cpp
auto f = [](bool flag) -> double  {
    if (flag) return 3;      // int
    else return 3.5;         // double
}; // Báo lỗi vì conflict kiểu trả về
```

#### Lambda Mutable
- Nó sẽ tương tự với capture by value, nhưng sẽ khác ở chỗ là lần này nó không chỉ đọc mà nó sẽ có thể tạo một biến copy
 với biến capture.
- Nó sẽ tương tự như truyền tham số cho hàm bình thường vậy.
- Lấy ví dụ:

```cpp
int count = 0;
auto lam = [count]() mutable {
    count++;
    std::cout << count << "\n";
};

lam();  // 1
lam();  // 2

cout << count; // 0
```

#### Lambda Truyền Vào STL
- Nó sẽ như một comparator hay các callable khác cho các stl.
- Vậy ưu điểm của nó so với hàm bình thường là gì?.
- Nó sẽ có ưu điểm:
  - Ngắn gọn, viết tại chỗ không cần khai báo trước hay đặt tên. Đặc biệt là với các hàm không cần tái sử dụng.
  - Có giữ được trạng thái state bằng capture. Hay nói cách khác, nó có thể sử dụng biến bên ngoài mà không cần truyền vào như tham số. Điều mà các hàm bình thường không làm được.
- Lấy ví dụ:

```cpp
int threshold = 10;
std::count_if(v.begin(), v.end(), [threshold](int x) {
    return x > threshold;
}); //Biến threshold được sử dụng từ bên ngoài
```

# 2. FUNCTOR
## 2.1 Khái Niệm
- Trong C++, Functor (Function Object - Đối tượng hàm) là một đối tượng (object) có thể hoạt động như một hàm.
- Nói cách khác, functor là một đối tượng của class (struct) có định nghĩa toán tử operator () để có thể gọi ra như một hàm thông thường.
- Nhớ lại một chút về cách sử dụng một operator overloading:

```cpp
return_type operator symbol (parameter_list) {
};
```

- Thì functor chính là một operator được định nghĩa với symbol là () để cho đối tượng có thể sử dụng được và hoạt động như một hàm.
- Cú pháp:

```cpp
return_type operator()(parameter_list) const{};
```

- Cùng lấy một ví dụ về cách nó được sử dụng:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class A
{   
    public:

        void operator () () const
        {
            cout << "Hello World";
        }
};

int main()
{
    A a;
    a(); //Hello World

    return 0;
}
```

## 2.2 Các đặc điểm của functor
### 1. Nó phải được đặt ở public
- Điều này là hiển nhiên, vì bạn gọi nó bên ngoài class thì nó phải được đặt ở trong public.

### 2. Functor là một stateful function
- Một hàm có bộ nhớ (stateful function) là một hàm hoặc đối tượng hàm có thể nhớ và sử dụng dữ liệu nội bộ giữa các lần gọi — nói cách khác, nó giữ trạng thái (state).
- Trong C++, chỉ functor hoặc lambda capture mới làm được điều này.
- Lấy ví dụ:

```cpp
struct Counter {
    int count = 0;

    int operator()(int x) {
        return count += x;
    }
};

int main() {
    Counter c;
    cout << c(1) << endl; // 1
    cout << c(2) << endl; // 3
}
```

- Nếu các bạn để ý kỹ thì sẽ thấy nó có nét tương đồng với static method. Vì static method cũng có thể thao tác với cùng một biến static.
- Nhưng bản chất thì chúng thực sự khác nhau. Vì static method nó **độc lập** với đối tượng. Tức là nó sẽ thao tác với biến static mà không cần một đối tượng nào. Chính vì thế **biến static đó là của toàn class** .
- Lấy ví dụ:

```cpp
#include <iostream>
using namespace std;

class StaticCounter
{
    static int count;

public:
    static int call() { return ++count; }
    void get() { cout << count << endl; }
};

int StaticCounter::count = 0;

int main()
{
    StaticCounter state;
    StaticCounter::call(); // 1
    state.get();
    StaticCounter::call(); // 2
    state.get();
    state.call(); // 3
    state.get();
    return 0;
}
```

- Dù là gọi đối tượng hay không gọi đối tượng thì biến static cũng sẽ bị tác động.
- Còn đối với functor thì mỗi một đối tượng nó sẽ có **bộ nhớ** của nó.
- Cùng lấy ví dụ:

```cpp
struct Counter {
    int count = 0;
    int operator()() { return ++count; }
};

Counter a, b;
a();  // count = 1
a();  // count = 2
b();  // count = 1 → riêng biệt

```

### 3. Hỗ trợ tốt cho các STL, có thể mở rộng với template hay virtual.

- Cùng lấy ví dụ cách nó được mở rộng với STL và Template

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef struct
{
    string name;
    double gpa;
} Student;

// Functor để lọc sinh viên và lưu vào danh sách riêng
class GPAFilter
{
    private:
        double minGPA;
        vector<Student>& resultList;

    public:
        GPAFilter(double threshold, vector<Student>& output)
            : minGPA(threshold), resultList(output) {}
   
        bool operator()(const Student& s)
        {
            if (s.gpa > minGPA)
            {
                resultList.push_back(s);
            }
            return false;  // Để find_if tiếp tục
        }
};

int main()
{
    vector<Student> students =
    {
        {"Alice", 3.2},
        {"Bob", 2.8},
        {"Charlie", 3.9},
        {"David", 2.5}
    };

    double minGPA = 3.0;

    vector<Student> s1;

    GPAFilter filter(minGPA, s1);

    find_if(students.begin(), students.end(), filter);

    for (const auto& item : s1)
    {
        cout << item.name << " ";
    }

    return 0;
}
```

- Đây là một ví dụ kết hợp nhiều kiến thức đã đề cập ở các nội dung trước với nhau. Nên hãy cùng phân tích đặc điểm mới ở ví dụ này.
- Nếu nhìn vào sơ qua, có lẽ sẽ có nhiều bạn không nhận ra functor nằm ở vị trí nào.
- Nhưng để ý kỹ hơn một chút sẽ thấy, functor chính ở chỗ filer nằm ở vị trí callable trong stl find_if.
- Nhưng câu hỏi đặt ra đó chính là vì sao functor lại không cần dùng đến toán tử () ở đây.
- Đó là vì đi sâu một chút vào stl, để ý tham số cuối của stl sẽ là một callable object hoặc một pointer function.
- Thì như đã đề cập, lambda và functor chính là các callable object sẽ được stl hiểu khi chỉ cần truyền vào đối tượng cho stl.
- Bản chất của functor và lambda đều sẽ là đối tượng nhưng được định nghĩa một cách đặc biệt để có thể sử dụng được các tính chất của hàm.

# 3. SO SÁNH FUNCTOR VÀ LAMBDA

## 🔍 So sánh Lambda và Functor trong C++

| Tiêu chí                              | **Lambda**                                             | **Functor**                                          |
|--------------------------------------|--------------------------------------------------------|------------------------------------------------------|
| Cú pháp                            | Ngắn gọn, viết tại chỗ (`[](...) { ... }`)             | Phải định nghĩa riêng struct/class                  |
| Là object?                        | ✅ Có – compiler tạo class ẩn danh                     | ✅ Có – do người lập trình định nghĩa               |
| Có `operator()` không?            | ✅ Luôn có, compiler tự tạo                            | ✅ Phải tự viết `operator()`                        |
| Giữ được trạng thái (state)?     | ✅ Qua capture `[=]`, `[&]`, `[x, &y]`, etc             | ✅ Qua biến thành viên                              |
| Tên kiểu rõ ràng?                | ❌ Không (anonymous type, không đặt tên được)          | ✅ Có tên kiểu rõ ràng (ví dụ: `MyFilter`)          |
| Có thể mở rộng/kế thừa?          | ❌ Không                                                | ✅ Có thể kế thừa, overload                         |
| Debug/log dễ không?              | ❌ Khó (không có tên)                                  | ✅ Dễ vì là class có tên                            |
| Dễ dùng trong template?          | ✅ Dễ dùng với `auto`, `decltype`                      | ✅ Dễ dùng với template nếu bạn cần generic         |
| Tái sử dụng?                     | ❌ Không dễ – viết lại lambda                          | ✅ Có thể dùng lại nhiều nơi                        |

---

## Vậy thì khi nào nên dùng cái nào?

| Tình huống                                       | Khuyên dùng      |
|--------------------------------------------------|------------------|
| Viết logic nhỏ, tại chỗ                          | Lambda           |
| Lọc, sắp xếp đơn giản, ngắn gọn                  | Lambda           |
| Cần đặt tên rõ ràng, tái sử dụng                 | Functor          |
| Cần debug hoặc log dễ hiểu                       | Functor          |
| Cần kế thừa, mở rộng, override, template hóa     | Functor          |
| Cần viết cho STL nhưng vẫn giữ state phức tạp    | Functor          |
| Cần giữ biến bên ngoài theo cách nhanh gọn       | Lambda           |











