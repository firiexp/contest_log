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
using u32 = unsigned;
using u64 = unsigned long long;
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
    vector<string> v(n);
    for (auto &&i : v) cin >> i;
    ll ans = 0;
    using P = array<int, 3>;
    queue<P> Q;
    Q.emplace(P{0, n, 0});
    vector<pair<char, int>> a;
    while(!Q.empty()){
        P x = Q.front(); Q.pop();
        a.clear();
        a.emplace_back(0, 0);
        for (int i = x[0]; i < x[1]; ++i) {
            char nxt = 0;
            if(x[2] < v[i].size()) nxt = v[i][x[2]];
            if(a.back().first != nxt) a.emplace_back(nxt, 1);
            else a.back().second++;
        }
        int cur = x[0];
        for (int i = 0; i < a.size(); ++i) {
            if(a[i].first){
                ans += (ll)(a[i].second)*(a[i].second+1)*(a[i].second+2)/6;
                Q.emplace(P{cur, cur+a[i].second, x[2]+1});
            }
            cur += a[i].second;
        }
    }
    cout << ans << "\n";
    return 0;
}