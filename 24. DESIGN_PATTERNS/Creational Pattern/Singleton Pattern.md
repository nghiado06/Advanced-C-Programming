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
            instance = new Logger();
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

