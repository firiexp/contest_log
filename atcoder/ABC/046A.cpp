#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int x = (a != b) + (b != c) + (c != a) + (a == b && b == c);
    cout << x;
}