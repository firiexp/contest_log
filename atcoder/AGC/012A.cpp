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
    cin >> n;
    vector<int> v;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        v.emplace_back(a);
        v.emplace_back(b);
        v.emplace_back(c);
    }
    sort(v.begin(), v.end(), greater<>());
    for (int i = 0; i < n; ++i) {
        ans += v[i*2+1];
    }
    cout << ans << "\n";
    return 0;
}
