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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if(v[i-1] != i) continue;
        int k = 1;
        for (int j = i+1; j <= n; ++j) {
            if(v[j-1] != i) break;
            k++;
        }
        i += k;
        ans += (k+1)/2;
    }
    cout << ans << "\n";
    return 0;
}
