#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int a, b, x;
    cin >> a >> b >> x;
    if (a <= x && x <= a + b) cout << "YES";
    else cout << "NO";
    return 0;
}