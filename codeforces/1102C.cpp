#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

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
    int n, x, y;
    cin >> n >> x >> y;
    if(x > y) {
        printf("%d\n", n);
        return 0;
    }
    int ans = 0;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        if(x < v[i]) break;
        v[i] = 0;
        ans++;
        for (int j = n-1; j >= 0; --j) {
            if(v[j] != 0 &&  x >= v[j]) {
                v[j] += y;
                break;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
