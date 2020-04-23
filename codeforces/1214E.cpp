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
ostream& operator<<(ostream& os, deque<T> v) {
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
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i].first);
        v[i].second = i;
    }
    sort(v.begin(),v.end());
    deque<int> q;
    vector<vector<int>> ans(n*n);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < v[i].first; ++j) {
            q.emplace_back(j*2+i);
        }
    }
    for (int i = 0; i < q.size()-1; ++i) {
        ans[q[i]].emplace_back(q[i+1]);
    }
    cout << q << "\n";
    return 0;
}