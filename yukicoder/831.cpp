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
    for (int i = 0; i < n; ++i) {
        v[i] = (i+1);
    }

    deque<int> q;
    q.emplace_back(v[0]);
    int cur1 = 1, cur2 = n-1;
    while(cur1 <= cur2){
        q.emplace_front(v[cur2--]);
        if(cur1 > cur2) continue;
        q.emplace_back(v[cur2--]);
        if(cur1 > cur2) continue;
        q.emplace_front(v[cur1++]);
        if(cur1 > cur2) continue;
        q.emplace_back(v[cur1++]);
        if(cur1 > cur2) continue;
    }
    for (int i = 0; i < n; ++i) {
        v[i] = q.front(); q.pop_front();
    }
    ll ans = 0;
    if(n != 1 ) for (int i = 0; i < n; ++i) {
        ans += (ll)v[i]*v[(i+1)%n];
    }
    cout << ans << "\n";
    return 0;
}