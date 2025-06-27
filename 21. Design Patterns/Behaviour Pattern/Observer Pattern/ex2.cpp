#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Observer
{
public:
    virtual void update(float throttle, float speed) = 0;
};

class Subject
{
public:
    virtual void registerObserver(Observer * observer) = 0;
    virtual void removeObserver(Observer * observer) = 0;
    virtual void notifyObservers() = 0;
};

class SensorDataManager : public Subject
{
private:
    float throttle; // cảm biến bàn đạp ga
    float speed;    // cảm biến tốc độ
    vector<Observer *> observers;

public:
    void registerObserver(Observer * observer)
    {
        observers.push_back(observer); // emplace_back()
    }

    void removeObserver(Observer * observer)
    {
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
        // find
        // erase(o, o + 1)
    }

    // 1, 1, 2, 3, 5
    // 2, 3, 5, 1, 1

    void notifyObservers()
    {
        for (auto observer : observers)
        {
            observer->update(throttle, speed);
        }
    }

    void setSensorData(float throttleValue, float speedValue)
    {
        throttle = throttleValue;
        speed = speedValue;
        notifyObservers(); // Thông báo khi dữ liệu cảm biến thay đổi
    }
};

// Concrete Observer: Dashboard
class DashBoardDisplay : public Observer{
    public :
        void update(float throttle, float speed) override{
            cout << "Dashboard: Current speed = " << speed << " km/h, Throttle = " << throttle << "%" << endl;
}
}
;

// Concrete Observer: Engine Controller
class EngineController : public Observer{
    public :
        void update(float throttle, float speed) override{
            cout << "Engine Controller: Adjusting engine power based on throttle = " << throttle << "%" << endl;
}
}
;

// Concrete Observer: ABS Controller
class ABSController : public Observer{
    public :
        void update(float throttle, float speed) override{
            if (speed > 100){
                cout << "ABS Controller: Speed is high (" << speed << " km/h), monitoring for possible skidding." << endl;
}
else
{
    cout << "ABS Controller: Speed is safe." << endl;
}
}
}
;

int main(int argc, char const *argv[])
{
    // Tạo Subject (Sensor Data Manager)
    SensorDataManager sensorDataManager;

    // Tạo các Observers
    DashBoardDisplay dashboard;
    EngineController engineController;
    ABSController absController;

    // Đăng ký Observers với Subject
    sensorDataManager.registerObserver(&dashboard);
    sensorDataManager.registerObserver(&engineController);
    sensorDataManager.registerObserver(&absController);

    // Cập nhật dữ liệu cảm biến lần 1
    sensorDataManager.setSensorData(30, 80);

    // Cập nhật dữ liệu cảm biến lần 2
    sensorDataManager.setSensorData(60, 120);

    // Gỡ bỏ Dashboard
    sensorDataManager.removeObserver(&dashboard);

    // Cập nhật dữ liệu cảm biến lần 3
    sensorDataManager.setSensorData(50, 100);
    return 0;
}
