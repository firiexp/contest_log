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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "(" << p.first << "," << p.second << ")";
}

template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "{";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ",";
        os << v[i];
    }
    return os << "}";
}

int LIS(const vector<int> &v){
    vector<int> u(v.size(), INF<int>);
    for (int i : v) {
        *lower_bound(u.begin(), u.end(), i) = i;
    }
    return static_cast<int>(distance(u.begin(), lower_bound(u.begin(), u.end(), INF<int>)));
}

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    if(a+b-1 > n || a*b < n){
        puts("-1");
        return 0;
    }
    vector<ll> v(b,1);
    vector<vector<int>> ans(b);
    v[b-1] = a;
    ll k = n-a-b+1;
    ll cur = b-2;
    for (int i = 0; i < k; ++i) {
        if(v[cur] >= a) cur--;
        v[cur]++;
    }
    cur = 1;
    for (ll i = b - 1; i >= 0; --i) {
        for (int j = 0; j < v[i]; ++j) {
            ans[i].emplace_back(cur++);
        }
    }
    for (int i = 0; i < b; ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            if(i | j) printf(" ");
            printf("%d", ans[i][j]);
        }
    }
    return 0;
}
