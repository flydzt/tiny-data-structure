#include "../Stack.hpp"
#include <iostream>

using namespace std;

int main() {
    Stack<int> s;
    cout << "push_back" << endl;
    for (int i = 0; i < 100; ++i)
        s.push_back(i);
    for (int i : s)
        cout << i << ' ';
    cout << endl;

    cout << "pop_back" << endl;
    for (int i = 0; i < 100; ++i)
        cout << s.pop_back() << ' ';
    cout << endl;
}