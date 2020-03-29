#include "../List.hpp"
#include <iostream>

using namespace std;

int main() {
    List<long> l;

    cout << "push_back 1~10 " << endl;
    for (int i = 0; i < 10; ++i)
        l.push_back(i);

    for (auto i = l.begin(); i != l.end(); ++i)
        cout << i.iter->data << ' ';
    cout << endl;

    cout << "erase begin()+1" << endl;
    l.erase(l.begin() + 1);
    for (long i : l)
        cout << i << ' ';
    cout << endl;

    cout << "erase end()-1" << endl;
    l.erase(l.end() - 1);
    for (long i : l)
        cout << i << ' ';
    cout << endl;

    cout << "reverse" << endl;
    l.reverse();
    for (long i : l)
        cout << i << ' ';
    cout << endl;

    cout << "clear" << endl;
    l.clear();
    for (long i : l)
        cout << i << ' ';
    cout << endl;
}
