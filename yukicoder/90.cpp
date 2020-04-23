#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <typename T>
struct edge {
    int from, to;
    T cost;

    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}

    explicit operator int() const {return to;}
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> v(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        v[b].emplace_back(a, c);
    }
    vector<int> dp(1<<n, 0);
    for (int i = 0; i < (1<<n); ++i) {
        for (int j = 0; j < n; ++j) {
            if(i & (1<<j)){
                int s = dp[i^(1<<j)];
                for (auto &&k : v[j]) {
                    if(i & (1<<k.first)){
                        s += k.second;
                    }
                }
                dp[i] = max(dp[i], s);
            }
        }
    }
    cout << dp[(1<<n)-1] << "\n";
    return 0;
}
