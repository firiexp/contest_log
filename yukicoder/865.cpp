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


template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "{";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ", ";
        os << v[i];
    }
    return os << "}";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "{" << p.first << ", " << p.second << "}";
}


int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> s(n+1);
    for (int i = 0; i < n; ++i) {
        s[i+1] = s[i] + v[i];
    }
    vector<int> u(n-23);
    int ans = 0;
    for (int i = 0; i < n-23; ++i) {
        u[i] = s[i+24]-s[i];
        ans = max(ans, u[i]);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int t, x; scanf("%d %d", &t, &x);
        t--;
        int y = x-v[t];
        v[t] = x;
        for (int j = max(0, t-23); j <= min(t, n-24); ++j) {
            u[j] += y;
            ans = max(ans, u[j]);
        }
        printf("%d\n", ans);
    }
    return 0;
}