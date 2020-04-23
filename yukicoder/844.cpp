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
    int n, m; ll a;
    cin >> n >> m >> a;
    vector<ll> dp1(n+1, -INF<ll>), dp2(n+1, 0);
    dp1[0] = 0;
    vector<tuple<int, int, ll>> v(m);
    for (int i = 0; i < m; ++i) {
        int l, r; ll cost;
        cin >> l >> r >> cost;
        l--;
        v[i] = make_tuple(r, l, cost);
    }
    sort(v.begin(),v.end());
    int cur = 0;
    for (int i = 0; i < m; ++i) {
        int l, r; ll cost;
        tie(r, l, cost) = v[i];
        while(cur < r){
            dp2[cur+1] = max({dp2[cur+1], dp1[cur], dp2[cur]});
            cur++;
        }
        dp1[r] = max({dp1[r], dp1[l]+cost-a*(r != n), dp2[l]+cost-a-a*(r != n)});
    }
    cout << max(*max_element(dp1.begin(),dp1.end()),
            *max_element(dp2.begin(),dp2.end())) << "\n";
    return 0;
}