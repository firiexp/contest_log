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
    int n;
    cin >> n;
    map<int , int> v;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        v[k]++;
    }
    int ans = 0;
    for (auto &&j : v) {
        if(j.second == 1) ans++;
    }
    cout << ans << "\n";
    return 0;
}
