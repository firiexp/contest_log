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
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &&i : v) cin >> i;
    sort(v.begin(), v.end());
    int p = 0;
    while(m){
        if(m >= v[p]){
            m -= v[p];
            p++;
            ans++;
        }else m = 0;
    }
    cout << ans << "\n";
    return 0;
}
