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
    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> v(n+1, -1);
    for (int i = 1; i <= n; ++i) scanf("%d", &v[i]);
    int s = 0;
    for (int i = 1; i <= n; ++i) {
        if(v[i-1] < v[i]) s++;
        else {
            ans += max(s-k+1, 0);
            s = 1;
        }
    }
    ans += max(s-k+1, 0);
    cout << ans << "\n";
    return 0;
}
