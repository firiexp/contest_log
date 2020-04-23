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

int main() {
    u32 w, h;
    cin >> w >> h;
    vector<ll> v(w+h);
    int k = w+1, l = h+1;
    for (int i = 0; i < w; ++i) {
        int x;
        scanf("%d", &x);
        v[i] = x*2;
    }
    for (int i = 0; i < h; ++i) {
        int x;
        scanf("%d", &x);
        v[w+i] = x*2+1;
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for (int i = 0; i < w+h; ++i) {
        if(v[i]%2) {
            ans += v[i]/2 * (k);
            l--;
        }else {
            ans += v[i]/2 * (l);
            k--;
        }
    }
    cout << ans << "\n";
    return 0;
}
