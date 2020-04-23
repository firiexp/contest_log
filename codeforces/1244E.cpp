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
    ll n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    sort(v.begin(),v.end());
    vector<pair<int, int>> u;
    u.emplace_back(v[0], 1);
    for (int i = 1; i < n; ++i) {
        if(u.back().first == v[i]) u.back().second++;
        else u.emplace_back(v[i], 1);
    }
    int cur1 = 0, cur2 = (int)(u.size())-1;
    while(cur2 - cur1 > 0){
        if(u[cur1].second < u[cur2].second){
            ll x = min(k/u[cur1].second,
                       (ll)u[cur1+1].first-u[cur1].first);
            if(x == 0) break;
            k -= x*u[cur1].second;
            if(u[cur1].first+x == u[cur1+1].first){
                u[cur1+1].second += u[cur1].second;
                u[cur1].second = 0;
                cur1++;
            }else {
                u[cur1].first += x;
            }
        }else {
            ll x = min(k/u[cur2].second,
                       (ll)u[cur2].first-u[cur2-1].first);
            if(x == 0) break;
            k -= x*u[cur2].second;
            if(u[cur2-1].first+x == u[cur2].first){
                u[cur2-1].second += u[cur2].second;
                u[cur2].second = 0;
                cur2--;
            }
            else {
                u[cur2].first -= x;
            }
        }
    }
    cout << u[cur2].first-u[cur1].first << "\n";
    return 0;
}