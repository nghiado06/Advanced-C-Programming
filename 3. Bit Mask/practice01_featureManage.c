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