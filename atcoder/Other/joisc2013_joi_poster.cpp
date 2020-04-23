#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

ll sq(ll n){
    return n*n;
}

int main() {
    ll n, w, h;
    cin >> n >> w >> h;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        v[i] = make_pair(a, b);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i == j) continue;
            ll xa, ya;
            tie(xa, ya) = v[i];
            ll xb, yb;
            tie(xb, yb) = v[j];
            ll a = sq(xa-xb)+sq(ya-yb);
            ll p = sq(min({xa, w-xa, ya, h-ya}));
            if(a > p) continue;
            for (int k = 0; k < n; ++k) {
                if(j == k || i == k) continue;
                ll xc, yc;
                tie(xc, yc) = v[k];
                for (int l = 0; l < n; ++l) {
                    if(i == l || j == l || k == l) continue;
                    ll xd, yd;
                    tie(xd, yd) = v[l];
                    ll b = sq(xa-xc)+sq(ya-yc);
                    ll c = sq(xc-xd)+sq(yc-yd);
                    if(a-b-c>0 && sq(a-b-c) > b*c*4) ans++;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
