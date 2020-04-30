#include <iostream>
#include <algorithm>
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

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

using A = array<int, 1<<16>;
int main() {
    int n, c;
    while(cin >> n >> c, n){
        vector<int> a(n), b(c);
        for (int i = 0; i < n; ++i) {
            int val = 0;
            for (int j = 0; j < 16; ++j) {
                int x;
                cin >> x;
                val |= x << j;
            }
            a[i] = val;
        }
        for (int i = 0; i < c; ++i) {
            int val = 0;
            for (int j = 0; j < 16; ++j) {
                int x;
                cin >> x;
                val |= x << j;
            }
            b[i] = val;
        }
        vector<int> cnt(1 << 16);
        for (int k = 0; k < 1<<16; ++k) {
            for (int i = 0; i < 16; ++i) {
                if(k & (1 << i)) cnt[k] = cnt[k^(1 << i)]+1;
            }
        }
        vector<A> dp(n+1);
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 1 << 16; ++j) {
                if(!dp[i][j]) continue;
                int jj = j|a[i];
                for (int k = 0; k < c; ++k) {
                    chmax(dp[i+1][jj^(jj&b[k])], dp[i][j]+cnt[jj&b[k]]);
                }
            }
        }
        cout << *max_element(dp.back().begin(),dp.back().end())-1 << "\n";
    }

    return 0;
}