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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "(" << p.first << "," << p.second << ")";
}

template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "{";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ",";
        os << v[i];
    }
    return os << "}";
}
bool IsKadomatsu(int a, int b, int c){
    if(a == b || b == c || c == a) return false;
    return max({a, b, c}) == b || min({a, b, c}) == b;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> ans(3, INF<int>);
    vector<int> dp(1<<n);
    int w = n%3;
    for (int x = 0; x < (1<<n); ++x) {
        if(__builtin_popcount(x)%3 != w) continue;
        for (int i = 0; i < n; ++i) {
            if(!(x & (1 << i))) continue;
            for (int j = i+1; j < n; ++j) {
                if(!(x & (1 << j))) continue;
                for (int k = j+1; k < n; ++k) {
                    if(!(x & (1 << k))) continue;
                    if(!IsKadomatsu(v[i], v[j], v[k])) continue;
                    if(dp[x - (1 << i) - (1 << j) - (1 << k)] == 0) {
                        dp[x] = 1;
                        if(x == (1 << n)-1){
                            ans = min(ans, vector<int>{i, j, k});
                        }
                    }
                }
            }
        }
    }
    if(dp[(1 << n) - 1]){
        printf("%d %d %d\n", ans[0], ans[1], ans[2]);
    }else puts("-1");
    return 0;
}
