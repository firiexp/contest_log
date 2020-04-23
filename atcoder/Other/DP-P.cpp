#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>


static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }


int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d%d",&a, &b);
        v[a-1].emplace_back(b-1);
        v[b-1].emplace_back(a-1);
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
        for (auto &&i : v[a]) {
            if(!visited[i]) s.emplace(i);
        }
    }
    auto dp = make_v(n, 2, -1LL);
    ll ans;
    while(!Q.empty()){
        int a = Q.front(); Q.pop_front();
        ll b = 1, w = 1;
        for (auto &&i : v[a]) {
            if(dp[i][0] != -1){
                (b *= dp[i][1]) %= MOD;
                (w *= (dp[i][0]+dp[i][1])) %= MOD;
            }
        }
        dp[a][0] = b, dp[a][1] = w;
        (ans = dp[a][0] + dp[a][1]) %= MOD;
    }
    cout << ans << "\n";
    return 0;
}
