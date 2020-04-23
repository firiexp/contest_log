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
    vector<ll> vv(5);
    for (auto &&j : vv) scanf("%lld", &j);
    reverse(vv.begin(),vv.end());
    vector<ll> v(75, 1);
    for (int i = 2; i < 75; ++i) {
        v[i] = v[i-1]+v[i-2];
    }
    int ans = 0;
    for (int len = 1; len <= 5; ++len) {
        for (int i = 0; i+len < 75; ++i) {
            int ok = 1;
            for (int j = 0; j < len; ++j) {
                if(v[i+j] != vv[j]) ok = 0;
            }
            if(ok) ans = max(ans, len);
        }
    }
    cout << ans << "\n";
    return 0;
}