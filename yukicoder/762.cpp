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

int main() {
    int n, m;
    string s, t = "PDCA";
    cin >> n >> m >> s;
    int ans = 0;
    vector<vector<int>> G(n);
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = (s[i] == 'P');
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        G[a-1].emplace_back(b-1);
        G[b-1].emplace_back(a-1);
    }
    for (int c = 1; c < 4; ++c) {
        for (int i = 0; i < n; ++i) {
            for (auto &&j : G[i]) {
                if(s[i] == t[c-1] && s[j] == t[c]){
                    (v[j] += v[i]) %= MOD;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if(s[i] == 'A'){
            (ans += v[i]) %= MOD;
        }
    }
    cout << ans << "\n";
    return 0;
}
