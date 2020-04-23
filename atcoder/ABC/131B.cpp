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
    int n, l;
    cin >> n >> l;
    vector<int> v(n);
    ll s = 0;
    for (int i = 0; i < n; ++i) {
        v[i] = l+i;
        s += v[i];
    }
    ll ans = 0, k = INF<ll>;
    for (int i = 0; i < n; ++i) {
        if(abs(v[i]) < k){
            k = abs(v[i]);
            ans = s-v[i];
        }
    }
    cout << ans << "\n";
    return 0;
}