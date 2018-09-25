#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    a += b;
    a >= 10 ? cout << "error" : cout << a;
    return 0;
}