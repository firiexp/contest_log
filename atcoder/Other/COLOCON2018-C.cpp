#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ",";
        os << v[i];
    }
    return os << "]";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "(" << p.first << "," << p.second << ")";
}

int main() {
    ll a, b, ans = 0;
    cin >> a >> b;
    queue<vector<ll>> v;
    v.push(vector<ll>{});
    for (ll i = a; i <= b; ++i) {

        int k = static_cast<int>(v.size());
        cout << i << " " << k <<  "\n";
        for (int j = 0; j < k; ++j) {
            auto vv = v.front(); v.pop();
            bool kuwae = true;
            for (auto &&l : vv) {
                if(__gcd(l, i) > 1) kuwae = false;
            }
            v.push(vv);
            if(kuwae) {
                vv.emplace_back(i);
                v.push(vv);
            }
        }
    }
    cout << v.size() << "\n";
    return 0;
}
