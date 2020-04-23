#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    int x;
    cin >> a >> b >> c;
    x = (a == 7) + (a == 5)*10  + (b == 7) + (b == 5) * 10  + (c == 7) + (c == 5)*10;
    if (x == 21) cout << "YES";
    else cout << "NO";
    return 0;
}
