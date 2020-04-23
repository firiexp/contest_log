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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<ll> DD(n+1, 0), MM(n+1, 0);
    for (int i = 0; i < n; ++i) {
        DD[i+1] = DD[i] + (s[i] == 'D');
        MM[i+1] = MM[i] + (s[i] == 'M');
    }
    cout << DD << "\n";
    for (int i = 0; i < q; ++i) {
        ll ans = 0;
        int k;
        cin >> k;
        vector<ll> D(n+1, 0), M(n+1, 0);
        for (int j = 0; j < n; ++j) {
            D[j+1] = DD[j+1]-(j >= k ? DD[j-k] : 0);
            M[j+1] = M[j]+(s[j] == 'M' ? D[j] : 0);
            if(s[j] == 'C') ans += D[j]*(M[j]-(j >= k ? M[j-k+1] : 0));
        }
        cout << D << "\n" << M << "\n";
        cout << ans << "\n";
    }
    return 0;
}
