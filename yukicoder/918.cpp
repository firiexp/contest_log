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
    vector<ll> a, b;
    auto u = v;
    ll ans = 0;
    for (int K = n; K >= 1; --K) {
        a.resize(n/K); b.resize(n/K+1);
        for (int i = 0; i < n/K; ++i) {
            nth_element(u.begin()+i*K, u.begin()+i*K+(K-1)/2, u.begin()+(i+1)*K);
            a[i] = u[i*K+(K-1)/2];
        }
        u = v;
        for (int i = 0; i < n/K; ++i) {
            nth_element(u.rbegin()+i*K, u.rbegin()+i*K+(K-1)/2, u.rbegin()+(i+1)*K);
            b[i+1] = b[i]+u[n-(i*K+(K-1)/2)-1];
        }
        u = v;
        for (int i = 0; i < n/K; ++i) {
            b[i+1] = max(b[i+1], b[i]);
        }
        ll p = 0; int cur = 0; ll s = 0;
        for (int i = 0; i < n/K; ++i) {
            while(i*K-1 >= n-K*(n/K+1-cur)) cur++;
            p = max(p, s+b[n/K+1-cur]);
            s += a[i];
        }
        ans = max({ans, p*K, s*K});
    }
    cout << ans << "\n";
    return 0;
}