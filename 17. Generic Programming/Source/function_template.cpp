#include <iostream>

using namespace std;

// Constructor không có tham số
// Constructor có tham số - Không có giá trị mặc định
// Constructor có tham số - Có giá trị mặc định

#include <iostream>
using namespace std;

template <typename T>
class Sensor
{
private:
    T value;

public:
    Sensor(T init) : value(init) {}
    void readSensor(T newValue) { value = newValue; }
    T getValue() const { return value; }
    void display() { cout << "Gia tri cam bien: " << value << endl; }
};

// Function Template
// Template cũng có 2 loại:
// - template có tham số - Không có giá trị mặc định
// - template có tham số - Có giá trị mặc định
//  Cú pháp:
template <typename T>
T func(T a, T b) {}

template <typename T1, typename T2, typename T3>
T1 func(T1 a, T2 b, T3 c) {}

template <typename T4>
T4 sum(T4 a, T4 b)
{
    return a + b;
}

template <typename A = float, typename B, typename C>
A sum(B a, C b)
{
    return a + b;
}

int main()
{
    cout << sum(2, 4) << endl;
    cout << sum(1.0, 2.5) << endl;
    cout << sum(2, 1.5) << endl;

    Sensor tempSensor(36.5);
    tempSensor.display();

    Sensor lightSensor(512);
    lightSensor.display();

    Sensor stateSensor("OFF");
    stateSensor.display();

    return 0;
}