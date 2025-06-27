#include <iostream>
#include "stm32f10x.h"
using namespace std;

class UART
{
private:
    static UART *instance;
    UART() { initUART(); }

    void initUART()
    {
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
    static UART *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new UART(); // Tạo instance nếu chưa có
        }
        return instance;
    }

    void sendData(uint8_t data)
    {
        while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)
            ;
        USART_SendData(USART1, data);
    }

    uint8_t receiveData()
    {
        while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET)
            ;
        return USART_ReceiveData(USART1);
    }
};

UART *UART::instance = nullptr;

int main()
{
    UART *uart = UART::getInstance();

    // Gửi một ký tự qua UART
    uart->sendData('H');

    // Nhận một ký tự từ UART
    uint8_t received = uart->receiveData();

    while (1)
    {
        // Thực hiện công việc liên quan khác
    }
}
