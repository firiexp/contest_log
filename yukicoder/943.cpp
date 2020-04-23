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
    auto v = make_v(n, n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
        }
    }
    vector<int> u(n);
    for (auto &&k : u) scanf("%d", &k);
    int ans = INF<int>;
    queue<int> Q;

    vector<int> deg(n);
    for (int i = 0; i < (1 << n); ++i) {
        int s = 0;
        vector<vector<int>> G(n);
        fill(deg.begin(),deg.end(), 0);
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if(!(i & (1 << k)) && v[k][j]){
                    G[k].emplace_back(j);
                    deg[j]++;
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            if(i & (1 << j)) s += u[j];
        }
        for (int j = 0; j < n; ++j) {
            if(!deg[j]) Q.emplace(j);
        }
        int cnt = 0;
        while(!Q.empty()){
            int x = Q.front(); Q.pop();
            cnt++;
            for (auto &&j : G[x]) {
                deg[j]--;
                if(!deg[j]) Q.emplace(j);
            }
        }
        if(cnt == n){
            ans = min(ans, s);
        }
    }
    cout << ans << "\n";
    return 0;
}