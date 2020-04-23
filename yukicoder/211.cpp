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
    int k, x[] = {2,3,5,7,11,13}, y[] = {4,6,8,9,10,12};
    cin >> k;
    int ans = 0;
    for (int i : x) {
        for (int j : y) {
            if(i * j == k) ans++;
        }
    }
    cout << setprecision(20) << (long double)ans/36.0 << "\n";
    return 0;
}
