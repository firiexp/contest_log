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
    int n, h;
    cin >> n >> h;
    vector<int> v(n), u(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        u[i] = i;
    }
    int ans = 0;
    do {
        bool success = true;
        vector<int> s(n, 1);
        for (int i = 0; i < n; ++i) {
            int q = 0;
            for (int j = 0; j <= u[i]; ++j) {
                if(s[j]) q += v[j];
            }
            s[u[i]] = 0;
            if(q > h) success = false;
        }
        if(success) ans++;
    } while (next_permutation(u.begin(), u.end()));
    cout << ans << "\n";
    return 0;
}
