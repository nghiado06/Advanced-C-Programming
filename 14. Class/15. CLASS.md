# TÌM HIỂU VỀ CLASS TRONG C++
- Tìm hiểu về Class trong C++
  - Định nghĩa
  - Phạm vi truy cập
  - Khái niệm Constructor/Destructor
  - Từ khóa Static trong Class

# 1. CLASS
- Trong C++, từ khóa "class" được sử dụng để định nghĩa một lớp, là một cấu trúc dữ liệu tự định nghĩa có thể chứa dữ liệu và các hàm thành viên liên quan. 
- Lớp là nền tảng của lập trình hướng đối tượng (OOP) trong C++.
- Cấu trúc của class

```cpp
class ClassName
{  Access Specifier
   Data Member;
   Member Functions() {}
}
```

- Trong đó:
  - **Access Specifier:** là **phạm vi truy cập** của class. Tức là khả năng sử dụng các biến thành viên của Class.
  - **Data Member:** Các biến thành viên hay còn được gọi với thuật ngữ là **thuộc tính (properties)** .
  - **Member Fuction:** Hàm thành viên hay còn được gọi là **phương thức (method)**

- Bên cạnh đó, một biến được khai báo bới class này được gọi là 1 **đối tượng (object)**.

```cpp
  class Student
  {
    string name;
    int age; // thuộc tính (properties)
    int id;
    string school;
    string falcuty;

    void display() // phương thức (method)
    {
      cout << "Name: " << name << endl;
      cout << "Age: "  << age << endl;
    {
  }


int main()
{
  Student sv1; // đối tượng (object)
  
  return 0;
}
```

# 2. PHẠM VI TRUY CẬP
- Điểm khác biệt giữa class và struct là gì?. Tại sao người ta lại thiết kế class?
- Điểm khác biệt lớn nhất giữa class và struct đó chính là khả năng truy cập.
- Cụ thể, struct có phạm vi truy cập là public, còn class có 3 phạm vi truy cập khác nhau.
- Vậy phạm vi truy cập là gì?

## 2.1 PHẠM VI TRUY CẬP
- Phạm vi truy cập trong class là cách quy định mức độ truy cập của các thành viên (biến và phương thức) trong một lớp. 
- C++ cung cấp ba phạm vi truy cập chính:
  - public
  - private
  - protected
- Mỗi phạm vi truy cập sẽ có đặc điểm riêng biệt và liên quan đến các tính chất hướng đối tượng khác nhau.

## 2.2 ĐẶC ĐIỂM TỪNG LOẠI PHẠM VI
- Đầu tiên, để truy cập các thuộc tính/phương thức trong class có 2 cách. Trong và ngoài.
- Tức là ta sẽ truy cập/gọi thuộc tính hoặc phương thức bên trong class hoặc bên ngoài hàm class.
### 2.2.1 PRIVATE
- Private không cho phép người dùng truy cập từ bên ngoài, chỉ được phép truy cập từ bên trong.
- Và mặc định của class sẽ là private.
- Lấy ví dụ:

```cpp
#include <iostream>
#include <string>

using namespace std;

class Student
{
  string name;
  int age;
  int id;
  string school;

  void display()
  {
    cout << "Name: " << name << endl;
    cout << "Age: " << age < endl;
  {
};

int main()
{
  SinhVien sv1;
  sv1.name = "Do Duc Nghia";
  sv2.age = 19;
  sv2.display();
  
  return 0;
}
```

- Khi này sẽ không có kết quả trả về mà chương trình sẽ báo lỗi **inaccessible** do các biến mà đối tượng sv1 đang cố gắng truy cập nằm trong phạm vi private.
- Nhưng đối với các biến mà hàm display() truy cập thì lại được phép. Vì đó là truy cập trong, còn sv1 thì đang cố gắng truy cập ngoài.
- Tương tự cho khi ta sử dụng từ khóa private.

```cpp
#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
  string name;
  int age;
  int id;
  string school;

  void display()
  {
    cout << "Name: " << name << endl;
    cout << "Age: " << age < endl;
  {
};

int main()
{
  SinhVien sv1;
  sv1.name = "Do Duc Nghia";
  sv2.age = 19;
  sv2.display();
  
  return 0;
}
```

### 2.2.2 PUBLIC
- Tương tự với private, chỉ khác là bây giờ ta có thể truy cập cả trong lẫn ngoài.
- Lấy ví dụ:

```cpp
#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
  string name;
  int age;
  int id;
  string school;

  void display()
  {
    cout << "Name: " << name << endl;
    cout << "Age: " << age < endl;
  {
};

int main()
{
  SinhVien sv1;
  sv1.name = "Do Duc Nghia";
  sv2.age = 19;
  sv2.display();
  
  return 0;
}
```

output

```
Name: Do Duc Nghia
Age: 19
```

### 2.2.3 PROTECTED
- Kiểu truy cập này sẽ liên quan đến khái niệm **Class con**.
- Protected là kiểu phạm vi sẽ cho phép truy cập trong và truy cập từ class Con.
- Khác với private, private không cho phép truy cập kể cả class con.

#### KHÁI NIỆM CLASS CON
- Class con là class **kế thừa** (sử dụng lại thuộc tính/phương thức) của class khác gọi là **class cha**.
- Cú pháp:

```cpp
class Child : access_modifier Parent
{
{
```
- Quay trở lại với protected, cùng lấy ví dụ ứng dụng của protected.

```cpp
#include <iostream>
#include <string>

using namespace std;

class Parent
{
protected:
    int c;
    int d;

public:
    int a;
    string b;

    void display() { cout << c << endl; }
private:
  int e;
  int f;
};

class Child : protected Parent
{
public:
    void display()
    {
        cout << c << endl;
        cout << d << endl;
        cout << a << endl;
        cout << e << endl; //lỗi không truy cập được
    }
};

int main()
{
    Parent p1;
    p1.c = 1; // Lỗi không truy cập được

    return 0;
}
```

## 2.3 PHƯƠNG THỨC (METHOD)
- Hãy cùng tìm hiểu về cách định nghĩa các phương thức (method).
- Phương thức có 2 cách định nghĩa như cách gọi thuộc tính hay gọi phương thức, đó là định nghĩa trong và định nghĩa ngoài.
### 2.3.1  ĐỊNH NGHĨA TRONG
- Ta sẽ định nghĩa phương thức 1 cách bình thường.

```cpp
class Student
{
public:
  string name;
  int age;
  int id;

  void display()
  {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Id: " << id << endl;
  }
};
```

### 2.3.2 ĐỊNH NGHĨA NGOÀI
- Phương thức được khai báo bên trong class. Nên khi ta định nghĩa, ta phải gọi phương thức này từ class với cú pháp sau.
- Ví dụ:

```cpp
class Student
{
public:
  string name;
  int age;
  int id;

  void display();
};

void SinhVien:display()
{
  cout << "Name: " << SinhVien::name << endl; // Cách gọi thuộc tính thứ 2 (Thêm cú pháp className::Property)
  cout << "Age: " << age << endl;
  cout << "Id: " << id << endl;
}
```

# 3. CONSTRUCTOR/DESTRUCTOR

## 3.1 CONSTRUCTOR
- Constructor trong C++ là một method sẽ được tự động gọi khi khởi tạo object.
- Constructor sẽ có tên trùng với tên của class.
- Thường sử dụng để khởi tạo những giá trị ban đầu.
- Constructor có 2 loại: có tham số và không có tham số

### 3.1.1 KHÔNG CÓ THAM SỐ

```cpp
#include <iostream>
#include <string>```cpp
using namespace std;

class SinhVien
{
public:
  string name;
  int age;
  int id;
  string uni;
  string campus;
  string falcuty;
  string major;

  void display();

  SinhVien(); //Constructor
};

void SinhVien::display()
{
  cout << "Name: " << name << endl;
  cout << "Age: " << age << endl;
  cout << "ID: " << id << endl;
  cout << "Uni: " << uni << endl;
  cout << "Campus: " << campus << endl;
  cout << "Falcuty: " << falcuty << endl;
  cout << "Major: " << major << endl;
}

SinhVien::SinhVien()
{
  Uni = "Ho Chi Minh City University of Technology"; //Khởi tạo các giá trị cố định
  Age = 19;
}

int main()
{
  SinhVien sv1;
  sv1.name = "Do Duc Nghia";
  sv1.id = 2412257;
  sv1.campus = "Ly Thuong Kiet Camp";
  sv1.falcuty = "Falcuty of Mechanical Engineer";
  sv1.major = "Mechatronics Engineering";
  sv1.display();

  return 0;
}
```

output

```
Name: Do Duc Nghia
Age: 19
ID: 2412257
Uni: Ho Chi Minh City University of Technology
Campus: Ly Thuong Kiet Camp
Falcuty: Falcuty of Mechanical Engineer
Major: Mechatronics Engineering
```

### 3.1.2 CÓ THAM SỐ
- Trong đó, tham số có thể được khai báo sẵn hoặc khai báo khi gọi đối tượng.
- Các tham số đầu vào hoàn toàn có thể bị ghi đè.

```cpp
#include <iostream>
#include <string>

using namespace std;

class SinhVien
{
public:
    string name;
    int age;
    int id;
    string uni;
    string campus;
    string falcuty;
    string major;

    void display();

    SinhVien(string newName = " ", string whichUni = " ", string whichCampus = "", string whichMajor = "");
};

void SinhVien::display()
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "ID: " << id << endl;
    cout << "Uni: " << uni << endl;
    cout << "Campus: " << campus << endl;
    cout << "Falcuty: " << falcuty << endl;
    cout << "Major: " << major << endl;
}

SinhVien::SinhVien(string newName, string whichUni, string whichCampus, string whichMajor)
{
    name = newName;
    uni = whichUni;
    age = 19;
    campus = whichCampus;
    major = whichMajor;
}

int main()
{
    // Cách khai báo 1: Khai báo cho tham số
    SinhVien sv1("Do Duc Nghia", "HCMUT", "Ly Thuong Kiet", "Mechatronics Engineering"); // Hoàn toàn có thể ghi đè giá trị
    sv1.id = 2412257;
    sv1.falcuty = "Falcuty of Mechanical Engineer";

    // Cách khai báo 2: Khai báo đè lên tham số
    SinhVien sv2;
    sv2.name = "Ngo Hoang Hao";
    sv2.id = 2310890;
    sv2.uni = "HCMUT";
    sv2.campus = "Di An";
    sv2.major = "Industry Management";
    sv2.falcuty = "Falcuty of Industry Management";

    // Chưa khai báo tham số
    SinhVien sv3;
    sv3.id = 2412862;
    sv3.falcuty = "Falcuty of Mechanical Engineering";

    // Xuất ra màn hình
    sv1.display();

    // Xuống dòng
    cout << endl;

    sv2.display();

    // Xuống dòng
    cout << endl;

    sv3.display();

    return 0;
}
```

output

```
Name: Do Duc Nghia
Age: 19
ID: 2412257
Uni: HCMUT
Campus: Ly Thuong Kiet
Falcuty: Falcuty of Mechanical Engineer
Major: Mechatronics Engineering

Name: Ngo Hoang Hao
Age: 19
ID: 2310890
Uni: HCMUT
Campus: Di An
Falcuty: Falcuty of Industry Management
Major: Industry Management

Name:
Age: 19
ID: 2412862
Uni:
Campus:
Falcuty: Falcuty of Mechanical Engineering
Major:
```

## 3.2 DESTRUCTOR
- Một object sau khi thực hiện xong sẽ được giải phỏng.
- Destructor trong C++ là một method sẽ được tự động gọi trước khi object được giải phóng.
- Destructor sẽ có tên trùng với tên của class và thêm ký tự ~ ở phía trước tên.
- Thường dùng để xóa dữ liệu sau khi dùng xong hoặc thu hồi vùng nhớ đã cấp phát động.

```cpp
#include <iostream>
#include <string>

using namespace std;

class SinhVien
{
public:
    string name;
    int age;
    int id;
    string uni;
    string campus;
    string falcuty;
    string major;

    void display();

    SinhVien(string newName = " ", string whichUni = " ", string whichCampus = "", string whichMajor = "");

    ~SinhVien();
};

void SinhVien::display()
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "ID: " << id << endl;
    cout << "Uni: " << uni << endl;
    cout << "Campus: " << campus << endl;
    cout << "Falcuty: " << falcuty << endl;
    cout << "Major: " << major << endl;
}

SinhVien::SinhVien(string newName, string whichUni, string whichCampus, string whichMajor)
{
    name = newName;
    uni = whichUni;
    age = 19;
    campus = whichCampus;
    major = whichMajor;
}

SinhVien::~SinhVien()
{
    // Reset lại dữ liệu
    name = "";
    uni = "";
    age = 0;
    id = 0;
    campus = "";
    falcuty = "";
    major = "";

    cout << "Da reset du lieu!" << endl;
}

int main()
{
    // Cách khai báo 1: Khai báo cho tham số
    SinhVien sv1("Do Duc Nghia", "HCMUT", "Ly Thuong Kiet", "Mechatronics Engineering"); // Hoàn toàn có thể ghi đè giá trị
    sv1.id = 2412257;
    sv1.falcuty = "Falcuty of Mechanical Engineer"

    // Xuất ra màn hình
    sv1.display();

    return 0;
}

```

output

```
Name: Do Duc Nghia
Age: 19
ID: 2412257
Uni: HCMUT
Campus: Ly Thuong Kiet
Falcuty: Falcuty of Mechanical Engineer
Major: Mechatronics Engineering
Da reset du lieu!
```

# 4. STATIC KEYWORD

## 4.1 STATIC PROPERTY
- Khi một property trong class được khai báo với từ khóa static, thì tất cả các object sẽ dùng chung địa chỉ của property này.
- một static khi đã khai báo cho property, nếu muốn dùng bắt buộc phải định nghĩa lại bên ngoài.

```cpp
#include <iostream>
#include <string>

using namespace std;

class HinhChuNhat
{
public:
    double chieuDai;
    double chieuRong;
    static int var; //Khai báo static property
};

int HinhChuNhat::var; //Định nghĩa lại bên ngoài

int main()
{
    HinhChuNhat hinh1;
    HinhChuNhat hinh2;
    HinhChuNhat hinh3;

    cout << "address of chieu dai: " << &hinh1.chieuDai << endl;
    cout << "address of chieu dai: " << &hinh2.chieuDai << endl;
    cout << "address of chieu dai: " << &hinh3.chieuDai << endl;

    cout << "address of var: " << &hinh1.var << endl;
    cout << "address of var: " << &hinh2.var << endl;
    cout << "address of var: " << &hinh3.var << endl;
    return 0;
}
```

output

```
address of chieu dai: 0x6d7f1ffa20
address of chieu dai: 0x6d7f1ffa10
address of chieu dai: 0x6d7f1ffa00
address of var: 0x7ff785007030
address of var: 0x7ff785007030
address of var: 0x7ff785007030
```

- Chương trình mẫu:

```cpp
#include <iostream>
#include <string>
using namespace std;

class SinhVien
{
public:
    SinhVien(string name, string lop); // constructor  // tự động khởi tạo
    int ID;                            // property
    string name;                       // property
    string lop;                        // property
    void display();                    // method
};

SinhVien::SinhVien(string name, string lop)
{
    static int id = 100;
    SinhVien::ID = id;
    cout << "Create class ID: " << ID << endl;
    id++;

    SinhVien::name = name;
    SinhVien::lop = lop;
}

void SinhVien::display()
{
    cout << "MSSV: " << ID << endl;
    cout << "TEN: " << name << endl;
    cout << "LOP: " << lop << endl;
}

int main(int argc, char const *argv[])
{
    SinhVien sv("Anh", "DDT1"), sv1("Tuan", "CDT2"); // stack
    sv.display();
    cout << "---------" << endl;
    sv1.display();
    return 0;
}

```

output

```
Create class ID: 100
Create class ID: 101
MSSV: 100
TEN: Anh
LOP: DDT1
---------
MSSV: 101
TEN: Tuan
LOP: CDT2
```

## 4.2 STATIC METHOD
- Khi một method trong class được khai báo với từ khóa static:
  - Method này độc lập với bất kỳ đối tượng nào của lớp.
  - Method này có thể được gọi ngay cả khi không có đối tượng nào của class tồn tại.
  - Method này có thể được truy cập bằng cách sử dụng tên class thông qua toán tử :: .
  - Method này có thể truy cập các static property và các static method bên trong hoặc bên ngoài class.
  - Method có phạm vi bên trong class và không thể truy cập con trỏ đối tượng hiện tại.

 Lấy ví dụ:

```cpp
#include <iostream>
#include <string>

using namespace std;

class SinhVien
{
public:
    static int dem;

    SinhVien()
    {
        dem++;
    }

    static void showCount()
    {
        cout << "Da tao " << dem << " sinh vien" << endl;

        // cout << name; ❌ Không được, vì name không phải static
    }

private:
    string name;
};

// Định nghĩa biến static bên ngoài
int SinhVien::dem = 0;

int main()
{
    SinhVien::showCount(); // ✅ Gọi hàm static mà không cần tạo object
    SinhVien sv1;
    SinhVien::showCount();
    SinhVien sv2;
    SinhVien::showCount(); // ✅ In ra: Da tao 2 sinh vien
}

```

output

```
Da tao 0 sinh vien
Da tao 1 sinh vien
Da tao 2 sinh vien
```

