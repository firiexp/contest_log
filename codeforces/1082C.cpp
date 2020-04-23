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
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> v;
    for (int i = 0; i < n; ++i) {
        int s, r;
        scanf("%d %d", &s, &r);
        v[s].emplace_back(r);
    }
    vector<ll> ans(n, 0);
    for (auto &&x : v) {
        sort(x.second.begin(), x.second.end(), greater<>());
        ll s = 0;
        for (int i = 0; i < x.second.size(); ++i) {
            s += x.second[i];
            if(s > 0) ans[i] += s;
        }
    }
    ll ret = 0;
    for (int i = 0; i < n; ++i) {
        ret = max(ret, ans[i]);
    }
    cout << ret << "\n";
    return 0;
}
