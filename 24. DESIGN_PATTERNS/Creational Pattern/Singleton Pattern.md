# NỘI DUNG TÌM HIỂU
- Chúng ta sẽ đi tìm hiểu mẫu đầu tiên trong nhóm Creational Pattern (Nhóm khởi tạo). Đó chính là **Singleton Pattern - Mẫu thiết kế đơn thể**.
- Chúng ta sẽ tìm hiểu về:
  - Khái niệm
  - Kiến thức áp dụng
  - Các kiến thức liên quan
  - Phân tích từng bước
  - Ví dụ sử dụng

# KHÁI NIỆM
- Singleton là một mẫu thiết kế thuộc nhóm **Creational (mẫu khởi tạo)**, nó đảm bảo rằng một class chỉ có một đối tượng duy nhất được tạo ra, và cung cấp một phương thức
 để truy cập đến đối tượng đó từ bất kỳ đâu trong chương trình.
- Singleton đảm bảo rằng một lớp chỉ có duy nhất một thể hiện (instance) trong toàn bộ chương trình và cung cấp một điểm truy cập toàn cục đến thể hiện đó.
- Singleton thường sử dụng cho những hệ thống chỉ cần một phiên bản duy nhất như: kết nối cơ sở dữ liệu, bộ nhớ đệm (cache), logger để ghi log, hoặc cấu hình hệ thống.

# CÁC THÀNH PHẦN CHÍNH CỦA SINGLETON PATTERN
**- Private Constructor:** Đảm bảo rằng không ai có thể khởi tạo đối tượng từ bên ngoài class.
**- Static Instance:**
  - Đối tượng tĩnh duy nhất của class.
  - Không thể tạo ra nhiều hơn một đối tượng của class Singleton.
**- Static Method:** Phương thức để truy cập đến đối tượng duy nhất từ mọi nơi trong chương trình.

# PHÂN TÍCH KIẾN THỨC
- Đó là các khái niệm của singleton pattern. Nhưng hẳn ai ban đầu khi đọc vào cũng sẽ chẳng hiểu gì. Thế nên bây giờ chúng ta sẽ cùng phân tích chi tiết từng ý một.

## Đặt vấn đề
- Trước tiên hãy bắt đẩu với câu hỏi tại sao lại cần dùng đến Singleton Pattern?
- Đặt vấn đề khi lập trình vi điều khiển với các chân GPIO, Timer,.. Mỗi chân này đều có địa chỉ cố định, vậy thì khi ta làm việc với các chân đó, ta sẽ tạo các object để ghi những giá trị lên
các địa chỉ cố định này, vậy thì khi này việc tạo nhiều object mà chỉ ghi giá trị lên cùng một địa chỉ thì nó sẽ bị tiêu tốn tài nguyên bộ nhớ của chúng ta.
- Vậy nên singleton sẽ giúp chúng ta tạo ra nhiều object nhưng các object đó chỉ dùng chung một địa chỉ duy nhất mà thôi, nó sẽ giúp tối ưu bộ nhớ chương trình hơn rất nhiều.

## Phân tích các khái niệm
- Tiếp theo chúng ta sẽ đi đến câu hỏi cái này là gì và có tác dụng gì?
- Đầu tiên hãy nhìn vào một đoạn code của singleton pattern.

```cpp
#include <iostream>
#include <string>
using namespace std;

class Logger {
private:
    static Logger* instance;

    // Constructor private -> không cho new từ bên ngoài
    Logger() {
        cout << "[Logger] Constructor được gọi -> Logger được tạo ra!\n";
    }

public:
    static Logger* getInstance() {
        cout << "[Logger] getInstance() được gọi.\n";

        if (instance == nullptr) {
            cout << "[Logger] instance chưa có -> tạo mới\n";
            instance = new Logger(); //Gán biến instace cho object được tạo ra lần đầu tien
        } else {
            cout << "[Logger] instance đã tồn tại -> trả về instance cũ\n";
        }

        return instance;
    }

    void log(string message) {
        cout << "[Log] " << message << endl;
    }
};

// Khởi tạo con trỏ static ban đầu = nullptr
Logger* Logger::instance = nullptr;

int main() {
    cout << "== Gọi logger1 lần đầu ==\n";
    Logger* logger1 = Logger::getInstance();
    logger1->log("Ghi log lần 1");

    cout << "\n== Gọi logger2 lần hai ==\n";
    Logger* logger2 = Logger::getInstance();
    logger2->log("Ghi log lần 2");

    cout << "\n== So sánh logger1 và logger2 ==\n";
    if (logger1 == logger2) {
        cout << "Cùng một thể hiện Logger!\n";
    } else {
        cout << "Logger bị tạo nhiều lần!\n";
    }

    return 0;
}
```

- Trước tiên hãy cùng làm rõ khái niệm instance (thể hiện). Có thể hiểu đơn giản rằng instance và object là một, nhưng khi nói đến instance người ta sẽ hiểu rằng mình đang nhấn mạnh tính **duy nhất** trong singleton pattern.
- Bây giờ hãy cũng phân tích kỹ hơn:
    - Khởi tạo instance: chúng ta dùng từ khóa static có hai mục đích:
      - Đây là biến của **toàn class**.
      - Biến này chỉ truy cập được bằng static method.
      - Static Method cũng chỉ truy cập được biến static.
    - Chúng ta sử dụng con trỏ nhằm lưu địa chỉ của đối tượng khi khởi tạo lần đầu tiên. Tức là đối với singleton pattern, chúng ta sẽ khởi tạo một đối tượng, và đối tượng này chỉ được khởi tạo bằng static method, và ta
sẽ gán địa chỉ của object đó cho biến instance, vậy là instance đã trở thành object và ta không thể tạo thêm một object nào khác nữa.
    - Hãy cùng xem output của đoạn code trên:
    ```cpp
    == Gọi logger1 lần đầu ==
    [Logger] getInstance() được gọi.
    [Logger] instance chưa có -> tạo mới
    [Logger] Constructor được gọi -> Logger được tạo ra!
    [Log] Ghi log lần 1
    
    == Gọi logger2 lần hai ==
    [Logger] getInstance() được gọi.
    [Logger] instance đã tồn tại -> trả về instance cũ
    [Log] Ghi log lần 2
    
    == So sánh logger1 và logger2 ==
    Cùng một thể hiện Logger!
    ```


