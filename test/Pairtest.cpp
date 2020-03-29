#include "../Pair.hpp"
#include "../String.hpp"
#include "../Vector.hpp"
#include <iostream>

using namespace std;

int main() {
    int a = 1;
    cout << Make_pair("pig", 1).first << endl;
    cout << Make_pair("pig", a).second << endl;

    Pair<String, int> String_int("pig", 1);
    cout << String_int.first << ' ' << String_int.second << endl;
    Pair<String, int> String_int_2(Make_pair("pig", 1));
    Pair<String, int> String_int_3 = Make_pair("pig", 1);
    cout << String_int_2.first << ' ' << String_int_3.second << endl;
}