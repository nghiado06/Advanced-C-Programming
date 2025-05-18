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

# CÁC BIẾN THỂ CỦA SINGLETON PATTERN
- Singleton có các biến thể như: Eager initialization, Lazy Initialization, Thread Safe, Double Check Locking.
- Các biến thể này cũng chỉ có một mục đích đó là tạo một instance duy nhất, những sẽ khác cách khởi tạo biến instance này để phù hợp cho từng trường hợp ứng dụng.
- Bây giờ chúng ta sẽ cùng tìm hiểu từng biến thể.

## EAGER INITIALIZATION (KHỞI TẠO SỚM)
- Như cái tên của mình, mục tiêu của eager initialization chính là khởi tạo biến instance **từ sớm** , hay nói cách khác là nó sẽ khởi tạo biến instance ngay từ lúc bắt đầu run chương trình, trước cả khi nó được
 sử dụng. Tức là nói dân giã thì nó **nôn nóng** khởi tạo từ sớm dùng chưa biết có dùng tới hay không.
- **Ưu điểm:**
  - Đơn giản: Không cần kiểm tra nullptr, không cần new
  - An toàn trong môi trường đa luồng vì được khởi tạo sẵn từ đầu --> Không có race condition
- **Nhược điểm**:
  - Có thể lãng phí tài nguyên nếu singleton chưa bao giờ được dùng đến
  - Không linh hoạt vì khó kiểm soát được thời điểm khởi tạo

- Lấy ví dụ:

```cpp
#include <iostream>
using namespace std;

class Logger {
private:
    static Logger instance; // tạo ngay từ khi chương trình khởi động
    Logger() {
        cout << "[Logger] Constructor được gọi -> Logger được tạo!\n";
    }

public:
    static Logger& getInstance() {
        return instance;  // trả về tham chiếu tới thể hiện đã có sẵn
    }

    void log(string message) {
        cout << "[Log] " << message << endl;
    }
};

// Phần bắt buộc: khởi tạo biến tĩnh ở ngoài class
Logger Logger::instance;  // <- được gọi NGAY KHI chương trình bắt đầu
```

- Trong C++ thì đối với eager việc ta có thể lược qua việc kiểm tra điều kiện tồn tại, nên ta có thể sử dụng luôn việc khởi tạo bằng biến thông thường và kết hợp với reference để tối ưu hóa bộ nhớ.
- Ta vẫn có thể sử dụng con trỏ đối với eager nhưng điều đó sẽ làm ta tiêu tốn thêm vùng nhớ heap cho con trỏ:

```cpp
#include <iostream>
using namespace std;

class Logger {
private:
    static Logger* instance = new Logger(); // tạo ngay từ khi chương trình khởi động
    Logger() {
        cout << "[Logger] Constructor được gọi -> Logger được tạo!\n";
    }

public:
    static Logger* getInstance() {
        return instance;  // trả về tham chiếu tới thể hiện đã có sẵn
    }

    void log(string message) {
        cout << "[Log] " << message << endl;
    }
};

// Phần bắt buộc: khởi tạo biến tĩnh ở ngoài class
Logger* Logger::instance;  // <- được gọi NGAY KHI chương trình bắt đầu
```

- Các ví dụ thực tế dùng eager:

  - Ghi log khởi động hệ thống
  - Khởi tạo hệ thống cấu hình mặc định
  - Quản lý quyền truy cập vào thiết bị phần cứng (driver) luôn bật từ đầu.

## LAZY INITIALIZATION (KHỞI TẠO TRỄ)
- Ngược lại với eager, thì lazy hướng đến mục tiêu chỉ tạo đối tượng khi lần đầu cần dùng đến chứ không tạo từ đầu chương trình.
- Điều này sẽ giúp tiết kiệm bộ nhớ tài nguyên và đặc biệt nếu singleton chiếm nhiều tài nguyên mà chưa chắc đã cần đến.
- **Ưu điểm:**
  - Tiết kiệm tài nguyên vì sẽ không tạo nếu không cần
  - Kiểm soát được thời điểm khởi tạo
- **Nhược điểm:**
  - Không an toàn trong đa luồng nếu không được xử lý. Giả định như nếu 2 thread cùng gọi getInstance cùng lúc nullptr thì sẽ tạo ra 2 đối tượng.
  - Cần thêm code để đồng bộ hoặc bảo vệ.

- Ví dụ:

```cpp
#include <iostream>
using namespace std;

class Logger {
private:
    static Logger* instance;  // con trỏ tới thể hiện duy nhất
    Logger() {
        cout << "[Logger] Constructor được gọi → Logger được tạo!\n";
    }

public:
    static Logger* getInstance() {
        cout << "[Logger] getInstance() được gọi.\n";

        if (instance == nullptr) {
            cout << "[Logger] instance chưa có → tạo mới\n";
            instance = new Logger();
        } else {
            cout << "[Logger] instance đã tồn tại → dùng lại\n";
        }

        return instance;
    }

    void log(string message) {
        cout << "[Log] " << message << endl;
    }
};

// Gán instance ban đầu là nullptr
Logger* Logger::instance = nullptr;
```

- Đây chính là ví dụ ban đầu mà chúng ta đã dùng, nó sẽ thêm điều kiện kiểm tra if nullptr và chỉ khởi tạo nếu nó không phải null, tức là khi chưa được khởi tạo.

## THREAD-SAFE
- Như đã nói ở trên, đối với lazy initialization sẽ rất nguy hiểm khi làm việc trong môi trường đa luồng nếu không được kiểm tra xử lý đúng cách.
- Chính vì thế các tác giả của design patterns đã phát minh ra các biến thể thread-safe để giải quyết vấn đề đa luồng đó.
- Trong đó có 3 giải pháp chính:
  - Sử dụng mutex
  - Sử dụng static local variable
  - Sử dụng double-checked locking (Tối ưu)
- Vậy bây giờ chúng ta hãy cùng phân tích khái niệm và ưu nhược điểm của nó nhé.

### MUTEX
- Trước tiên hãy làm rõ mutex là gì?
- mutex là một đối tượng khóa (lock) trong C++ nằm trong thư viện <mutex> dùng để đồng bộ (synchronization) giữa các luồng (thread) khi cùng truy cập vào một tài nguyên chia sẻ như:
  - Biến toàn cục
  - File
  - Database
  - Singleton Instance

 - Mục tiêu của mutex đó chính là đảm bảo chỉ có 1 thread được phép vào "vùng nguy hiểm" tại một thời điểm duy nhất, còn các thread khác phải chờ.
- Cú pháp khai báo:

```cpp
#include <mutex>

std::mutex mtx;
```

-  Các thao tác chính với mutex:
  - mtx.lock(): thread gọi lock đầu tiên sẽ “giữ khóa”. Các thread khác sẽ chờ.
  - mtx.unlock(): trả khóa cho các thread khác dùng

  ```cpp
  std::mutex mtx;
  
  void printSafe(string msg) {
      mtx.lock();
      cout << msg << endl;
      mtx.unlock();
  }
  ```

  - std::lock_guard<std::mutex> lock(mtx); : RALL Style - tự động lock khi tạo và unclock khi ra khởi scope - Đây là cách an toàn và được khuyên dùng nhất vì nếu lock và unlock thủ công có thể làm ta dễ quên.

  ```cpp
  void printSafe(string msg) {
    lock_guard<mutex> lock(mtx);  // auto lock
    cout << msg << endl;          // tự unlock khi ra khỏi hàm
  }
  ```

- Quay trở lại với singleton pattern, vì sao ta lại cần dùng mutex?
- Trong lazy initialization, ta có đoạn:

```cpp
if (instance == nullptr) {
    instance = new Singleton();
}
```

- Nếu 2 thread chạy cùng lúc, cả hai thấy nullptr --> Cùng tạo --> Vi phạm Singleton --> Cần mutex để ngăn chặn 1 thread tạo khi thread khác đang tạo.
- Lấy ví dụ:

```cpp
#include <iostream>
#include <mutex>
using namespace std;

class Logger {
private:
    static Logger* instance;
    static mutex mtx;

    Logger() {
        cout << "[Logger] Logger được tạo!\n";
    }

public:
    static Logger* getInstance() {
        cout << "[getInstance] Được gọi.\n";

        lock_guard<mutex> lock(mtx);  // TỰ ĐỘNG LOCK

        if (instance == nullptr) {
            cout << "[getInstance] Chưa có instance → tạo mới\n";
            instance = new Logger();
        } else {
            cout << "[getInstance] Đã có instance → dùng lại\n";
        }

        return instance;
    }

    void log(string msg) {
        cout << "[Log] " << msg << endl;
    }
};

Logger* Logger::instance = nullptr;
mutex Logger::mtx;
```

## STATIC LOCAL VARIABLE
- Mục tiêu của việc sử dụng biến static cục bộ để tạo thread-safe để khởi tạo trễ nhưng vẫn tự động an toàn với đa luồng và không cần mutex thủ công bằng cách kết hợp tham chiết trong C++
- **Ưu điểm:**
  - Thread-safe tự động mà không cần mutex
  - Gọn và sạch
  - Không bị memory leak vì không cần cấp phát động
- **Nhược điểm:**
  - Không kiểm soát được thời gian hủy nếu cần quản lý vòng đời chi tiết (thực chất điều này cũng hiếm khi cần).
- Lấy ví dụ:

```cpp
#include <iostream>
using namespace std;

class Logger {
private:
    Logger() {
        cout << "[Logger] Constructor → Logger được tạo!\n";
    }

public:
    static Logger& getInstance() {
        static Logger instance;  // Biến static cục bộ
        return instance;
    }

    void log(string msg) {
        cout << "[Log] " << msg << endl;
    }
};
```
- Tới đây có lẽ nhiều người vẫn sẽ thắc mắc rằng nếu nó tạo cục bộ như vậy thì nó sẽ an toàn chỗ nào?.
- Thực chất trình biên dịch sẽ tự tạo cơ chế đồng bộ (synchronization) phía sau để:
  - Đảm bảo instance chỉ được khởi tạo đúng 1 lần duy nhất.
  - Nếu nhiều thread cùng vào các thread khác sẽ chờ đến khi thread đầu tiên khởi tạo xong.
- Trình biên dịch sẽ tạo ra một flag để kiểm tra xem biến đã được khởi tạo chưa (is_initialized).
- Hoặc dùng một chơ chế mutex hoặc atomic guard được ẩn đi.

- Ví dụ mô phỏng ý tưởng bên trong, tất nhiên bạn chẳng cần viết như vậy vì trình biên dịch đã tự lo sẵn:

```cpp
static bool is_initialized = false;
static mutex mtx;

Logger& getInstance() {
    lock_guard<mutex> lock(mtx);     // ẩn trong compiler
    if (!is_initialized) {
        static Logger instance;      // thực chất tạo ở đây
        is_initialized = true;
        return instance;
    }
    return instance;
}
```

## DOUBLE-CHECKED LOCKING (DCL)
- Mục tiêu của DCL chính là tối ưu hóa lazy trong môi trường đa luồng bằng cách chỉ khóa (lock) khi thực sự cần thiết, tức là:
  - Không khóa mỗi lần gọi getInstance
  - Nhưng vẫn đảm bảo thread-safe
  - Đặt vấn đề
    - Lazy Singleton đơn giản:
    ```cpp
    if (instance == nullptr) {
    instance = new Singleton();
    }
    ```
    --> Không thread-safe
    - Thread-safe bằng mutex:
    ```cpp
    lock_guard<mutex> lock(mtx);
    if (instance == nullptr)
      instance = new Singleton();
    ```
    --> Luôn bị lock mỗi lần gọi getInstance() mặc dù instance đã tồn tại --> Hiệu năng thấp.

==> Vậy thì DCL sinh ra chính là để giải quyết tất cả bằng cách kiểm tra 2 lần.
- Ý tưởng của DCL:
  - Lần 1: Kiểm tra instance == nullptr trước khi lock. --> Nếu đã tồn tại thì không lock nữa mà trả luôn.
  - Lần 2: Nếu vẫn chưa tồn tại --> Lock lại --> Kiểm tra lần nữa rồi mới tạo
- Lấy ví dụ:

```cpp
#include <iostream>
#include <mutex>
using namespace std;

class Logger {
private:
    static Logger* instance;
    static mutex mtx;

    Logger() {
        cout << "[Logger] Logger được tạo!\n";
    }

public:
    static Logger* getInstance() {
        if (instance == nullptr) {  // Check 1 - không đồng bộ
            lock_guard<mutex> lock(mtx);  // Khóa khi cần
            if (instance == nullptr) {    // Check 2 - đã khóa
                instance = new Logger();
            }
        }
        return instance;
    }

    void log(string msg) {
        cout << "[Log] " << msg << endl;
    }
};

// Khởi tạo biến tĩnh
Logger* Logger::instance = nullptr;
mutex Logger::mtx;

```
- Phân tích kỹ flow của nó:
  - Thời điểm 1: Thread A gọi getInstance()
  
  ```cpp
  if (instance == nullptr) // Đúng vì chưa tạo --> A tiến vào trong khối if để tạo Singleton
  ```
  
  - Thời điểm 2: Thread B gọi getInstance() gần như cùng lúc với A
  
  ```cpp
  if (instance == nullptr) // B cũng thấy nullptr --> B cũng vào trong if
  ```

  - Cả 2 thread đều đến dòng lock_guard<mutex> lock()mtx;
  - Thread A lấy được mutex trước --> Vào trong
  - Đến dòng:

  ```cpp
  if (instance == nullptr)  // vẫn đúng
    instance = new Singleton(); // Khởi tạo luôn
  ```
  - Thread B vào sau bị mtx giữ chờ đến khi A xong thì B mới tiến vào kiểm tra:

  ```cpp
  if (instance == nullptr)  // Phát hiện đã khởi tạo rồi --> Không khởi tạo nữa mà chỉ trả về instance. Nếu không có điều kiện kiểm tra lần 2 thì thread B sẽ tạo thêm một instance mới --> Không còn là singleton nữa
    instance = new Singleton(); 
  ```

  - **Ưu điểm:**
    - Tối ưu hiệu năng, chỉ tạo lock khi thực sự cần tạo instance
    - An toàn đa luồng
    - Không lock ở mọi lần gọi

## ÁP DỤNG THỰC TẾ
- Chúng ta sẽ cùng nhất lấy một ví dụ áp dụng singleton trong lập trình vi điều khiển.
- Các bạn có thể vận dụng các lý thuyết vừa rồi và phân tích cách chương trình hoạt động nhé.

```cpp
#include <iostream>
#include "stm32f10x.h"  
using namespace std;

class UART{
    private:
        static UART* instance;  
        UART(){ initUART(); }

        void initUART(){
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
            USART_InitTypeDef USART_InitStructure;

            USART_InitStructure.USART_BaudRate = 9600;
            USART_InitStructure.USART_WordLength = USART_WordLength_8b;
            USART_InitStructure.USART_StopBits = USART_StopBits_1;
            USART_InitStructure.USART_Parity = USART_Parity_No;
            USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
            USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

            USART_Init(USART1, &USART_InitStructure);
            USART_Cmd(USART1, ENABLE);
        }

    public:
        static UART* getInstance(){
            if (instance == nullptr){
                instance = new UART();  // Tạo instance nếu chưa có
            }
            return instance;
        }

        void sendData(uint8_t data){
            while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
            USART_SendData(USART1, data);
        }

        uint8_t receiveData(){
            while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);
            return USART_ReceiveData(USART1);
        }
};

UART* UART::instance = nullptr;

int main(){
    UART* uart = UART::getInstance();

    // Gửi một ký tự qua UART
    uart->sendData('H');

    // Nhận một ký tự từ UART
    uint8_t received = uart->receiveData();

    while (1){
        // Thực hiện công việc liên quan khác
    }
}
```


## TỔNG KẾT
- Vậy là chúng ta đã tìm hiểu được cơ bản cách sử dụng singleton và các biến thể sử dụng trong các trường hợp nhất định.





