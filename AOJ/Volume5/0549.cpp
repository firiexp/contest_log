#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 100000;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n, m;
    cin >> n >> m;
    int ans = 0, s = 0;
    vector<int> v(n);
    for (int i = 0; i < n-1; ++i) {
        int k;
        scanf("%d", &k);
        (s += k) %= MOD;
        v[i+1] = s;
    }
    int cur = 0;
    for (int i = 0; i < m; ++i) {
        int x;
        scanf("%d", &x);
        if(x > 0){
            (ans += v[cur+x]-v[cur]+MOD) %= MOD;
        }else {
            (ans += v[cur]-v[cur+x]+MOD) %= MOD;
        }
        cur += x;
    }
    cout << ans << "\n";
    return 0;
}
