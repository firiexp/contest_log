#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n);

    for (auto &&i : v) scanf("%d", &i);
    int ans = 0;
    auto u = v;
    for (int i = 0; i < n; ++i) {
        if(v[i] == 0 && v[n-i-1] == 1) {
            puts("-1");
            return 0;
        }else if(v[i] == 2 && v[n-i-1] == 2){
            v[i] = v[n-i-1] = (a < b ? 0 : 1);
        }else {
            if(v[i] == 2){
                v[i] = v[n-i-1];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if(u[i] == 2){
            if(v[i]) ans += b;
            else ans += a;
        }
    }
    cout << ans << "\n";
    return 0;
}