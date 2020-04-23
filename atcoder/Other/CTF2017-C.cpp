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
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;
int main() {
    int n, k;
    cin >> n >> k;
    GPQ<pair<ll, int>> Q;
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        Q.emplace((ll)a, b);
    }
    ll ans = 0;
    for (int i = 0; i < k; ++i) {
        auto p = Q.top(); Q.pop();
        ans += p.first;
        Q.emplace(p.first+p.second, p.second);
    }
    cout << ans << "\n";
    return 0;
}
