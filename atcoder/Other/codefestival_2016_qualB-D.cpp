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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int m = 0;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if(m+1 < v[i]){
            ans += (v[i]-1)/(m+1);
            v[i] = max(1, m);
        }
        m = max(m, v[i]);
    }
    cout << ans << "\n";
    return 0;
}