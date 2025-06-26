# ĐẶT VẤN ĐỀ
- Tình huống thường xảy ra trong lập trình C/C++. Ví dụ: Code bạn đang viết có hàm tên là test() và có thư viện khác có sẵn mà cũng có hàm test(). Bây giờ, trình biên dịch không biết phiên bản nào của hàm mà bạn muốn sử dụng trong code của mình.
- Làm sao để giải quyết vấn đề trên?
- Vậy thì chúng ta sẽ cùng tìm hiểu các khái niệm:
  - Namespace
  - Name Mangling
  - Từ khóa using
  - Thư viện chuẩn std

# 1. Namespace
- Namespace là cách nhóm các đối tượng như biến, hàm, class, struct,... vào một không gian tách biệt.
- Namespace được sử dụng với mục đích là để tránh xung đột tên khi có các định danh giống nhau được khai báo trong các phần của chương trình hoặc các thư viện khác nhau
- Namespace có các đặc điểm sau:
  - Namespace có thể **lồng** nhau
  - Namespace có tính mở rộng, tương tự như function overloading, khác một chút là mở rộng ở đây có nghĩa là namespace cùng tên
- Lấy ví dụ:

```cpp
#include <iostream>
using namespace std;

// Đặc điểm: lồng nhau, namespace cùng tên,

namespace A
{
    int x = 10;
    void display()
    {
        cout << x << endl;
    }

    namespace C //Namespace lồng nhau
    {
        void display()
        {
            cout << "Hello World!" << endl;
        }
    };
};

namespace A //Namespace mở rộng
{
  int y;
  int z;
};

namespace B
{
    int x = 11;
    void display()
    {
        cout << x << endl;
    }
};

template <typename T>
void display(T a, T b)
{
    cout << "Đây là hàm display với template" << endl;
}

void display(int c)
{
    cout << "Hàm display toàn cục với tham số " << c << endl;
}

int main()
{
    cout << A::x << endl;
    cout << B::x << endl;

    A::y = 10;
    A::z = 11;

    A::display();
    B::display();
    A::C::display();
    display(1, 2);
    display(3);

    return 0;
}
```

# 2. Name Mangling
- Biến đổi tên (Name Mangling) là một cơ chế của trình biên dịch g++ nhằm mã hóa tên hàm, biến, class, namespace,... thành tên duy nhất, để tránh xung đột trong quá trình biên dịch (giai đoạn compiler).
- Trong C++, ta có thể dùng:
  - Class chứa hàm thành viên
  - Nạp chồng hàm (hàm trùng tên, khác tham số)
  - Template
  - Namespace
- Bây giờ chúng ta sẽ xem cấu trúc chung mà trình biên dịch sẽ mã hóa tên của các hàm này với cú pháp:

```cpp
nm file_name.o | grep function_name
```

- Lấy ví dụ ngay cho chương trình trên, tôi mã hóa: my namespace.o | grep display.
- Nó sẽ đưa ra các tên sau:

```
000000014000150a T _Z7displayi
0000000140002980 T _Z7displayIiEvT_S0_
0000000140001498 T _ZN1A1C7displayEv
0000000140001460 T _ZN1A7displayEv
00000001400014d2 T _ZN1B7displayEv
```
- Hãy cùng phân tích: Lấy ví dụ cho _ZN1A1C7displayEv
  - "_Z": bắt đầu mã hóa
  - "N...E": biểu diễn cho namespace
  - "1A1C": cho biết namespace có tên là A (1 ký tự) và namespace C nằm lồng trong A cũng với 1 ký tự.
  - "7display": tên hàm là display với 7 chữ cái
  - "v": không có tham số
- Tương tự cho những hàm khác, chỉ có khác biệt 1 chút:

```
000000014000150a T _Z7displayi : nằm toàn cục với tham số int "i"
0000000140002980 T _Z7displayIiEvT_S0_: "TiE" biểu diễn cho "template T = int" "_S0_" biểu diễn cho có 2 tham số cùng kiểu dữ liệu
```

- Tương tự như vậy chúng ta cũng có thể tìm hiểu thêm những hàm khác và chúng ta còn có thể nhờ trình biên dịch giãi mã những cái tên này với cú pháp:

```
c++filt _Z7displayIiEvT_S0_
```
```
void display<int>(int, int)
```
# 3. Từ khóa Using
- Nếu để ý, có thể thấy ở các nội dung trước, trong chương trình của mình luôn có dòng "using namespace std;".
- Đó là vì từ khóa using cho phép bạn sử dụng các phần tử trong namespace mà không cần phải sử dụng toán tử '::' mỗi khi truy cập.
- Và ta chỉ sử dụng using namespace khi member muốn truy cập đến là duy nhất.
- Đặt từ khóa using này bên dưới namespace đã được tạo.
- Lấy ví dụ:

```cpp
#include <iostream>
using namespace std;
using namespace A; //Lỗi A chưa được định nghĩa
namespace A{
    char *name = (char*)"Anh 20";
}

namespace B{
    char *name = (char*)"Anh 21";
}

using namespace A;
// using namespace B; // error: tham chiếu không rõ ràng

int main()
{
    cout << "Name: " << name << endl;
    cout << "Name: " << B::name << endl;
    return 0;
}
```

# 4. Namespace tiêu chuẩn std
- Một trong những namespace quan trọng và phổ biến nhất trong C++ là std. Tất cả các thành phần của thư viện chuẩn C++ (như cout, cin, vector, string) đều được định nghĩa bên trong namespace std.
- Bên cạnh đó, ta cũng có thể sử dụng tính chất mở rộng của namespace để mở rộng cho namespace tiêu chuẩn này, vì namespace tiêu chuẩn sẽ không được phép thay đổi hay chỉnh sửa gì cả.
- Lấy ví dụ:

```cpp
#include <iostream>
using namespace std;

namespace std{
    struct{
        int x;
        int y;
    } point;

    void display(){
        cout << "x = " << point.x << endl;
        cout << "y = " << point.y << endl;
    }
}

int main()
{  
    point.x = 10;
    point.y = 20;
    display();
    return 0;
}

```


