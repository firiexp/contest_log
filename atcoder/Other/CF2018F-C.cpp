#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "[";
    for (auto vv : v)
        os << vv << ",";
    return os << "]";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "(" << p.first << "," << p.second << ")";
}

int main() {
    vector<pair<int, int>> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        v.emplace_back(a, b);
    }
    sort(v.begin(), v.end());
    vector<int> v2{0, v[0].first};
    for (int i = 0; i < n-1; ++i) {
        v2.emplace_back(v[i+1].second - v[i].second + v[i].first);
        v2.emplace_back(v[i+1].first);
    }
    v2.emplace_back(INF<int>*2);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int t;
        scanf("%d", &t);
        u32 x = static_cast<u32>(lower_bound(v2.begin(), v2.end(), t) - v2.begin());
        if(x%2 != 0){
            cout << v[x/2].second << "\n";
        }else {
            cout << v[(x-1) / 2].second +  t - v[(x-1) / 2].first << "\n";
        }
    }
    return 0;
}
