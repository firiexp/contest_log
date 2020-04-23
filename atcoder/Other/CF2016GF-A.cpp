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
    int n;
    cin >> n;
    vector<pair<int, int>> v(2*n);
    for (int i = 0; i < n; ++i) {
        int a; scanf("%d", &a);
        v[i] = make_pair(a, 0);
    }
    for (int i = 0; i < n; ++i) {
        int a; scanf("%d", &a);
        v[n+i] = make_pair(a, 1);
    }
    sort(v.begin(), v.end());
    int k = v[0].second, u = 1;
    ll ans = 1;
    for (int i = 1; i < 2*n; ++i) {
        if(u == 0){
            k = v[i].second;
            u = 1;
            continue;
        }
        if(v[i].second == k) u++;
        else {
            (ans *= u) %= MOD;
            u--;
        }
    }
    cout << ans << "\n";
    return 0;
}
