# Tìm hiểu về các khái niệm
- Struct
  - Khái niệm
  - Cú pháp
  - Data Alignment
  - Data Padding
  - Kích thước struct
- Bit Field
- Union
# 1. STRUCT
## 1.1 Khái niệm
- Trong ngôn ngữ lập trình C, struct là một cấu trúc dữ liệu cho phép lập trình viên tự định nghĩa một kiểu dữ liệu mới bằng cách nhóm các biến có các kiểu dữ liệu khác nhau lại với nhau. struct cho phép tạo ra một thực thể dữ liệu lớn hơn và có tổ chức hơn từ các thành viên (members) của nó.
## 1.2 Cú pháp

```cpp
  struct name_struct
{
  <data type 1> <member 1>;
  <data type 2> <member 2>;
  ...
};  
```

Kết hợp với typedef: Sẽ giúp cho code gọn hơn, không cần dùng Struct để khai báo nữa.

```cpp
  typedef struct
{
  <data type 1> <member 1>;
  <data type 2> <member 2>;
  ...
} name_struct;
```

Ví dụ về Struct:

```cpp
#include <stdio.h>
#include <stdint.h>

struct Example
{
  uint8_t a;
  uint16_t b;
  uint32_t c;
};

typedef struct
{
  uint8_t a;
  uint16_t b;
  uint32_t c;
} Ex2;

int main(){

  struct Example Ex1;
  Ex2 ex1;

  //Gán giá trị thử
  Ex1.a = 16;
  ex1.a = 20;

  printf("a = %d\n", Ex1.a);
  printf("a = %d\n", ex1.a); 
  return 0;
}
```
## 1.3 Data Alignment
- Các biến thành phần sẽ được cấp phát dữ liệu theo biến thành phần
có kích thước lớn nhất. 
- Tuy nhiên, số biến và số lần cấp phát không bằng nhau. Tức là
các biến thành phần hoàn toàn có thể sử dụng lại vùng nhớ được cấp phát 
lần trước.

<br>

Lấy ví dụ:

```cpp
  tydef struct
{
  uint16_t a; //2 Bytes
  uint8_t b; //1 Byte
  uint32_t c; //4 Bytes
};  
```
Khi này các biến thành viên sẽ được cấp phát bộ nhớ 
theo biến thành viên có kích thước lớn nhất, đó chính là
4 Bytes. Vậy các biến thành viên sẽ sử dụng kích thước bộ nhớ
được cấp phát đó như nào?

```cpp
  tydef struct
{
  uint16_t a; //2 Bytes
  uint8_t b; //1 Byte
  uint32_t c; //4 Bytes
} Name;
```

```
Lần cấp phát thứ 1: 4 Bytes 0x00 0x01 0x02 0x04
Biến a sẽ lấy 2 Bytes 0x00 0x01
Tuy nhiên vẫn còn 2 Bytes chưa sử dụng. Khi đó,
biến b sẽ sử dụng tiếp 1 bytes tiếp theo
a: 0x00 0x01
b: 0x02
Còn dư 1 byte thừa sẽ không đủ cho biến c. Nên sẽ
có lần cấp phát thứ 2: 0x04 0x05 0x06 0x07
Khi này:
a: 0x00 0x01
b: 0x02
c: 0x04 0x05 0x06 0x07
Như vậy là sử dụng 7 Bytes và dư 1 Byte.
Đó là quá trình sắp xếp các địa chỉ ô nhớ (Data Alignment)
```

## 1.4 Data Padding
- Nhìn lại ví dụ trước, Data Padding chính là vùng nhớ còn thừa
lại. Như vậy ở ví dụ trên có 1 byte padding.
- Byte Padding có thể nằm ở vị trí bất kỳ.

```cpp
typedef struct {
  uint32_t a; //4 bytes
  uint16_t b; //2 bytes
  uint8_t c; //1 byte
//Như cách sắp xếp ở trên thì sẽ có 1 byte padding nằm ở cuối
} Name;

```

## 1.5 Size of Struct
- Kích thước của struct sẽ bằng Bytes sắp xếp + Bytes Padding

```cpp
#include <stdio.h>

tydef struct
{
  uint16_t a; //2 Bytes
  uint8_t b; //1 Byte
  uint32_t c; //4 Bytes
} Ex;

int main(){
  Ex ex1;
  printf("Size of Struct: %d", sizeof(ex1));
  return 0;
}

```
output
```
Size of Struct: 8
```
# 2. Bit Field
- Trong C, “bit field” (trường bit) là một thành phần đặc biệt của cấu trúc (struct) cho
phép bạn chỉ định số lượng bit cụ thể dùng để lưu trữ một biến số nguyên. Thay vì sử
dụng toàn bộ kích thước của một kiểu dữ liệu, bạn có thể “cắt nhỏ” bộ nhớ theo số bit
cần thiết, giúp tiết kiệm không gian bộ nhớ và mô tả chính xác hơn ý nghĩa của dữ liệu
(ví dụ: lưu trạng thái bật/tắt chỉ cần 1 bit)
- Đặc điểm:
  - Không xác định được vùng nhớ mà nó truy cập
  - Không truy cập được địa chỉ của bit

```cpp
#include <stdio.h>
#include <stdint.h>

typedef struct {
  uint8_t a : 1; //Sử dụng 1 bit trong 8 bits
  uint16_t b : 3; //Sử dụng 3 bits trong 16 bits
} Example;

int main(){
  Example Ex1;

  Ex1.a = 1;
  printf("%d", &Ex1.a));

  return 0;
}

```
```
Không in được địa chỉ
```
# 3. UNION
- Trong ngôn ngữ lập trình C, union là một cấu trúc dữ liệu giúp lập trình viên kết hợp nhiều kiểu dữ liệu khác nhau vào cùng một vùng nhớ. Mục đích chính của union là tiết kiệm bộ nhớ bằng cách chia sẻ cùng một vùng nhớ cho các thành viên của nó. Điều này có nghĩa là, trong một thời điểm, chỉ một thành viên của union có thể được sử dụng. Điều này được ứng dụng nhằm tiết kiệm bộ nhớ.
- Kích thước vùng nhớ dùng chung sẽ phụ thuộc vào kiểu dữ liệu có kích thước lớn nhất.

Cú pháp:
```cpp
union name_union 
{
    kieuDuLieu1 thanhVien1;
    kieuDuLieu2 thanhVien2;
    // ...
};
```
Ví dụ:
```cpp
union Data 
{
    uint8_t  a; 0x00
    uint16_t b; 0x00 0x01
    uint32_t c; 0x00 0x01 0x02 0x03
}; //Kích thước chung của Union này là 4 byte.
```
Khi tác động lên một biến thành viên thì biến thành viên còn lại sẽ bị thay đổi theo.

```cpp
#include <stdio.h>
#include <stdint.h.


union Data {
  uint8_t a;
  uint16_t b;
  uint32_t c;
};

int main(){
  Data X;
  X.a = 10;
  X.b = 7;
  printf("a = %d", X.a);

  return 0;
}
```
output
```
a = 7
```
1 Ví dụ để hiểu rõ hơn cách Union dùng chung vùng nhớ:
```cpp
#include <stdio.h>
#include <stdint.h>

typedef union
{
    uint8_t a;   // 1 byte
    uint16_t b;  // 2 byte
    uint32_t c;  // 4 byte
} Ex;

int main(){
  Ex ex1;
  ex1.c = 4294967290;

  printf("a = %d\n", ex1.a);
  printf("b = %d\n", ex1.b);
  return 0;
}

```
output
```
a = 250
b = 65530
```
Giải thích về cách phần bổ vùng nhớ trong union:
```
Giá trị 4294967290 trong hệ thập lục phân là:  0xFFFFFFFA
Khi đó Vùng nhớ sẽ phân bổ như sau:
Byte thấp nhất: 0xFA
Byte thứ 2: 0xFF
Byte thứ 3: 0xFF
Byte thứ 4 (Byte cao nhaats0: 0xFF
Khi đó giá trị ex1.a chiếm byte đầu tiên mang 0xFA tương đương với 250 nên sẽ có giá trị 250
Giá trị ex1.b chiếm 2 byte 0xFA 0xFF tương đương với 65530 nên sẽ có giá trị 65530
```
- Ứng dụng của union và struct:

```cpp
#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef union
{
    struct
    {
        uint8_t id[2];
        uint8_t data[4];
        uint8_t check_sum[2];
    } data;
   
    uint8_t frame[8];
} Data_Frame;

int main(int argc, char const *argv[])
{
    Data_Frame transmit_data;
    strcpy((char*)transmit_data.data.id, "10");
    strcpy((char*)transmit_data.data.data, "1234");
    strcpy((char*)transmit_data.data.check_sum, "70");

    Data_Frame receive_data;
    strcpy((char*)receive_data.frame, (char*)transmit_data.frame);
    return 0;
}
```

