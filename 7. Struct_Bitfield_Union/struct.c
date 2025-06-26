#include <stdio.h>
#include <stdint.h>

// Kiến thức về struct (Cú pháp, con trỏ)
// Kiến thức về:
//- Data Alignment: quá trình sắp xếp các biến thành viên sao cho phù hợp
//   int, int32_t, uint32_t (4 byte): 0x00 0x04 0x08, v.v nằm ở các địa chỉ chia hết cho 4
//  float, double (8 byte): 0x00, 0x08, 0x0f, v.v
//  uint16_t, int16_t (2 byte): 0x00, 0x02, 0x04, 0x06, 0x08,v.v
//  char, uint8_t, int8_t (1 byte)

//- Data Padding: sau khi căn chỉnh, sắp xếp các biến thành viên thì sẽ có byte trống (padding)

// Cách cấp phát địa chỉ trong struct. Đó chính là nó sẽ cấp phát theo biến thành viên có kiểu dữ liệu lớn nhất.
// Nó sẽ cấp phát và sử dụng tuần tự, nếu như biến đầu tiên không sử dụng hết số byte được cấp phát thì số byte còn lại sẽ được dùng cho
// biến tiếp theo. Số byte còn lại sau cùng sẽ là số byte thừa (Data Padding)

//- Kích thước struct: là kích thước khi cấp phát

// Bit field: khoông biết được địa chỉ mà nó sử dụng --> Không đọc được địa chỉ

// Union: là kiểu strcut sử dụng chung 1 vùng nhớ của biến thành viên lớn nhất cho
// các biến thành viên còn lại. Khi thay đổi giá trị 1 biến thì các biến thành viên còn
// lại cũng dùng chung giá trị thay đổi đó.

/*Cách phân bổ vùng nhớ:
có vùng nhớ 0xFFFFFFFA
Nó sẽ phân bố ngược:
Byte thấp nhất: 0xFA
Byte thứ 2: 0xFF
Byte thứ 3: 0xFF
Byte cao nhất: 0xFF
*/

typedef union
{
    uint8_t a;
    uint16_t b;
    uint32_t c;

} Ex;

typedef struct
{
    char *name;
    int age;
    double gpa;

} SinhVien;

struct SV
{
    int a;
    int b;
    int c;
};

typedef struct
{
    int x;   // 4 byte // 0xa0 0xa1 0xa2 0xa3 //Lần cấp phát 1
    short y; // 2 byte //0xa4 0xa5 //Lần cấp phát 2
    short z; // 2 byte //0xa6 0xa7 //Sử dụng lại 2 byte ở trên
    short a; // 2 byte //0xa8 0xa9 0xaa 0xab  //Lần cấp phát 3
} N;

struct Example1
{
    uint8_t arr1[5];  // 5x1 1 byte
    uint16_t arr2[4]; // 4x2 2 byte
    uint32_t arr3[2]; // 2x4 4 byte
};

int main()
{
    SinhVien sv1, sv2;

    sv1.age = 18;
    sv1.gpa = 4.0;

    SinhVien *ptr;
    ptr->gpa = 3.8;

    printf("%f\n", ptr->gpa);
    printf("Size of struct: %d\n", sizeof(struct SV));
    printf("Size of struct: %u\n", sizeof(N));

    // struct
    Ex i;
    // i.a = 10;
    // i.b = 6;
    i.c = 4294967290;

    printf("a = %d\n", i.a);
    printf("b = %d\n", i.b);
    printf("c = %d", i.c);

    return 0;
}