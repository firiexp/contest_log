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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

bool IsKadomatsu(int a, int b, int c){
    if(min({a, b, c}) == 0) return true;
    if(a == b || b == c || c == a) return false;
    return max({a, b, c}) == b || min({a, b, c}) == b;
}

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int dp[51][51][51];
int main() {
    int n, c;
    cin >> n >> c;
    vector<int> l(n), w(n);
    for (auto &&i : l) scanf("%d", &i);
    for (auto &&j : w) scanf("%d", &j);
    for (auto &&k : dp) for (auto &&m : k) fill(begin(m), end(m), -1);
    dp[c][0][0] = 0;
    int ans = 0;
    for (int i = c; i >= 0; --i) {
        for (int j = 0; j <= 50; ++j) {
            for (int k = 0; k <= 50; ++k) {
                if(!(~dp[i][j][k])) continue;
                for (int m = 0; m < n; ++m) {
                    if(w[m] > i) continue;
                    if(IsKadomatsu(j, k, l[m])){
                        chmax(dp[i-w[m]][k][l[m]], dp[i][j][k]+l[m]);
                        if(j && k) {
                            chmax(ans, dp[i-w[m]][k][l[m]]);
                        }
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}