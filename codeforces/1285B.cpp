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

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &&i : v) scanf("%d", &i);
        int ok = 1;
        vector<ll> S(n+1);
        for (int i = 0; i < n; ++i) {
            S[i+1] = S[i]+v[i];
        }
        ll x = 0, val = -INF<ll>;
        for (int i = 1; i < n; ++i) {
            val = max(val, S[i]-x);
            x = min(x, S[i]);
        }
        for (int i = 1; i < n; ++i) {
            val = max(val, S[n]-S[i]);
        }
        if(val < S[n]){
            puts("YES");
        }else {
            puts("NO");
        }
    }
    return 0;
}