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
using u32 = uint32_t;
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

int main() {
    int n;
    cin >> n;
    vector<ll> x = {3, 5, 17, 257, 65537};
    vector<ll> y;
    for (int i = 0; i < (1 << 5); ++i) {
        ll ans = 1;
        for (int j = 0; j < 5; ++j) {
            if(i & (1 << j)) ans *= x[j];
        }
        y.emplace_back(ans);
    }
    vector<ll> ans;
    for (auto &&i : y) {
        while(i <= n){
            if(i >= 3) ans.emplace_back(i);
            i *= 2;
        }
    }
    cout << ans.size() << "\n";
    return 0;
}
