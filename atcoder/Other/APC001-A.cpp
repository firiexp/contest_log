#include <iostream>
using ll = long long;
using namespace std;

int main() {
    ll x, y;
    cin >> x >> y;
    if(x % y == 0) {
        cout << -1 << "\n";
        return 0;
    }else {
        cout << x*(y-1) << "\n";
    }
    return 0;
}
