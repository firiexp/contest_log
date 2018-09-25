#include <iostream>
using ll = long long;
using namespace std;

int main() {
    ll x, y;
    cin >> x >> y;
    int c = 0;
    for (ll i = x; i <= y; i*=2) {
        c++;
    }
    cout << c << "\n";
    return 0;
}
