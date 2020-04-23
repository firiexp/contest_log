#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    ll n, k, m, r;
    cin >> n >> k >> m >> r;
    vector<ll> v(n-1);
    for (auto &&i : v) scanf("%li", &i);
    ll ng = -1, ok = m+1;
    while(ok-ng > 1){
        ll mid = (ok+ng)/2;
        vector<ll> u = v;
        u.emplace_back(mid);
        sort(u.begin(), u.end(), greater<>());
        ll s = 0;
        for (int i = 0; i < k; ++i) {
            s += u[i];
        }
        if(s >= k*r) ok = mid;
        else ng = mid;
    }
    cout << (ok == m+1 ? -1 : ok) << "\n";
    return 0;
}
