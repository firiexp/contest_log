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

int main() {
    int n = 25;
    vector<int> v(n);
    vector<int> cnt(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if(v[i]) cnt[v[i]-1] = i+1;
    }
    auto f = [](int x, int k) {
        int i = x%5, j = x/5;
        return (((i != 0 && i != 4) && (((k & (1 << (x-1))) != 0)^((k & (1 << (x+1))) != 0))) |
                ((j != 0 && j != 4) && (((k & (1 << (x-5))) != 0)^((k & (1 << (x+5))) != 0)))) != 0;
    };

    vector<int> dp(1<<25); dp[0] = 1;
    for (int S = 1; S < (1<<25); ++S) {
        int pcnt = __builtin_popcount(S);
        if(cnt[pcnt-1]){
            if(!f(cnt[pcnt-1]-1, S)) (dp[S] = dp[S^(1 << (cnt[pcnt-1]-1))]) %= MOD;
        }
        else {
            for (int i = 0; i < 25; ++i) {
                if(S & (1 << i) && !f(i, S)) (dp[S] += dp[S ^ (1 << i)]) %= MOD;
            }
        }

    }
    cout << dp.back() << "\n";
    return 0;
}