#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    int r, c, ans = 0;
    cin >> r >> c;
    for (int i = c; i <= r+c; i += c) {
        for (int j = c; j <= r+c; j += c) {
            if(i*i + j*j <= r*r) ans++;
        }
    }
    cout << ans*4 << "\n";
    return 0;
}
