#include <iostream>
using namespace std;

class Sensor
{
public:
    virtual void readData() = 0;
};

// Cảm biến nhiệt độ
class TemperatureSensor : public Sensor
{
public:
    void readData() override
    {
        cout << "reading temperature data: " << endl;
    }
};

// Cảm biến độ ẩm
class HumiditySensor : public Sensor
{
public:
    void readData() override
    {
        cout << "reading humidity data: " << endl;
    }
};

// Decorator Pattern
class SensorDecorator : public Sensor
{
protected:
    Sensor *wrappedSensor;

public:
    SensorDecorator(Sensor *sensor) : wrappedSensor(sensor) {}

    virtual void readData() override
    {
        wrappedSensor->readData();
    }
};

// Thêm tính năng Log
class LoggingSensor : public SensorDecorator
{
public:
    LoggingSensor(Sensor *sensor) : SensorDecorator(sensor) {}

    void readData() override
    {
        cout << "LOG: sensor data" << endl;
        SensorDecorator::readData();
    }
};

int main(int argc, char const *argv[])
{
    Sensor *tempSensor = new TemperatureSensor();
    Sensor *log = new LoggingSensor(tempSensor);
    log->readData();
    return 0;
}
