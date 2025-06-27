#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Giao diện Observer
class IObserver
{
public:
    virtual void update(float temperature) = 0;
};

// Subject: Cảm biến nhiệt độ
class TemperatureSensor
{
private:
    float temperature;
    vector<IObserver *> observers;

public:
    void attach(IObserver * obs)
    {
        observers.push_back(obs);
    }

    void detach(IObserver * obs)
    {
        observers.erase(remove(observers.begin(), observers.end(), obs), observers.end());
    }

    void setTemperature(float newTemp)
    {
        temperature = newTemp;
        notifyObservers();
    }

    void notifyObservers()
    {
        for (auto obs : observers)
        {
            obs->update(temperature);
        }
    }
};

// Concrete Observer: Màn hình
class LCDDisplay : public IObserver{
    public :
        void update(float temperature) override{
            cout << "[LCD] Hiển thị nhiệt độ: " << temperature << " độ C\n";
}
}
;

// Concrete Observer: Báo động
class Alarm : public IObserver{
    public :
        void update(float temperature) override{
            if (temperature > 50){
                cout << "[ALARM] Cảnh báo! Nhiệt độ vượt ngưỡng: " << temperature << " độ C\n";
}
}
}
;

// Concrete Observer: Ghi log
class Logger : public IObserver{
    public :
        void update(float temperature) override{
            cout << "[LOG] Ghi nhiệt độ vào file: " << temperature << " độ C\n";
}
}
;

int main()
{
    TemperatureSensor sensor;

    LCDDisplay lcd;
    Alarm alarm;
    Logger logger;

    sensor.attach(&lcd);
    sensor.attach(&alarm);
    sensor.attach(&logger);

    // Thay đổi nhiệt độ – tất cả observers được thông báo
    sensor.setTemperature(45.0);
    cout << "----------------------------\n";
    sensor.setTemperature(55.5);

    return 0;
}
