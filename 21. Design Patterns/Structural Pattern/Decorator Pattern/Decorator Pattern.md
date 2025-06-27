# NỘI DUNG TÌM HIỂU
- Trong bài này, chúng ta sẽ tìm hiểu một mẫu thiết kế thuộc nhóm Structural Pattern (mẫu cấu trúc). Đó chính là **Decorator Pattern - Mẫu trang trí**.
- Chúng ta sẽ tìm hiểu về:
  - Khái niệm
  - Ưu nhược điểm
  - Ý tưởng chính
  - Phân tích chi tiết hoạt động
  - Code tổng quát
  - Ví dụ dễ hiểu (Coffee + Milk + Sugar)
  - Hủy con trỏ

# KHÁI NIỆM
- Decorator là một mẫu thiết kế cho phép bạn **thêm chức năng cho đối tượng mà không cần sửa mã gốc**.
- Bạn sẽ "bọc" đối tượng của mình bằng một lớp khác, và lớp này sẽ override lại hành vi đã có (hoặc gọi thêm hành vi cũ rồi bổ sung).
- Decorator giúp chức năng được **xếp chồng lên nhau linh hoạt**, tránh tạo quá nhiều class con.

# ĐẶC ĐIỂM, ƯU NHƯỢC ĐIỂM

## Đặc điểm
- Dùng nguyên lý **composition over inheritance** – kết hợp đối tượng thay vì kế thừa cứng.
- Có thể bọc đối tượng **nhiều lớp Decorator** để xếp chồng hành vi.
- Decorator và đối tượng gốc **cùng kế thừa một interface**.

## Ưu điểm
- Mở rộng chức năng **mà không sửa đổi lớp gốc**.
- **Linh hoạt hơn kế thừa** – có thể kết hợp nhiều decorator khác nhau.
- Tuân theo **nguyên lý Mở/Đóng (Open/Closed)**.

## Nhược điểm
- Tạo ra **nhiều lớp nhỏ** – nếu quá lạm dụng sẽ rối mã.
- Logic có thể trở nên **khó theo dõi** nếu nhiều lớp Decorator chồng lên nhau.
- **Khó debug hơn** nếu không kiểm soát tốt luồng gọi qua các lớp bọc.


# TÌNH HUỐNG THỰC TẾ
- Bạn có nhiều loại Coffee: `BasicCoffee`, `Espresso`, `Latte`...
- Bạn muốn thêm các chức năng: `Milk`, `Sugar`, `Whip`, `Caramel`,...
- Thay vì tạo ra hàng loạt lớp kế thừa như:
  - `MilkCoffee`, `MilkLatte`, `SugarEspresso`, `SugarMilkCoffee`, ...
  → Rất nhiều class để phủ hợp mọi combo

==> Dùng Decorator Pattern: **bọc thêm chức năng cho đối tượng**, không cần tạo class mới.

# CÁC THÀNH PHẦN CHÍNH
| Vai trò             | Giải thích                                                     |
| ------------------- | -------------------------------------------------------------- |
| `Component`         | Interface gốc có hàm ví dụ: `getDescription()`                 |
| `ConcreteComponent` | Lớp thực thi của `Component`, chứa logic chính                 |
| `Decorator`         | Lớp trừu tượng/kế thừa từ Component, chứa con trỏ `Component*` |
| `ConcreteDecorator` | Ghi đè hàm Component và bổ sung chức năng mới                  |

# CODE TỔNG QUÁT
```cpp
class Component {
public:
    virtual void operation() = 0;
    virtual ~Component() {}
};

class ConcreteComponent : public Component {
public:
    void operation() override {
        // Logic chính
    }
};

class Decorator : public Component {
protected:
    Component* component;
public:
    Decorator(Component* comp) : component(comp) {}
    void operation() override {
        component->operation();
    }
};

class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* comp) : Decorator(comp) {}
    void operation() override {
        Decorator::operation(); // Gọi lại
        // Bổ sung chức năng A
    }
};
```

# VÍ DỤ CỤ THỂ - COFFEE
```cpp
class Coffee {
public:
    virtual ~Coffee() {
        std::cout << "~Coffee()\n";
    }
    virtual std::string getDescription() = 0;
    virtual int cost() = 0;
};

class BasicCoffee : public Coffee {
public:
    ~BasicCoffee() {
        std::cout << "~BasicCoffee()\n";
    }
    std::string getDescription() override { return "Basic Coffee"; }
    int cost() override { return 5; }
};

class CoffeeDecorator : public Coffee {
protected:
    Coffee* coffee;
public:
    CoffeeDecorator(Coffee* c) : coffee(c) {}
    virtual ~CoffeeDecorator() {
        std::cout << "~CoffeeDecorator()\n";
        delete coffee;
    }
};

class Milk : public CoffeeDecorator {
public:
    Milk(Coffee* c) : CoffeeDecorator(c) {}
    ~Milk() {
        std::cout << "~Milk()\n";
    }
    std::string getDescription() override {
        return coffee->getDescription() + " + Milk";
    }
    int cost() override {
        return coffee->cost() + 2;
    }
};

class Sugar : public CoffeeDecorator {
public:
    Sugar(Coffee* c) : CoffeeDecorator(c) {}
    ~Sugar() {
        std::cout << "~Sugar()\n";
    }
    std::string getDescription() override {
        return coffee->getDescription() + " + Sugar";
    }
    int cost() override {
        return coffee->cost() + 1;
    }
};
```

### Cách dùng:
```cpp
Coffee* myCoffee = new Sugar(new Milk(new BasicCoffee()));
std::cout << myCoffee->getDescription();  // Basic Coffee + Milk + Sugar
std::cout << myCoffee->cost();            // 8
```

# PHÂN TÍCH HOẠT ĐỘNG TỪNG BƯỚC
Chắc hẳn sẽ có nhiều bạn không hiểu ở bước khởi tạo này, cách nó hoạt động ra sao. Vậy thì chúng ta sẽ cùng phân tích từng bước để nắm rõ hơn cách nó hoạt động nhé.

```cpp
Coffee* myCoffee = new Sugar(new Milk(new BasicCoffee()));
```

### Trình tự khởi tạo:
1. `BasicCoffee` được tạo đầu tiên
2. `Milk` bọc `BasicCoffee`
3. `Sugar` bọc `Milk`

### Khi gọi `myCoffee->getDescription()`
- `Sugar::getDescription()` gọi `Milk::getDescription()`
- `Milk::getDescription()` gọi `BasicCoffee::getDescription()`
- Ghép chuỗi ngược lại: `"Basic Coffee + Milk + Sugar"`

### Cần nhớ:
- Việc `new Milk(new BasicCoffee)` **không gọi** `getDescription()` ngay lập tức
- Chỉ khi gọi trực tiếp: `obj->getDescription()` mới bắt đầu chuỗi gọi override

# HỦY ĐỐI TƯỢNG

Khi đã khởi tạo đối tượng bằng cấp phát động thì phải hủy, khi này ta kết hợp thêm destructor. Nhưng nếu hủy bằng `delete` mà không kết hợp `virtual` thì các lớp con sẽ không được hủy đúng cách. Phân tích hai trường hợp sau:

## Trường hợp đúng: Có `virtual` destructor

```cpp
class Coffee {
public:
    virtual ~Coffee() {
        std::cout << "Hủy Coffee\n";
    }
};

class BasicCoffee : public Coffee {
public:
    ~BasicCoffee() {
        std::cout << "Hủy BasicCoffee\n";
    }
};

int main() {
    Coffee* c = new BasicCoffee();
    delete c;
}
```

### Kết quả

```
Hủy BasicCoffee
Hủy Coffee
```

## Trường hợp sai: Không có `virtual` destructor

```cpp
class Coffee {
public:
    ~Coffee() {
        std::cout << "Hủy Coffee\n";
    }
};

class BasicCoffee : public Coffee {
public:
    ~BasicCoffee() {
        std::cout << "Hủy BasicCoffee\n";
    }
};

int main() {
    Coffee* c = new BasicCoffee();
    delete c;
}
```

### Kết quả

```
Hủy Coffee
```

## Kết luận
Khi làm việc với đa hình, nếu bạn dùng con trỏ lớp cha để trỏ tới đối tượng lớp con, hãy luôn khai báo destructor ở lớp cha là `virtual`:

```cpp
class Coffee {
public:
    virtual ~Coffee() {}
};
```

Điều này giúp đảm bảo rằng đối tượng lớp con sẽ được hủy đúng cách và không gây rò rỉ bộ nhớ.

# TỔNG KẾT
- Decorator Pattern cho phép bạn mở rộng chức năng đối tượng linh hoạt và runtime
- Tránh việc tạo quá nhiều lớp kế thừa
- Áp dụng nhiều trong GUI, input stream, game...
- Cần quản lý bộ nhớ nếu dùng `new` liên tục hoài

