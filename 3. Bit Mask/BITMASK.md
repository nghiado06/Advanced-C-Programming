## Tìm hiểu về Kỹ thuật Bitmask
- Khái niệm Bitmask
- Thư viện stdint
- Toán tử với Bitmask
- Quy tắc dịnh bit
- Một số kỹ thuật ứng dụng Bitmask
# 1. Khái niệm
- Bitmask là một kỹ thuật sử dụng các bit để lưu trữ và thao tác với các cờ (flags) hoặc trạng thái. Có thể sử dụng bitmask để đặt, xóa và kiểm tra trạng thái của các bit cụ thể trong một từ (word).
- Bitmask thường được sử dụng để tối ưu hóa bộ nhớ, thực hiện các phép toán logic trên một cụm bit, và quản lý các trạng thái, quyền truy cập, hoặc các thuộc tính khác của một đối tượng.
# 2. Thư viện stdint
- Thư viện stdint cho phép chúng ta khai báo các kiểu dữ liệu int, uint, .. nhưng với số bit xác định.
<br>
Lấy ví dụ:

```cpp
#include <stdio.h>
#include <stdint.h>

int8_t, uint8_t: 1 byte (8 bits)
int16_t, uint16_t: 2 bytes (16 bits)
int32_t, uint32_t: 4 bytes (32 bits)
```

- Khi khai báo các kiểu dữ liệu này mặc dù có giảm kích thước dữ liệu đáng kể nhưng vẫn chưa thực sự tối ưu. Ví dụ khi khai báo các biến chỉ với 0/1 bit thì kích thước vẫn sẽ thừa rất nhiều.
- Khi đó việc sử dụng bitmask là một phương pháp giúp tối ưu hóa kích thước hơn. Ta sẽ quản lý bit trong cùng 1 biến.

```cpp
uint8_t user = 0bxxxxxxxx;
```
- Trong đó 0bxxxxxxxx là giá trị của biến user được biểu diễn dưới dạng nhị phân. Điều này có nghĩa là chúng ta chỉ sử dụng 1 địa chỉ biến duy nhất là biến user và thay đổi giá trị của nó dưới dạng nhị phân để thao tác bit trên dạng nhị phân đó.
# 3. Toán tử với Bitmask
## NOT Bitwise (~)
Toán tử này dùng để đảo ngược bit lại: 1 --> 0; 0 --> 1
```cpp
uint8_t user = 0b01011100;
user1 = ~user1;
//user1 = 0b10100011;
```

## AND Bitwise (&)
Toán tử này dùng để thực hiện phép so sánh giữa từng cặp bit theo quy tắc.
<br>
| X   | Y   | X & Y | X \| Y | X ^ Y |
| --- | --- | ----- | ------ | ----- |
| 0   | 0   | 0     | 0      | 0     |
| 0   | 1   | 0     | 1      | 1     |
| 1   | 0   | 0     | 1      | 1     |
| 1   | 1   | 1     | 1      | 0     |

```cpp
uint8_t user1 = 0b01011100;
uint8_t user2 = 0b11011010;
int result = user1 & user2;
//result = 0b01011000 
```
## OR Bitwise (|)
Toán tử nảy dùng để thực hiện phép so sánh cũng thoe quy tắc trên.
```cpp
uint8_t user1 = 0b01011100;
uint8_t user2 = 0b11011010;
int result = user1 | user2;
//result = 0b11011110
```
## XOR Bitwise (^)
Tương tự như ở trên
```cpp
uint8_t user1 = 0b01011100;
uint8_t user2 = 0b11011010;
int result = user1 ^ user2;
//result = 0b10000110
```
# 4. Quy tắc dịch bit (Bit shifting rule)
- Dùng để di chuyển bit sang trái hoặc sang phải.
- Trong trường hợp (TH1) << (Shift Left), các bit ở bên phải sẽ được dịch sang trái, và các bit trái cùng sẽ được đặt giá trị 0.
- Trong trường hợp (TH2) >> (Shift Right), các bit ở bên trái sẽ được dịch sang phải, và các bit phải cùng sẽ được đặt giá trị 0 hoặc 1 tùy thuộc vào giá trị của bit cao nhất (bit dấu).
Ví dụ cho TH1:

```cpp
uint8_t x = 00000001;
uint8_t res = x << 1; //res = 00000010
uint8_t res2 = x << 2; //res2 = 00000100
```

Ví dụ cho TH2: Ở trường hợp nó chia ra làm hai trường hợp nữa. Đó là dịch bit có dấu và không dấu. Dựa vào bit dấu (sign bit) để mà phân tích.
Bit dấu là bit số 7 (bit ngoài cùng nhất).
- Bit dấu = 0 --> Số dương
- Bit dấu = 1 --> Số âm
- Ví dụ có:
  - 00000101 = 5 (Bit dấu  = 0)
  - 11111010 = ~5 = -5 (Bit dấu  = 1)

```cpp
uint8_t x = 00000100; //Không dấu
uint8_t res = x >> 1; //res = 00000010
uint8_t res2 = x >> 2; //res2 = 00000001
int8_t y = 10000100; //Có dấu
uint8_t res = y >> 1; //res = 110000010
uint8_t res2 = y >> 2; //res2 = 11000001
```
# 5. Một số kỹ thuật ứng dụng Bitmask

```cpp
#include <stdio.h>
#include <stdint.h>

// Tạo các feature chỉ tồn tại 2 giá trị 0/1 (có hoặc không)
// Men's Features: HOUSE, WIFE, CAR, MONEY, BABY, JOB, FRIENDS, COMPETENCE

#define HOUSE 1 << 0 //(0000 0001) Bit số 1 được kích hoạt
#define WIFE 1 << 1  //(0000 0010) Bit số 2 được kích hoạt
#define CAR 1 << 2   //(0000 0100) Bit số 3 được kích hoạt
#define MONEY 1 << 3
#define BABY 1 << 4
#define JOB 1 << 5
#define FRIENDS 1 << 6
#define COMPETENCE 1 << 7

void featureEnable(uint8_t *men, uint8_t features)
{
    // Sử dụng logic | để gán bit được kích hoạt vào biến men
    *men |= features;
}

void featureUnenable(uint8_t *men, uint8_t features)
{
    // Sử dụng logic & và ~ để gán nghịch đảo của bit được kích hoạt
    *men &= (~features);
}

void IsFeatureEnabled(uint8_t men, uint8_t features)
{
    printf(((men & features) != 0) ? "Feature is enabled\n" : "Feature is not enabled\n");
}

int main()
{

    uint8_t Men = 0;

    featureEnable(&Men, HOUSE | MONEY | JOB | COMPETENCE);

    IsFeatureEnabled(Men, HOUSE);

    return 0;
}
```
- Chọn một biến user có giá trị = 0 = 0b00000000. Ý nghĩa là chưa có thuộc tính gì.
- Chọn mỗi bit là 1 thuộc tính. Dùng các hàm để kích hoạt hoặc hủy thuộc tính.
- Trong đây có các hàm ứng dụng Bitmask như:
  - **featureEnable:** dùng toán tử OR để kích hoạt 1 thuộc tính.
  
  ```cpp
  feature1 = 00010000
  user = 01000110 //user chưa được kích hoạt feature1
  user = user | feature1 = 01010110
  ```

  - **featureUnenable:** dùng toán tử & kết hợp với ~ để hủy 1 thuộc tính.
  ```cpp
  feature1 = 00010000
  user = 01010110 //user đang được kích hoạt feature1
  feature1 = ~feature1 // feature1 = 11101111
  user = user & feature1 = 01000110
  ```
  - **IsFeatureEnabled:** Kiểm tra 1 thuộc tính đã được kích hoạt chưa bằng toán tử &
  ```cpp
  feature1 = 00010000
  user = 01010110 //user đang được kích hoạt feature1
  user = user & feature1 = 00010000
  //khi này giá trị của user khác 0 nên thuộc tính đã được kích hoạt
  ```



