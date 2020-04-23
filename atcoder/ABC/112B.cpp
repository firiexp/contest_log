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
    int n, t;
    cin >> n >> t;
    int ans = INF<int>;
    for (int i = 0; i < n; ++i) {
        int c, x;
        cin >> c >> x;
        if(x <= t){
            ans = min(ans, c);
        }
    }
    if(ans == INF<int>){
        cout << "TLE\n";
    }else {
        cout << ans << "\n";
    }
    return 0;
}
