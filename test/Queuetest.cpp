#include "../Dequeue.hpp"
#include <iostream>

using namespace std;

int main() {
    Dequeue<int> q;

    cout << "push_back" << endl;
    for (int i = 0; i < 10; ++i)
        q.push_back(i);
    for (int i: q)
        cout << i << ' ';
    cout << endl;

    cout << "pop front" << endl;
    for (int i = 0; i < 10; ++i)
        cout << q.pop_front() << ' ';
    cout << endl;
}
