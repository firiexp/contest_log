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
    int n, ans = 0;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) cin >> i;
    for (int i = 0; i < n-2; ++i) {
        if((v[i] < v[i+1] && v[i+1] > v[i+2] && v[i] != v[i+2]) || (v[i] > v[i+1] && v[i+1] < v[i+2] && v[i] != v[i+2])) ans++;
    }
    cout << ans << "\n";
    return 0;
}
