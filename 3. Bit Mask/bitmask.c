#include <stdio.h>
#include <stdint.h>

// Bit mask là kỹ thuật control số bit khi khai báo một biến

/*
- int8_t, uint8_t: 1 byte (8bit)
- int16_t, uint16_t: 2 byte (16 bit)
- int, int32_t, uint32_t: 4 byte (32 bit)
*/

// Tuy nhiên cách này vẫn chưa thật sự tối ưu
//  Đối với các dữ liệu chỉ cần giá trị 0/1, 1 bit thì
//  ta có thể quản lí bit trong cùng 1 biến

uint8_t user; // 0bxxxxxxxx

int main()
{

    uint8_t user1 = 0b11110001;
    uint8_t user2 = 0b00101001;

    // Toán tử trong bitmask: NOT, OR, AND, XOR

    // NOT
    // user1 = ~user1; --> user1 = 0b00001110;

    // OR
    // user1 | user2 --> 0b11111001

    // AND
    // user1 & user2 --> 0b00100001

    // XOR
    // user1 ^ user2 --> 11011000

    // Quy tắc dịch bit: (<<) dịch sang trái (shiftLeft), (>>) dịch sang phải (shiftRight)

    // user = 0b00001101
    // user << n (n: số bit muốn dịch). Vd n = 1
    // user << 1 --> 0b00011010
    // user << 3 --> 0b01101000

    return 0;
}