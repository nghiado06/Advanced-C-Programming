#include <iostream>
using namespace std;

class StaticCounter
{
    static int count;

public:
    static int call() { return ++count; }
    void get() { cout << count << endl; }
};

int StaticCounter::count = 0;

int main()
{
    StaticCounter state;
    StaticCounter::call(); // 1
    state.get();
    StaticCounter::call(); // 2
    state.get();
    state.call();
    state.get();
    return 0;
}