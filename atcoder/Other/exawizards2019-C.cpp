#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, q; string s;
    cin >> n >> q >> s;
    vector<pair<char, int>> v(q);
    for (int i = 0; i < q; ++i) {
        char a, b;
        cin >> a >> b;
        v[i] = make_pair(a, (b == 'L' ? -1 : 1));
    }
    int ok = -1, ng = n, l, r;
    while(ng-ok > 1){
        int mid = (ok+ng)/2;
        int cur = mid;
        for (int i = 0; i < q; ++i) {
            if(s[cur] == v[i].first) {
                cur += v[i].second;
            }
            if(cur < 0 || cur >= n) break;
        }
        if(cur < 0) ok = mid;
        else ng = mid;
    }
    l = ok, ok = n, ng = -1;
    while(ok-ng > 1){
        int mid = (ok+ng)/2;
        int cur = mid;
        for (int i = 0; i < q; ++i) {
            if(s[cur] == v[i].first) {
                cur += v[i].second;
            }
            if(cur < 0 || cur >= n) break;
        }
        if(cur >= n) ok = mid;
        else ng = mid;
    }
    r = ok;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if(l < i && i < r) ans++;
    }
    cout << ans << "\n";
    return 0;
}
