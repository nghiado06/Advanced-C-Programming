/*
List là cấu trúc dữ liệu danh sách đôi.
Khác với linked list, list chứa các node có 3 phần tử:
    - Data: Chứa dữ liệu hiện tại đã được sử dụng template
    - Pre: con trỏ trỏ đến node phía trước
    - Next: con trỏ trỏ đến node tiếp theo
Giống với linked list, địa chỉ của các node không liền kề nhau
 */
#include <iostream>
#include <list>
using namespace std;

int main()
{
    // Khai báo
    list<int> lst = {1, 2, 3, 4, 5};

    lst.push_back(10);
    lst.push_front(20);

    lst.pop_back();
    lst.pop_front();

    lst.insert(lst.begin(), 100);
    lst.insert(lst.end(), 200);

    // lst.insert(lst.begin() + 1, 150);

    auto it2 = lst.begin();
    int index = -1;
    for (it2 = lst.begin(); it2 != lst.end(); it2++)
    {
        index++;
        if (index == 2)
        {
            lst.insert(it2, 150);
        }
    }

    it2 = lst.begin();
    index = -1;
    for (it2 = lst.begin(); it2 != lst.end(); it2++)
    {
        index++;
        if (index == 4)
        {
            lst.erase(it2);
        }
    }

    // Duyệt
    for (const int &item : lst)
    {
        cout << item << " ";
    }
    cout << endl;

    list<int>::iterator it;
    for (it = lst.begin(); it != lst.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    for (auto it1 = lst.rbegin(); it1 != lst.rend(); it1++)
    {
        cout << *it1 << " ";
    }
    cout << endl;

    list<int>::reverse_iterator rit;
    for (rit = lst.rbegin(); rit != lst.rend(); rit++)
    {
        cout << *rit << " ";
    }
    cout << endl;

    return 0;
}