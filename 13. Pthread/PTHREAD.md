# TÌM HIỂU VỀ THƯ VIỆN PTHREAD
- Đặt vấn đề
- Thư viện Pthread
  - Cú pháp
  - Chức năng
 
# 1. ĐẶT VẤN ĐỀ
- Giả sử chương trình thực hiện hai tác vụ liên tục (task1, task2), nếu đặt trong while(1) thì thực hiện tuần tự, task1 thực hiện xong thì mới thực hiện task2.
- Muốn cả 2 tác vụ trên thực thi song song với nhau thì làm thế nào?
- Ví dụ:

```cpp
#include <stdio.h>
#include <unistd.h>
void task1(){
    static int count = 0;
    count++;
    printf("Count taks1: %d\n", count);
    sleep(1);
}
void task2(){
    static int count = 0;
    count++;
    printf("Count taks2: %d\n", count);
    sleep(3);
}
int main(int argc, char const *argv[]){
    while(1){
        task1();
        task2();
    }
    return 0;
}
```

output

```
Count taks1: 1
Count taks2: 1
Count taks1: 2
Count taks2: 2
Count taks1: 3
Count taks2: 3
...
```

- Các task sẽ được chạy tuần tự, đặt trong trường hợp cần thực hiện nhiều chức năng cùng 1 lúc thì điều này là không hợp lí. Vì thế, đối với những trường hợp trên ta cần sử dụng tính chất **đa luồng** để có thể chạy
các task song song.

# 2. ĐA LUỒNG (MULTITHREADS)
## 2.1 LUỒNG (THREAD)
- Thread (luồng) là đơn vị thực thi nhỏ nhất của một tiến trình (Process). Mỗi tiến trình có thể chứa nhiều thread, và các thread này chạy song song với nhau.
- Các thread trong cùng tiến trình chia sẻ tài nguyên với nhau nhưng sẽ có stack và bộ đếm chương trình riêng biệt.

## 2.2 XỬ LÝ ĐA LUỒNG
- Về bản chất, đa luồng cũng chính là tuần tự, nhưng các tác vụ được CPU xử lý chạy xen kẽ và phân chia thời gian một cách ngẫu nhiên.
- Ví dụ: Ta có task 1 sẽ làm nhiệm vụ 1,2,3,4. Task 2 làm nhiệm vụ 5,6,7,8. Thì chạy đa luồng 2 task này sẽ được hình dung là 1,5,6,2,3,7,4,8. Với mỗi lần các task lặp lại sẽ là một lần các nhiệm vụ được phân chia khác nhau.

## 2.3 THƯ VIỆN PTHREAD
- Pthread (POSIX Threads) là thư viện cho lập trình đa luồng trong C/C++:
  - Giúp bạn viết các chương trình có thể thực hiện nhiều tác vụ cùng lúc bằng cách chạy nhiều luồng (threads) song song. Điều này đặc biệt hữu ích trên các hệ thống có nhiều bộ xử lý hoặc bộ xử lý nhiều nhân, vì mỗi luồng có thể được phân bố cho các nhân khác nhau để chạy.
  - Xử lý nhiều công việc cùng lúc, giúp tăng tốc độ xử lý và phân tán công việc hiệu quả hơn.

### 2.3.1 Hàm pthread_create
- Để tạo mới một thread ta sẽ sử dụng hàm pthread_create. Sau đó, ta chỉ định tác vụ cụ thể cho các thread này.
- Cú pháp:

```cpp
pthread_create(pthread_t *th, const pthread_attr_t *attr, void *(* func)(void *), void *arg)
```

- Trong đó:
  - Tham số 1: một con trỏ kiểu pthread_t, đại diện cho một thread mới được tạo ra.
  - Tham số 2: một thuộc tính của thread, đặt là NULL nếu giữ thuộc tính mặc định.
  - Tham số 3: địa chỉ hàm muốn thực thi.
  - Tham số 4: một con trỏ đối số cho hàm thuộc kiểu void.


### 2.3.2 Hàm pthread_join
- Chờ tác vụ thread kết thúc, ta sử dụng hàm pthread_join.
- Cú pháp:

```cpp
pthread_join(pthread_t t, void **res)
```

- Trong đó:
  - Tham số 1: ID của thread mà bạn muốn chờ đợi.
  - Tham số 2: pointer to pointer mà kết quả trả về từ thread sẽ được lưu trữ. Nếu không cần kết quả, có thể đặt NULL .

### 2.3.3 Lưu ý
- Các luồng (thread) được tạo bởi thư viện pthread này chính là các luồng phụ. Hàm main của chương trình chính là một luồng chính.
- Luồng chính phải hoạt động thì các luồng phụ mới được hoạt động. Lấy ví dụ:

```cpp
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void *task1(void *data){
    static int i = 0;
    for (int i=0; i<8; i++){
        printf("count task1: %d\n", i++);
        sleep(1);
    }
}
void *task2(void *data){
    static int i = 0;
    while(1){
        printf("count task2: %d\n", i++);
        sleep(3);
    }
}
void *display(void *a){
    while(1){
        printf("%s\n", (char*)a);
        sleep(1);
    }
}
int main(int argc, char const *argv[]){
    pthread_t t1; // luồng 1
    pthread_t t2; // luồng 2
    pthread_t t3; // luồng 3

    char *ptr = "Hello\n";
   
    pthread_create(&t1, NULL, task1, NULL);
    pthread_create(&t2, NULL, task2, NULL);
    pthread_create(&t3, NULL, display, ptr);

    return 0;
}
```

output

```
count task1: 0
count task2: 0
Hello
```

- Khi này có thể thấy, các task chỉ thực hiện đúng một lần khi được gọi, và hàm main không thực tác vụ dẫn đến các luồng phụ cũng ngưng chạy.
- Bên cạnh đó, bản chất của hàm pthread_join chính là một flag dùng để đánh dấu khi kết thúc luồng phụ và bắt đầu chạy luồng chính. Tức là nếu đặt hàm này trước các câu lệnh của hàm main thì hàm main sẽ không được thực hiện cho đến khi luồng phụ này kết thúc, và những luồng phụ
đặt sau hàm này cũng sẽ bị phụ thuộc vào luồng chính.
- Lấy ví dụ:

```cpp
count task1: 0
count task2: 0
count task1: 1
count task1: 2
count task2: 1
count task2: 2


...Program finished with exit code 0
```

Khi này, luồng chính không chạy dẫn đến sau khi task1 và task2 kết thúc, task3 cũng bị skip.

- Nếu luồng chính có chạy thì sao?

```cpp
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void *task1(void *data){
    static int a = 0;
    for (int i = 0; i < 3; i++){
        printf("count task1: %d\n", a++);
        sleep(1);
    }
}
void *task2(void *data){
    static int b = 0;
    for (int i=0; i < 3; i++){
        printf("count task2: %d\n", b++);
        sleep(3);
    }
}
void *display(void *a){
    while(1){
        printf("%s\n", (char*)a);
        sleep(1);
    }
}
int main(int argc, char const *argv[]){
    pthread_t t1; // luồng 1
    pthread_t t2; // luồng 2
    pthread_t t3; // luồng 3

    char *ptr = "Hello\n";
   
    pthread_create(&t1, NULL, task1, NULL);
    pthread_create(&t2, NULL, task2, NULL);


    pthread_join(t1, NULL);
    pthread_join(t2, NULL);


    
    pthread_create(&t3, NULL, display, ptr);
    while(1)
    {
        printf("Hello world\n");
        sleep(1);
    }
    

    return 0;
}


```

output

```
count task1: 0
count task2: 0
count task1: 1
count task1: 2
count task2: 1
count task2: 2
Hello world
Hello

Hello world
Hello

Hello world
Hello
```

- Khi này, task3 dã được chạy cùng luồng chính.
- Với trường hợp hàm pthread_join được đặt sau luồng chính:

```cpp
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void *task1(void *data){
    static int a = 0;
    for (int i = 0; i < 3; i++){
        printf("count task1: %d\n", a++);
        sleep(1);
    }
}
void *task2(void *data){
    static int b = 0;
    for (int i=0; i < 3; i++){
        printf("count task2: %d\n", b++);
        sleep(3);
    }
}
void *display(void *a){
    for (int i = 0; i < 3; i++){
        printf("%s\n", (char*)a);
        sleep(1);
    }
}
int main(int argc, char const *argv[]){
    pthread_t t1; // luồng 1
    pthread_t t2; // luồng 2
    pthread_t t3; // luồng 3

    char *ptr = "Hello\n";
   
    pthread_create(&t1, NULL, task1, NULL);
    pthread_create(&t2, NULL, task2, NULL);
    
    pthread_create(&t3, NULL, display, ptr);
    for (int i = 0; i < 3; i++)
    {
        printf("Hello world\n");
        sleep(1);
    }
    
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);


    return 0;
}

```

output

```
count task1: 0
count task2: 0
Hello world
Hello

count task1: 1
Hello world
Hello

Hello world
Hello

count task1: 2
count task2: 1
count task2: 2


...Program finished with exit code 0
Press ENTER to exit console.
```

- Khi này luồng chính không bị ảnh hưởng nữa.
