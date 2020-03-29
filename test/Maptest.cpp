#include "../Map.hpp"
#include "../String.hpp"
#include <iostream>

using namespace std;


int main() {
    cout << "insert rand num" << endl;
    Map<int, int> map_int_int;
    for (int i = 0; i < 100; ++i)
        map_int_int.insert(rand() % 100, rand() % 100);

    for (int i = 0; i < 100; ++i)
        map_int_int.insert(Pair<int, int>(rand() % 100, rand() % 100));

    for (auto i : map_int_int)
        cout << i.first << ':' << i.second << ' ';
    cout << endl;

    cout << endl << "for 1:100 map[i] = i" << endl;
    for (int i = 0; i < 100; ++i)
        map_int_int[i] = i;

    for (auto i : map_int_int)
        cout << i.first << ':' << i.second << ' ';
    cout << endl;

    cout << endl << "erase 30-58" << endl;
    for (int i = 30; i < 58; ++i)
        map_int_int.erase(i);

    for (auto i : map_int_int)
        cout << i.first << ':' << i.second << ' ';
    cout << endl;

    map_int_int.insert(1, 3);
    cout << 1 << ':' << map_int_int[1] << endl;

    Map<String, int> map_str_int;
    cout << "insert" << endl;
    map_str_int.insert("a", 1);
    cout << "insert a" << endl;
    map_str_int.insert("b", 2);

    map_str_int.insert("c", 3);
    cout << map_str_int["a"] << endl
         << map_str_int["b"] << endl
         << map_str_int["c"] << endl;
    map_str_int["d"] = 4;
    map_str_int["e"] = 5;
    map_str_int["f"] = 6;
    cout << map_str_int["d"] << endl
         << map_str_int["e"] << endl
         << map_str_int["f"] << endl;
}