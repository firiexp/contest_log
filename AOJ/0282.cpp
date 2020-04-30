#include <iostream>
#include <algorithm>
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
    int n, r, l;
    cin >> n >> r >> l;
    vector<int> v(n);
    set<pair<int, int>> s;
    for (int i = 0; i < n; ++i) {
        s.emplace(0, i);
    }
    int prv = 0;
    vector<int> ans(n);
    for (int i = 0; i < r; ++i) {
        int d, t, x;
        scanf("%d %d %d", &d, &t, &x); d--;
        auto M = s.begin();
        ans[M->second] += (t-prv);
        s.erase(s.find({v[d], d}));
        v[d] -= x;
        s.emplace(v[d], d);
        prv = t;
    }
    auto M = s.begin();
    ans[M->second] += (l-prv);
    cout << max_element(ans.begin(),ans.end()) - ans.begin() + 1 << "\n";
    return 0;
}