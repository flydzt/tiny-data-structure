#include "../String.hpp"
#include "../Skiplist.hpp"
#include <iostream>

using namespace std;

int main() {

    Skiplist<int> sint;
    for (int i : sint)
        cout << i << ' ';
    cout << endl;
    for (int i = 0; i < 1000; ++i) {
        cout << i << ' ';
        sint.insert(i);
    }
    for (int i:sint)
        cout << i << ' ';
    cout << endl;
    for (int i = 29; i < 100; ++i)
        sint.erase(i);
    for (int i : sint)
        cout << i << ' ';
    cout << endl;
    sint.clear();
    cout << "clear" << endl;
    for (int i : sint)
        cout << i << ' ';
    cout << endl;
    cout << "string" << endl;
    Skiplist<String> str;
    String s = "a";
    for (int i = 0; i < 1000; ++i) {
        cout << i << ' ';
        str.insert(s);
    }
    for (auto i : str)
        cout << i << ' ';
    cout << endl;
}