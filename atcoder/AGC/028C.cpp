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
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<pair<int, int>> v(2*n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a[i], &b[i]);
        v[2*i] = {a[i], 2*i}, v[2*i+1] = {b[i], 2*i+1};
    }
    sort(v.begin(), v.end());
    vector<int> cnt(n);
    ll ans = 0; int p = 0;
    for (int i = 0; i < n; ++i) {
        cnt[v[i].second/2]++;
        p += v[i].second % 2;
        ans += v[i].first;
    }
    for (int i = 0; i < n; ++i) {
        if(cnt[i] > 1){
            cout << ans << "\n";
            return 0;
        }
    }
    if(p == n || p == 0){
        cout << ans << "\n";
        return -0;
    }
    if(v[n].second/2 == v[n-1].second/2){
        cout << ans +
            min(v[n+1].first - v[n-1].first,
                v[n].first - v[n-2].first) << "\n";
    }else {
        cout << ans + v[n].first - v[n-1].first << "\n";
    }
    return 0;
}
