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
    int n, sum = 0, ans = 0;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        sum += k;
        v.emplace_back(k);
    }
    for (int i = 0; i < n; ++i) {
        if(v[i]*10 <= sum) ans += 30;
    }
    cout << ans << "\n";
    return 0;
}
