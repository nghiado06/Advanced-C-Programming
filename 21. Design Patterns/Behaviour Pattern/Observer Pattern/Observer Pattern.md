
# NỘI DUNG TÌM HIỂU
- Chúng ta sẽ cùng tìm hiểu một mẫu thiết kế thuộc nhóm **Behavioral Pattern (Nhóm hành vi)** – đó là **Observer Pattern – Mẫu thiết kế quan sát viên**.
- Nội dung tìm hiểu gồm:
  - Khái niệm
  - Kiến thức áp dụng
  - Các thành phần liên quan
  - Phân tích từng bước
  - Ví dụ sử dụng và ứng dụng thực tế

# KHÁI NIỆM
- Observer là một mẫu thiết kế **Behavioral**, cho phép một đối tượng (gọi là **Subject**) thông báo tới các đối tượng khác (gọi là **Observer**) mỗi khi trạng thái của nó thay đổi – mà **không cần gắn chặt với các lớp đó**.
- Tóm gọn:
  - Subject chứa dữ liệu chính.
  - Các Observer sẽ “nghe ngóng” và **tự động phản hồi** khi Subject thay đổi.

# CÁC THÀNH PHẦN CHÍNH CỦA OBSERVER PATTERN
- **Subject (Chủ thể)**: Quản lý danh sách các observer, cho phép thêm/xóa và notify mỗi khi dữ liệu thay đổi.
- **Observer (Quan sát viên)**: Định nghĩa interface `update()` để phản hồi khi Subject thay đổi.
- **ConcreteSubject / ConcreteObserver**: Các lớp triển khai cụ thể.

# PHÂN TÍCH KIẾN THỨC

## Đặt vấn đề
- Nếu bạn từng làm các ứng dụng mà có nhiều thành phần cần cập nhật khi một giá trị thay đổi (ví dụ: thời gian, nhiệt độ, giá cổ phiếu), bạn sẽ dễ dàng thấy được giá trị của Observer Pattern.
- Thay vì hardcode việc thông báo thủ công cho từng thành phần, chúng ta muốn một **cơ chế linh hoạt, tự động**, nơi các thành phần tự động cập nhật khi có thay đổi.

## Phân tích hoạt động
Giả sử ta có cảm biến nhiệt độ và muốn:
- Hiển thị trên màn hình LCD.
- Gửi cảnh báo nếu vượt ngưỡng.
- Ghi log dữ liệu.

Thay vì viết trong `setTemperature()`:

```cpp
// Cách chưa được tối ưu
lcdDisplay.update(temp);
alarm.update(temp);
logger.update(temp);
```

Ta viết:

```cpp
notifyObservers();  // Linh hoạt và mở rộng dễ dàng
```

# VÍ DỤ CỤ THỂ (C++)

```cpp
class IObserver {
public:
    virtual void update(float temperature) = 0;
};

class TemperatureSensor {
    vector<IObserver*> observers;
    float temperature;

public:
    void attach(IObserver * obs)
    {
        observers.push_back(obs);
    }

    void detach(IObserver * obs)
    {
        observers.erase(remove(observers.begin(), observers.end(), obs), observers.end());
    }

    void setTemperature(float newTemp)
    {
        temperature = newTemp;
        notifyObservers();
    }

    void notifyObservers()
    {
        for (auto obs : observers)
        {
            obs->update(temperature);
        }
    }
};

class LCDDisplay : public IObserver {
public:
    void update(float t) override {
        cout << "[LCD] Nhiệt độ hiện tại: " << t << " C\n";
    }
};

class Alarm : public IObserver {
public:
    void update(float t) override {
        if (t > 50)
            cout << "[ALARM] Quá nhiệt! " << t << " C\n";
    }
};
```

# CÁC TRƯỜNG HỢP ÁP DỤNG THỰC TẾ

## Trường hợp 1: Hệ thống cảnh báo công nghiệp
- Một cảm biến báo khói là Subject.
- Các thiết bị như: còi hú, tin nhắn, đèn nháy là Observer.
- Mỗi khi cảm biến báo khói, tất cả Observer sẽ nhận được cảnh báo.

## Trường hợp 2: Giao diện GUI
- Khi người dùng thay đổi dữ liệu → cập nhật nhiều thành phần (form, bảng, đồ thị).
- Rất phổ biến trong các framework như Qt, JavaFX, hoặc cả frontend JS (React).

## Trường hợp 3: Lập trình vi điều khiển (MCU)
- Trong hệ thống nhúng, bạn có thể dùng Observer để:
  - Các module (LCD, Logger, RF Transmitter) cùng nhận sự kiện từ một cảm biến chung.
  - Khi một biến flag thay đổi → tất cả các module phản hồi tương ứng (cảnh báo, hiển thị, lưu log).

# LỢI ÍCH VÀ NHƯỢC ĐIỂM

| Ưu điểm                                                  | Nhược điểm                                          |
| -------------------------------------------------------- | --------------------------------------------------- |
| Mở rộng dễ dàng – thêm Observer mới mà không sửa Subject | Có thể khó quản lý khi quá nhiều Observer           |
| Giảm sự phụ thuộc giữa các module                        | Có thể bị gọi nhiều lần nếu không kiểm soát         |
| Dễ tích hợp và kiểm thử                                  | Không phù hợp với hệ thống quá đơn luồng & đơn giản |

# TỔNG KẾT
- Observer Pattern là công cụ mạnh mẽ giúp thiết kế các hệ thống phản ứng theo sự thay đổi trạng thái một cách **tự động, linh hoạt và mở rộng**.
- Rất phù hợp trong các ứng dụng như:
  - Hệ thống nhúng đa module.
  - Ứng dụng GUI / Event-driven.
  - Tích hợp mạng / giao tiếp dữ liệu.
