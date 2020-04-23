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

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }


int main() {
    int a, b;
    cin >> a >> b;
    vector<int> s(a), t(b);
    for (auto &&i : s) scanf("%d", &i);
    for (auto &&i : t) scanf("%d", &i);
    int ans = 0;
    for (int i = 0; i < b; ++i) {
        int j = i;
        for (int k = 0; k < a; ++k) {
            if(j == b) break;
            if(s[k] == t[j]) j++;
        }
        ans = max(ans, j-i);
    }
    cout << ans << "\n";
    return 0;
}
