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

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

vector<vector<ll>> v;
ll h, w;

ll solve(ll y, ll x){
    cout << y << " " << x << " ";
    ll ans = 0;
    ll a = y/h, b = x/w;
    ans += (a*b/2*h*w)+(a*b%2*v[h][w]); // migiue
    y -= a*h, x -= b*w;
    cout << y << " " << x << " ";
    ans += y*w*(b/2); // miginomigi
    ans += x*h*(a/2); // uenoue
    ll parity = (a^b)&1^1;
    ans += (parity ? y*x-v[y][x] : v[y][x]); // migishita
    if(a & 1) ans += (parity ? h*x-v[h][x] : v[h][x]);
    if(b & 1) ans += (parity ? y*w-v[y][w] : v[y][w]);
    cout << parity << "\n";
    return ans;
}

int main() {
    int q;
    cin >> h >> w >> q;
    v = make_v(h+1, w+1, 0LL);
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            v[i+1][j+1] = s[j]-'0';
        }
    }
    for (int i = 0; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            v[i][j] += v[i][j-1];
        }
    }
    for (int i = 1; i <= h; ++i) {
        for (int j = 0; j <= w; ++j) {
            v[i][j] += v[i-1][j];
        }
    }
    while(q--){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        x1--; y1--;
        ll ans = solve(x2, y2)-solve(x1, y2)-solve(x2, y1)+solve(x1, y1);
        printf("%lld\n", ans);
    }
    return 0;
}