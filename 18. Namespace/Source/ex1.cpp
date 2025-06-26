#include <iostream>
using namespace std;

namespace LCD
{
    void display_LCD()
    {
        cout << "Hiển thị LCD" << endl;
    }

    void display_TFT()
    {
        cout << "Hiển thị TFT" << endl;
    }
}

int main()
{
    LCD::display_LCD();
    LCD::display_TFT();
    return 0;
}