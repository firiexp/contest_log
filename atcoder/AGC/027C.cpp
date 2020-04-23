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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<vector<int>> G(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    string t = "AABBAABBAA";
    auto dp = make_v(5, n, 0);
    for (int i = 0; i < n; ++i) dp[0][i] = (s[i] == 'A');
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < n; ++j) {
            if(!dp[i][j]) continue;
            for (auto &&k : G[j]) {
                if(s[k] == t[i+1]){
                    dp[i+1][k] |= dp[i][j];
                }
            }
        }
    }
    puts(*max_element(dp.back().begin(),dp.back().end()) ? "Yes" : "No");
    cout << n << "\n";
    return 0;
}