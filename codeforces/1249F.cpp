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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<vector<int>> G(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b; scanf("%d %d", &a, &b); a--; b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    auto dp = make_v(n, n+1, -INF<int>);
    deque<int> Q;
    vector<int> num(n);
    {
        stack<int> s;
        int cnt = 0;
        vector<int> visited(n, 0);
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
    }
    for (auto &&i : Q) {
        dp[i][0] = v[i];
        for (auto &&j : G[i]) {
            if(num[i] < num[j]) {
                for (int l = 0; l < n; ++l) {
                    if(dp[i][l] < 0) break;
                    int val = dp[i][l];
                    for (int m = 0; m < n; ++m) {
                        if(dp[j][m] < 0) break;
                        if(l+m+1 > k){
                           chmax(dp[i][min(l, m+1)], val+dp[j][m]);
                        }
                    }
                }
                for (int l = 0; l < n-1; ++l) {
                    dp[i][l+1] = max(dp[i][l+1], dp[j][l]);
                }
            }
        }
    }
    cout << *max_element(dp.front().begin(),dp.front().end()) << "\n";
    return 0;
}