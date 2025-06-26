Hôm nay chúng ta sẽ cùng tìm hiểu nội dung SOLID. Không phải là solid trong solidworks :). Mà sẽ là **S.O.L.I.D**, các
nguyên tắc trong thiết kế hướng đối tượng.

# SOLID PRINCIPLES
- **SOLID** là tập hợp 5 nguyên tắc **thiết kế phần mềm** giúp tạo ra mã nguồn dễ bảo trì, mở rộng và linh hoạt hơn.
- Bao gồm:
  - **S: Single Responsibility**
  - **O: Open/CLosed Principle**
  - **L: Liskov's Substitution Principle**
  - **I: Interface Segregation**
  - **D: Dependency Inversion**
- Bây giờ hãy cùng đi tìm hiểu từng nguyên tắc.

# 1. S - Single Responsibility (Nguyên tắc đơn trách nhiệm)
- Mỗi phần của chương trình chỉ nên làm một việc duy nhất. Nếu một phần có nhiều nhiệm vụ, nó sẽ khó bảo trì và dễ gây lỗi khi thay đổi..
- Giúp mã nguồn dễ bảo trì, dễ mở rộng và dễ kiểm thử hơn.
- Lấy ví dụ:

```cpp
class Sensor
{
    public:
        // Xử lý dữ liệu
        void processData(){}
       
        // Lưu trữ dữ liệu
        void saveData(){}

        // Gửi dữ liệu đi
        void sendData(){}
};

```
- Ở đây ta có một class đang xử lý 3 tasks cùng một lúc, điều này sẽ gây nên một vấn đề lớn đó chính là overload. Dẫn đến khó kiểm soát và quản lý, chỉ cần 1 module gặp vấn đề thì sẽ ảnh hưởng đến cả 1 hệ thống.
- Khi này, ta áp dụng nguyên tắc thứ nhất, đó là **đơn trách nhiệm**, phân tách công việc như sau:

```cpp
// Class xử lý dữ liệu
class Process
{
    public:
        void processData(){}
};

// Class lưu trữ dữ liệu
class Save
{
    public:
        void saveData(){}
};

// Class gửi dữ liệu
class Send
{
    public:
        void sendData(){}
};

```

# 2. Open/Closed Principle (Nguyên tắc đóng mở)
- Cho phép **mở rộng** nhưng **không sửa đổi mã cũ**. Khi thêm tính năng mới, hãy thêm mã mới thay vì chỉnh sửa mã hiện có.
- Tránh sửa đổi mã nguồn cũ, giúp phần mềm ổn định hơn.
- Tức là ta sẽ viết những tính năng, thay đổi mới hoàn toàn tách biệt so với mã cũ. Và ta có thể ứng dụng tính đa hình đã được tìm hiểu trong nội dung trước.
- Lấy ví dụ:

```cpp
class SpeedAlert
{
    public:
        void sendAlert(double speed)
        {
            if (speed > 100)
            {
                cout << "Cảnh báo: Vượt quá tốc độ!" << endl;
            }
        }
};

```

- Ở đây là một mã nguồn gốc, thay vì viết đè lên hàm sendAlert với các câu lệnh if-else thì ta hoàn toàn có thể viết tách biệt ra, kết hợp với nguyên tắc đơn trách nhiệm để có được một hệ thống quản lý cảnh báo tốt.

```cpp
class Device_Alert{
    public:
        virtual void sendAlert(double speed) = 0;
};

class Sound_Alert : public Device_Alert{
    public:
        void sendAlert(double speed) override{
            if (speed > 100){
                cout << "Cảnh báo: Vượt quá tốc độ! (Âm thanh)" << endl;
            }
        }
};

class LED_Alert : public Device_Alert{
    public:
        void sendAlert(double speed) override{
            if (speed > 100){
                cout << "Cảnh báo: Vượt quá tốc độ! (Đèn LED)" << endl;
            }
        }
};

void handleSpeedAlert(Device_Alert *alert, double speed)
{ 
alert->sendAlert(speed); 
}

```

# 3. L - Liskov's Substitution Principle (Nguyên tắc thay thế Liskov)
- Một lớp con có thể thay thế lớp cha mà không làm thay đổi tính đúng đắn của class cha.
- Nghĩa là chúng ta sẽ không cố gắng định nghĩa đè lên tính chất cũ của class cha.
- Lấy ví dụ:

```cpp
class Car{
    public:
        virtual void refuel(){
            cout << "Đổ xăng" << endl;
        }
};
   
class ElectricCar : public Car{
    public:
        void refuel() override{
            // Xe điện không thể đổ xăng
            cout << "Xe điện không dùng xăng!" << endl;
        }
};


```

- Ta thấy class con ElectricCar đang cố gắng định nghĩa đè lại class Cha là Car. Khi này sẽ gặp một vấn đề đó là việc định nghĩa lại hàm refuel của class cha sẽ không còn giữ đúng tính chất của class cha nữa.
- Nên chúng ta có thể xử lý bằng cách là định nghĩa lại một class cha trừu tượng. Hay nói cách khác, class sẽ đưa ra một phương thức mơ hồ để class con có thể tùy ý xử lý và ứng biến
- Và chúng ta hoàn toàn có thể ứng dụng tính đa hình và kế thừa đã được tìm hiểu:

```cpp
class Vehicle{
    public:
        virtual void rechargeOrRefuel() = 0;
};
   
class GasCar : public Vehicle{
    public:
        void rechargeOrRefuel() override{
            cout << "Đổ xăng" << endl;
        }
};

class ElectricCar : public Vehicle{
    public:
        void rechargeOrRefuel() override{
            cout << "Sạc pin" << endl;
        }
};

```

# 4. I -Interface Segregation (Phân tách Giao diện)
- Một class không nên bị ép buộc triển khai những phương thức mà nó không sử dụng.
- Tránh việc các class con phải cài đặt các phương thức không liên quan.
- Hay nói cách khác là những phương thức nào không phải là phương thức chung cho tất cả mọi class con thì đều nên phân tách riêng ra.
- Lấy ví dụ:

```cpp
class IVehicle
{
    public:
        virtual void drive() = 0;       // phương tiện có thể lái
        virtual void refuel() = 0;      // tiếp nhiên liệu
        virtual void loadCargo() = 0;   // chở hàng hóa
};

class Bike : public IVehicle
{
    public:
        void drive() override
        {
            cout << "Lái xe đạp" << endl;
        }

        void refuel() override {}       // Không hợp lý với xe đạp
        void loadCargo() override {}       
}
```

- Ở đây có thể thấy, với xe đạp thì không cần phải đổ nhiên liệu hay chở hàng hóa, nên các phương thức kia khi kế thừa sẽ là không cần thiết.
- Vì thế tối ưu, ta sẽ phân tách các phương thức này ra thành các class.

```cpp

// Interface cho phương tiện có thể lái
class IDriveable
{
    public:
        virtual void drive() = 0;
};
   
// Interface cho phương tiện có thể lái
class IFuelable
{
    public:
        virtual void refuel() = 0;
};

// Interface cho phương tiện có thể lái
class ICargo
{
    public:
        virtual void loadCargo() = 0;
};


// Xe ô tô
class Car : public IDriveable, public IFuelable, public ICargo
{
public:
    void drive() override{ cout << "Lái ô tô" << endl; }

    void refuel() override{ cout << "Đổ xăng" << endl; }

    void loadCargo() override{ cout << "Chở hàng" << endl; }
};

// xe đạp
class Bike : public IDriveable, public ICargo
{
    public:
        void drive() override{ cout << "Lái xe đạp" << endl; }

        void loadCargo() override{ cout << "Chở hàng" << endl; }
};

```

# 5. D - Dependency Inversion Principle (DIP) - Nguyên tắc đảo ngược phụ thuộc
- Các thành phần quan trọng trong chương trình không nên dựa trực tiếp vào chi tiết cụ thể mà nên dựa vào một **giao diện chung**. Điều này giúp phần mềm linh hoạt hơn, dễ mở rộng và thay đổi mà không làm ảnh hưởng đến các phần khác.

- Ví dụ: thay vì một công tắc chỉ bật được đèn, ta làm nó điều khiển bất kỳ thiết bị bào bằng cách dùng một giao diện chung.

```cpp
class LightBulb
{
    public:
        void turnOn() { /* Bật đèn */ }
};

class Switch
{
    private:
        LightBulb bulb;
       
    public:
        void operate() { bulb.turnOn(); }
};

```

- Ở đây ta chỉ sử dụng switch như một công tắc bật đèn, nhưng khi có nhiều class hơn nhưng cũng cùng được điều khiển bằng công tắc, ta hoàn toàn có thể đặt công tắc này như một giao diện chung.

```cpp
class Device{
    public:
        virtual void turnOn() = 0;
};

class LightBulb : public Device{
    public:
        void turnOn() override { /* Bật đèn */ }
};

class Fan : public Device{
    public:
        void turnOn() override { /* Bật quạt */ }
};

class Switch{
    private:
        Device *device;

    public:
        Switch(Device *d) : device(d){}
        void operate() { device->turnOn(); }
};

```

## Tóm tắt nội dung
- SRP giúp chia nhỏ thành nhiều module.
- OCP giúp mở rộng mà không sửa đổi cái cũ.
- LSP đảm bảo lớp con kế thừa không phá vỡ chương trình.
- ISP giúp interface gọn gàng.
- DIP giúp kết nối các module qua abstraction.

![Image](https://github.com/user-attachments/assets/8f69ba3b-b310-42c8-8bde-21fca3e2eb66)

- Nhìn vào sơ đồ có thể thấy được mối liên hệ giữa các nguyên tắc, trong đó nguyên tắc quan trọng nhất vẫn là **đơn trách nhiệm**. Sau đó chúng ta sẽ xét xem để hình thành nguyên tắc nào, ta cần đảm bảo nguyên tắc nào.
