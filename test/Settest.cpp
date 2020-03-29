#include "../Set.hpp"
#include "../String.hpp"
#include <iostream>


using namespace std;

int main()
{
    Set<int> set;
    set.clear();
    cout << "Set insert " << endl;
    for(int i = 100; i > 0; --i)
    set.insert(rand()%97);
    for(int i : set)
    cout << i << ' ';
    cout << endl;


    cout << "erase 30~87" << endl;
    for(int i = 30; i<87; ++i)
    set.erase(i);
    for(int i : set)
    cout << i << ' ';
    cout << endl;
    set.clear();
   Set<String> set_s;
    String a = "a";
    set_s.insert(a);
    set_s.insert("abc");
    set_s.insert("ccc");
    set_s.insert("bcd");
    set_s.insert("bbb");
    set_s.insert("abc");
    for(auto i : set_s)
    cout << i << ' ';
    cout << endl;
}