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
    int n;
    cin >> n;
    vector<int> ys(n), xs(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &xs[i], &ys[i]);
    }
    ll ans = 0, k = 0;
    map<pair<int, int>, set<ll>> v;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            int a = ys[j]-ys[i], b = xs[j]-xs[i];
            int g = __gcd(a, b); a /= g; b /= g;
            if(a < 0 || (a == 0 && b < 0)){
                a = -a;
                b = -b;
            }
            auto x = make_pair(a, b);
            ll c = a*xs[i]-b*ys[i];
            if(!v[x].count(c)){
                k++;
                v[x].insert(c);
                ans += k - v[x].size();
            }
        }
    }
    cout << ans << "\n";
    return 0;
}