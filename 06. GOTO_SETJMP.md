# Tìm hiểu về GOTO và Thư viện SETJMP
- Khái niệm Goto và Thư viện setjmp.h
- Chức năng và ứng dụng của chúng
# 1. GOTO
- goto là một từ khóa trong ngôn ngữ lập trình C/C++, cho phép chương trình nhảy đến một nhãn (label) đã được đặt trước đó trong cùng một hàm.
- Mặc dù nó cung cấp khả năng kiểm soát flow của chương trình, nhưng việc sử dụng goto thường được xem là không tốt vì nó có thể làm cho mã nguồn trở nên khó đọc và khó bảo trì.
<br>

**Phân tích ví dụ sau:**

```cpp
#include <stdio.h>

int main() {
    int i = 0; //0x01: 0

    // Đặt nhãn
    start:
        if (i >= 5) {
            goto end;  // Chuyển control đến nhãn "end"
        }

        printf("%d ", i);
        i++;

        goto start;  // Chuyển control đến nhãn "start"

    // Nhãn "end"
    end:
        printf("\n");

    return 0;
}

```
```
Kiểm tra output của từng step:
Step 1: 0
Step 2: 1
Step 3: 2
Step 4: 3
Step 5: 4
Step 6: 5
Step 7: 
```

## 2. Thư viện SETJMP
- setjmp.h là một thư viện trong ngôn ngữ lập trình C, cung cấp hai hàm chính là setjmp và longjmp. Cả hai hàm này thường được sử dụng để thực hiện xử lý ngoại lệ trong C, mặc dù nó không phải là một cách tiêu biểu để xử lý ngoại lệ trong ngôn ngữ này.
- Cấu trúc cơ bản khi sử dụng thư viện này bao gồm các hàm:
  - **Khai báo jmp_buf env; :** Biến env sẽ lưu trạng thái thực thi tại thời điểm gọi setjmp(env);
  - **setjmp(env):**
    - Lưu trạng thái thực thi vào biến env.
    - Lần gọi đầu tiên trạng thái sẽ trả về 0.
  - **longjmp(env, int val); :** Nhảy ngược về setjmp() và cập nhật trạng thái thực thi thành giá trị val.

```cpp
#include <stdio.h>
#include <setjmp.h>

jmp_buf env;

void test() {
    printf("Đang truy cập hàm test()\n");
    longjmp(env, 1); // Nhảy về setjmp()
}

int main() {
    if (setjmp(env) == 0) {
        printf("Gọi lần đầu tiên, setjmp trả về 0\n");
        test();  // Gọi test()
    } else {
        printf("Chương trình quay lại từ longjmp() với giá trị 1\n");
    }
    return 0;
}
```
output
```
Gọi lần đầu tiên, setjmp trả về 0
Đang truy cập hàm test()
Chương trình quay lại từ longjmp() với giá trị 1
```

