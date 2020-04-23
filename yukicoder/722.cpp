#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    ll a, b;
    cin >> a >> b;
    bool i1 = false, i2 = false;
    for (int i = -9; i <= 9; ++i) {
        if(i != 0){
            for (int j = 100; j <= 10000000; j *= 10) {
                if(i*j == a) i1 = true;
                if(i*j == b) i2 = true;
            }
        }
    }
    ll x = a*b;
    if(i1 && i2) x /= 10;
    else if(abs(x) >= 100000000) {
        puts("E");
        return 0;
    }
    cout << x << "\n";
    return 0;
}
