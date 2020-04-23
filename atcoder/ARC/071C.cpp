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
    string s, t;
    cin >> s >> t;
    vector<ll> v(s.size()+1, 0), v2(t.size()+1, 0);
    ll sum = 0;
    for (int i = 0; i < s.size(); ++i) {
        sum += (s[i] == 'A' ? 1 : 2);
        v[i+1] = sum;
    }
    sum = 0;
    for (int i = 0; i < t.size(); ++i) {
        sum += (t[i] == 'A' ? 1 : 2);
        v2[i+1] = sum;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b ,&c, &d);
        ll x = v[b]-v[a-1], y = v2[d]-v2[c-1];
        x = x%3, y = y%3;
        puts(x == y ? "YES" : "NO");
    }
    return 0;
}
