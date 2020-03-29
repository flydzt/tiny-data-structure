#include "../Vector.hpp"
#include <iostream>
#include "../List.hpp"

using namespace std;

int main() {
    Vector<int> v_int;
//    cout << *v_int.begin()<< endl;
    v_int.push_back(1);
    v_int.push_back(2);


    for (int i = 0; i < v_int.size(); ++i)
        cout << v_int[i] << ' ';
    cout << endl;

    v_int.clear();
    cout << endl;
    cout << "after clear" << endl;
    cout << "capacity: " << v_int.capacity() << endl;
    cout << "size: " << v_int.size() << endl;
    cout << endl;

    cout << "try to output" << endl;
    for (auto i : v_int)
        cout << i << ' ';
    cout << endl;
    cout << "output finish" << endl;
    cout << endl;

    cout << "begin push_back" << endl;
    for (int i = 0; i < 4000; ++i) {
        v_int.push_back(i);
        if (i % 1007 == 1) {
            cout << "capacity: " << v_int.capacity() << endl;
            cout << "size: " << v_int.size() << endl;
        }
    }
    cout << endl;
    cout << "begin pop_back" << endl;

    for (int i = 0; i < 5; ++i) {
        cout << "pop " << v_int.pop_back() << endl;
        cout << "capacity: " << v_int.capacity() << endl;
        cout << "size: " << v_int.size() << endl;
    }
    v_int.clear();
    cout << "after clear()" << endl;
    for (auto i : v_int)
        cout << i << ' ';
    cout << endl;

    v_int.destroy();
    cout << endl;
    cout << "after destroy" << endl;
    for (auto i : v_int)
        cout << i << ' ';
    cout << endl;

    cout << "init from a int_array" << endl;
    int a[3] = {0, 1, 2};
    Vector<int> v(a, a + 3);
    for (auto i : v)
        cout << i << ' ';
    cout << endl;

    cout << "init from a int_list" << endl;
    List<int> l;
    for (int i = 0; i < 4; ++i)
        l.push_back(i);
    Vector<int> v_list(l.begin(), l.end());
    for (auto i : v_list)
        cout << i << ' ';
    cout << endl;

    cout << "erase begin() twice" << endl;
    v_list.erase(v_list.begin());
    v_list.erase(v_list.begin());
    for (auto i: v_list)
        cout << i << ' ';
    cout << endl;


    cout << "size: " << v_list.size() << " capacity: " << v_list.capacity() << endl;
    cout << "insert end() and begin()" << endl;
    v_list.insert(v_list.end(), 10);
    v_list.insert(v_list.begin(), 20);
    v_list.insert(v_list.begin(), 30);
    cout << "size: " << v_list.size() << " capacity: " << v_list.capacity() << endl;
    for (auto i : v_list)
        cout << i << ' ';
    cout << endl;
}