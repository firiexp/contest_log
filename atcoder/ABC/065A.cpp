#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int a, b, x;
    cin >> x >> a >> b;
    if (b-a > x) cout << "dangerous";
    else if (b > a) cout << "safe";
    else cout << "delicious";
    return 0;
}