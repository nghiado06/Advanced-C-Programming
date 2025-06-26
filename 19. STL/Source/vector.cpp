#include <iostream>
#include <vector>
using namespace std;

/*
    Method
    - at()
    - size()
    - resize()
    - push_back
    - pop_back()
    - insert()
    - begin(): trỏ đến địa chỉ phần tử đầu tiên
    - end(): trỏ đến địa chỉ sau phần tử cuối cùng
    - erase()

*/

/*
    iterator: bộ lặp
    - Nó hoạt động giống con trỏ nhưng không phải là con trỏ
    - Nó như class bên trong class vector. Vì là một class nên nó cần khởi tạo đối tượng
và đối tượng này hoạt động như con trỏ và cần được gán địa chỉ vào.
class vector
{
    private:
        T *data;
    public:
    int size()
    void clear();
    ...

    class iterator
    {
        private:
            T *ptr;
        public:
            void operator ++ (){}
            bool operator != (){}

            T operator * ()
            {
                return *ptr;
            }
    }
}
*/
// template <typename T>
class SinhVien
{
private:
    int id;

public:
    void setID(int id)
    {
        SinhVien::id = id;
    }

    void getID()
    {
        cout << "MSSS: " << SinhVien::id << endl;
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};
    vector<int> v1(5);
    vector<int> v2(8, 3);
    vector<int> v4(15, 6);
    vector<vector<int>> v5 = {{1, 2, 3}, {4, 5}, {6, 7, 8, 9}};
    vector<SinhVien> listSV;

    // THÊM BỚT
    v1.pop_back();
    v1.push_back(15);

    v2.insert(v2.begin(), 12);
    v2.insert(v2.begin() + 1, 21);

    v.erase(v.end() - 1); // pop_back
    v.erase(v.begin());   // Tương đương hàm pop_front

    v4.erase(v4.begin() + 3, v4.begin() + 10);
    // KIỂM TRA

    cout << "Kích thước của vector: " << v.size() << endl;
    cout << "Giá trị phần tử 0: " << v.at(0) << endl;

    // Cách 1:
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }

    cout << endl;

    // Cách 2: range-based for loop

    for (const int &vector : v) // Sử dụng tham chiếu để giảm tiêu hao bộ nhớ
    {
        cout << vector << " ";
    }

    cout << endl;

    for (const int &item : v1)
    {
        cout << item << " ";
    }
    cout << endl;

    for (const int &item : v2)
    {
        cout << item << " ";
    }
    cout << endl;

    for (const int &item : v4)
    {
        cout << item << " ";
    }
    cout << endl;

    // Cách 3: dùng iterator
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        SinhVien sv;
        sv.setID(2412260 + i);
        listSV.push_back(sv);
    }

    for (SinhVien &item : listSV)
    {
        item.getID();
    }

    return 0;
}