#include "../String.hpp"


using namespace std;

int main() {
    String a;
    String b(3, 'b');
    char str[4] = "ccc";
    String c(str);
    String d(c);
    String e("eee");
    a = b;
    String f = "fff";
    String g = f;
    cout << a << endl
         << b << endl
         << c << endl
         << d << endl
         << e << endl;
    cin >> g;
    cout << g << endl;
    g += g;
    g += str;
    String h = g + g;
    cout << g << endl
         << h << endl;


}