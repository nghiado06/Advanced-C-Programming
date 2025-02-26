# Tìm hiểu về Pointer (Con trỏ)
- **Tìm hiểu tổng quan về con trỏ**
  - Khái niệm
  - Cú pháp khai báo, truy xuất
  - Kích thước
  - Ứng dụng và Ý nghĩa
- **Các loại con trỏ**
  - Cú pháp khai báo
  - Ý nghĩa và cách sử dụng của từng loại con trỏ đó. 
# 1. Tìm hiểu tổng quan về con trỏ (pointer)
## 1.1 Khái niệm
- Trong ngôn ngữ lập trình C, con trỏ (pointer) là một biến chứa địa chỉ bộ nhớ của một đối tượng khác (biến, mảng, hàm). Việc sử dụng con trỏ giúp chúng ta thực hiện các thao tác trên bộ nhớ một cách linh hoạt hơn.
## 1.2 Cú pháp khai báo
- Khai báo

```cpp
  data_type *pointer_name;
```
- Gán giá trị: do giá trị của một con trỏ là địa chỉ của một biến khác nên ta sẽ kết hợp toán tử & để lấy địa chỉ của 1 biến. Và bản thân con trỏ cũng là 1 biến đang sử dụng 1 địa chỉ khác nữa.
```cpp
  pointer_name = &variable;
```

Ví dụ:

```cpp
int x = 10; //Địa chỉ: 0x01
int *ptr; // Địa chỉ con trỏ: 0x02
ptr = &x; // Giá trị con trỏ: 0x01
```

## 1.3 Truy xuất giá trị
- Ta sử dụng toán tử * để lấy giá trị của địa chỉ mà con trỏ đang trỏ tới.
```cpp
int x = 10; //Địa chỉ: 0x01
int *ptr; //Địa chỉ con trỏ: 0x02
ptr = &x; //Giá trị con trỏ: 0x01
*ptr = 15; //Truy cập vào giá trị của địa chỉ là con trỏ trỏ tới *ptr = *(&x) = x = 15
printf("%d", x); //Khi này x = 15
```
output
```
15
```

******Lưu ý:****** Khi sử dụng con trỏ, kiểu dữ liệu con trỏ và kiểu dữ liệu địa chỉ mà con trỏ trỏ tới phải giống nhau.
```cpp
int *ptr;
float x = 10;
ptr = &x; //Báo lỗi
```

## 1.4 Kích thước con trỏ
- Kích thước của con trỏ phụ thuộc vào **kiến trúc máy tính và trình biên dịch** hoặc **kiến trúc vi xử lý**.

```cpp
#include <stdio.h>

int main() {
    int *ptr;
    printf("Size of pointer: %d bytes\n", sizeof(ptr));
    return 0;
}
```
output
```
Size of pointer: 8 bytes //Kết quả này là do hệ điều hành của tôi đang ở 64-bit. Con số này có thể thay đổi.
```

## 1.5 Ứng dụng và Ý nghĩa
- Con trỏ giúp **can thiệp trực tiếp** vào vùng nhớ của biến, thay vì làm việc với một bản sao cục bộ trong stack. Điều này giúp thay đổi giá trị thực của biến trong bộ nhớ, tránh việc trình biên dịch tạo ra một biến tạm thời khi truyền tham số theo giá trị.

<br>

**Khi không dùng con trỏ:**

```cpp
#include <stdio.h>

void changeValue(int x) {
    x = 10;
}

int main() {
    int num = 5;
    changeValue(num);
    printf("Giá trị của num: %d\n", num);  // Vẫn là 5
    return 0;
}
```
output
```
Giá trị của num: 5
```

--> Khi này giá trị của num không thay đổi vì:
  - Hàm changeValue đã tạo 1 biến tạm thời cục bộ sao chép giá trị của x là 5 sau đổi thay đổi nó thành 10 và biến tạm thời này sẽ được trả lại bộ nhớ sau khi thoát hàm.

```cpp
void changeValue(int x) {
    x = 10;  // Thay đổi x, nhưng chỉ thay đổi bản sao trong stack
}

int main() {
    int num = 5; //Địa chỉ: 0x01
    changeValue(num); //Biến tạm thời có địa chỉ: 0x02. Giá trị biến tạm thời: 10
    printf("Giá trị của num: %d\n", num);  // Giá trị biến num vẫn là 5
    return 0;
}
```

**Khi dùng con trỏ**

```cpp
#include <stdio.h>

void changeValue(int *x) {
    *x = 10;  // Thay đổi giá trị tại địa chỉ của x
}

int main() {
    int num = 5;
    changeValue(&num);  // Truyền địa chỉ của num
    printf("Giá trị của num: %d\n", num);  // Bây giờ là 10
    return 0;
}

```

--> Khi này chúng ta đã can thiệp trực tiếp vào địa chỉ của biến num và thay đổi giá trị của nó.
# 2.Các loại pointer
## Void pointer (Con trỏ Void)
- Void pointer thường dùng để trỏ để tới bất kỳ địa chỉ nào mà không cần biết tới kiểu dữ liệu của giá trị tại địa chỉ đó.
- Cú pháp:

```cpp
void *ptr_void;
```

Ví dụ:

```cpp
#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b)
{
    return a+b;
}

int main() {
   
    char array[] = "Hello";
    int value = 5;
    double test = 15.7;
    char letter = 'A';
   
    void *ptr = &value;
    printf("value is: %d\n", *(int*)(ptr));

    ptr = &test;
    printf("value is: %f\n", *(double*)(ptr));

    ptr = &letter;
    printf("value is: %c\n", *(char*)(ptr));

    ptr = sum;
    printf("sum: %d\n", ((int (*)(int,int))ptr)(5,6));

    void *ptr1[] = {&value, &test, &letter , sum, array};

    printf("value: %d\n", *(int*)ptr1[0]);

    printf("value: %c\n", *((char*)ptr1[4]+1));

    return 0;
}

```

## Function Pointer (Con trỏ Hàm)
- Pointer to function (con trỏ hàm) là một biến mà giữ địa chỉ của một hàm. Có nghĩa là, nó trỏ đến vùng nhớ trong bộ nhớ chứa mã máy của hàm được định nghĩa trong chương trình.
- Trong ngôn ngữ lập trình C, con trỏ hàm cho phép bạn truyền một hàm như là một đối số cho một hàm khác, lưu trữ địa chỉ của hàm trong một cấu trúc dữ liệu, hoặc thậm chí truyền hàm như một giá trị trả về từ một hàm khác.
- Cú pháp cơ bản:
```cpp
  <return_type> (* func_pointer)(<data_type_1>, <data_type_2>);
```
Ví dụ: 
<br>
**Hàm không có đối số**
```cpp
void doKiss(){
  printf("Kissed!\n")
}

void doHoldingHand(){
  printf("Already Held Her Hand\n");
}

int main(){
  //Khai báo con trỏ hàm
  void (*do_ptr)();
  //Gán địa chỉ của hàm doKiss
  do_ptr = doKiss;
  //Gọi hàm thông qua con trỏ hàm
  (*do_ptr)();

  //Gán địa chỉ của hàm doHoldingHand
  do_ptr = doHoldingHand;
  //Gọi hàm thông qua con trỏ hàm
  (*do_ptr)();

return 0;
}
```
output
```
Kissed!
Already Held Her Hand
```
**Hàm có đối số**: ở đây con trỏ hàm được dùng như 1 tham trị để đọc hàm.
```cpp
#include <stdio.h>

void sum(int a, int b)
{
    printf("Sum of %d and %d is: %d\n",a,b, a+b);
}

void subtract(int a, int b)
{
    printf("Subtract of %d by %d is: %d \n",a,b, a-b);
}

void multiple(int a, int b)
{
    printf("Multiple of %d and %d is: %d \n",a,b, a*b );
}

void divide(int a, int b)
{
    if (b == 0)
    {
        printf("Mau so phai khac 0\n");
        return;
    }
    printf("%d divided by %d is: %f \n",a,b, (double)a / (double)b);
}

void calculator(void (*ptr)(int, int), int a, int b)
{
    printf("Program calculate: \n");
    ptr(a,b);
}


int main()
{
    calculator(sum,5,2);
    calculator(subtract,5,2);
    calculator(multiple,5,2);
    calculator(divide,5,2);

    void (*ptr[])(int, int) = {sum, divide, multiple}; //Array con trỏ hàm
    ptr[0](5,6); //sum(5,6);

    return 0;
}

```

## Pointer to Constant (Con trỏ hằng)
- Là cách định nghĩa một con trỏ không thể thay đổi giá trị tại địa chỉ mà nó trỏ đến thông qua dereference nhưng giá trị tại địa chỉ đó có thể thay đổi.
- Cú pháp:
```cpp
int const *ptr_const; 
const int *ptr_const;
```
- Ví dụ:
```cpp
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int value = 5;
    int test = 8;
    int const *ptr_const = &value;

    //*ptr_const = 7; // wrong
    //ptr_const = &test; // right
    
    printf("value: %d\n", *ptr_const);

    value = 9;
    printf("value: %d\n", *ptr_const);

    return 0;
}

```
output
```
value: 5
value: 9
```

## Constant Pointer (Hằng con trỏ)
- Định nghĩa một con trỏ mà giá trị nó trỏ đến (địa chỉ ) không thể thay đổi. Tức là khi con trỏ này được khởi tạo thì nó sẽ không thể trỏ tới địa chỉ khác.
- Cú pháp:
```cpp
int *const const_ptr = &value;
```
- Ví dụ:
```cpp
#include <stdio.h>
#include <stdlib.h>


int main() {
    
    int value = 5;
    int test = 15;
    int *const const_ptr = &value;

    printf("value: %d\n", *const_ptr);

    *const_ptr = 7;
    printf("value: %d\n", *const_ptr);

    //const_ptr = &test; // wrong
    
    return 0;
}
```

## Pointer to Pointer (Con trỏ cấp 2)
- Con trỏ đến con trỏ (Pointer to Pointer) là một kiểu dữ liệu trong ngôn ngữ lập trình cho phép bạn lưu trữ địa chỉ của một con trỏ. Con trỏ đến con trỏ cung cấp một cấp bậc trỏ mới, cho phép bạn thay đổi giá trị của con trỏ gốc. Cấp bậc này có thể hữu ích trong nhiều tình huống, đặc biệt là khi bạn làm việc với các hàm cần thay đổi giá trị của con trỏ.
- Cú pháp:
```cpp
int test = 5; //Add: 0x01 Value: 5
int *ptr = &test; //Add: 0xf1 Value: 0x01
int **ptp = &ptr; //Add: 0xef Value: 0xf1
```
- Truy xuất giá trị:
```cpp
#include <stdio.h>

int main() {
    int value = 42; //Add: 0x01
    int value2 = 20; //Add: 0x02
    int *ptr1 = &value;  // Con trỏ thường trỏ đến một biến
    int **ptr2 = &ptr1;  // Con trỏ đến con trỏ

    *ptr1 = 10; //Value = 10
    *ptr2 = &value2; //ptr1 = &value2
    **ptr2 = 100; //*ptr1 = value2 = 100
    printf("Địa chỉ mà con trỏ ptr1 trỏ tới là: %p\n", ptr1);
    printf("Giá trị Value2 = %d\n", value2);
{
```
output
```
Địa chỉ mà con trỏ ptr1 trỏ tới là: 0x02
Giá trị Value2 = 100
```
## NULL Pointer 
- Null Pointer là một con trỏ không trỏ đến bất kỳ đối tượng hoặc vùng nhớ cụ thể nào. Trong ngôn ngữ lập trình C, một con trỏ có thể được gán giá trị NULL để biểu diễn trạng thái null, C++ (NULL, nullptr).
- Sử dụng null pointer thường hữu ích để kiểm tra xem một con trỏ đã được khởi tạo và có trỏ đến một vùng nhớ hợp lệ chưa. Tránh dereferencing (sử dụng giá trị mà con trỏ trỏ đến) một null pointer là quan trọng để tránh lỗi chương trình.
- Ví dụ:
```cpp
#include <stdio.h>

int main(){
  int *ptr; //Con trỏ khi khai báo chưa cấp phát sẽ có thể trỏ đến 1 địa chỉ rác, gây tốn bộ nhớ
  int *null_ptr = NULL; //Con trỏ khi này không trỏ đến một địa chỉ cụ thể nào cả.
  
  printf("Địa chỉ của ptr: %p\n", ptr);
  printf("Địa chỉ của con trỏ NULL: %p\n", (void*)null_ptr); //Vì nó không trỏ đến 1 địa chỉ hợp lệ nào cả nên cần ép kiểu để nó xuất được địa chỉ. Thông thường địa chỉ này sẽ là 0x00
  
  return 0;
}
```
output
```
Địa chỉ của ptr: 00000000005FFEF0
Địa chỉ của con trỏ NULL: 0000000000000000
```
