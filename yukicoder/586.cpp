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

int main() {
    int p, p2;
    cin >> p >> p2;
    int n, ans = 0;
    cin >> n;
    map<int, int> v;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        if(v[k]) ans += p+p2;
        v[k]++;
    }
    cout << ans << "\n";
    return 0;
}
