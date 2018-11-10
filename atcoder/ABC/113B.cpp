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
    int n, t, a;
    cin >> n >> t >> a;
    a *= 1000;
    t *= 1000;
    int k = INF<int>, x = 0;
    for (int i = 0; i < n; ++i) {
        int h;
        cin >> h;
        if(abs(a-t+6*h) <= k) {
            k = abs(a-t+6*h);
            x = i;
        }
    }
    cout << x+1 << "\n";
    return 0;
}
