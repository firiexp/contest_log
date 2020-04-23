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
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    int n;
    string s;
    cin >> n >> s;
    using P = pair<int, int>;
    vector<P> v(static_cast<u32>(n), P{0, 0});
    for (int i = 0; i < n-1; ++i) {
        if(s[i] == 'W') v[i+1].second++;
    }
    int a = 0;
    for (int i = 0; i < n; ++i) {
        a += v[i].second;
        v[i].second = a;
    }
    for (int i = n-1; i > 0; --i) {
        if(s[i] == 'E') v[i-1].first++;
    }
    a = 0;
    for (int i = n-1; i >= 0; --i) {
        a += v[i].first;
        v[i].first = a;
    }
    int ans = INF<int>;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, v[i].first+v[i].second);
    }
    cout << ans << "\n";
    return 0;
}
