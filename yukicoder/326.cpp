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
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i;
    }
    for (int i = 0; i < k; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        swap(v[a-1], v[b-1]);
    }
    vector<int> u(n);
    for (auto &&j : u) scanf("%d", &j), j--;
    vector<int> vu(n);
    for (int i = 0; i < n; ++i) {
        vu[i] = u[v[i]];
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-1-i; ++j) {
            if(vu[j] > vu[j+1]) {
                swap(vu[j], vu[j+1]);
                ans.emplace_back(j+1, j+2);
            }
        }
    }
    cout << ans.size() << "\n";
    for (auto &&i : ans) {
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}