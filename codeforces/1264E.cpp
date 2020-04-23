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
    ll n;
    cin >> n;
    vector<int> xs(n), ys(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &xs[i], &ys[i]);
    }
    ll ans = (n-1)*(n-2)*(n-3)*(n-4)/4/3/2*n; // n*(n-2)*(n-3)*(n-4)/4/3/2*n;
    long double pi = acos(-1.0L);
    for (int i = 0; i < n; ++i) {
        vector<long double> v;
        for (int j = 0; j < n; ++j) {
            if(i != j){
                v.emplace_back(atan2<long double>(xs[j]-xs[i], ys[j]-ys[i]));
                v.emplace_back(atan2<long double>(xs[j]-xs[i], ys[j]-ys[i])+2*pi);
            }
        }
        sort(v.begin(),v.end());
        ll l = 0, r = n-1;
        while(r < 2*(n-1)){
            while(v[r]-v[l] > pi){
                l++;
            }
            r++;
            ans -= (r-l-1)*(r-l-2)*(r-l-3)/6;
        }
    }
    cout << ans << "\n";
    return 0;
}