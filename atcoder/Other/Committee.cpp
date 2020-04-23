#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<vector<int>> G(n);
    for (int i = 0; i < n; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        v[i] = b;
        if(a) {
            G[a-1].emplace_back(i);
            G[i].emplace_back(a-1);
        }
    }
    deque<int> Q;
    stack<int> s;
    int cnt = 0;
    vector<int> visited(n, 0), num(n);
    s.emplace(0);
    while(!s.empty()){
        int a = s.top(); s.pop();
        visited[a]++;
        num[a] = cnt++;
        Q.emplace_front(a);
        for (auto &&i : G[a]) {
            if(!visited[i]) s.emplace(i);
        }
    }
    auto dp = make_v(n, 2, -INF<int>);
    for (auto &&i : Q) {
        dp[i][0] = v[i];
        for (auto &&j : G[i]) {
            if(num[i] < num[j]){
                dp[i][1] = max({dp[i][1], dp[j][0], dp[j][1]});
                if(dp[j][0] > 0) dp[i][0] += dp[j][0];
            }
        }
    }
    cout << max(dp[0][0], dp[0][1]) << "\n";
    return 0;
}