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

template<class T>
vector<T> divisor(T n){
    vector<T> ret;
    for(T i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return(ret);
}
int main() {
    ll n; cin >> n;
    auto v = divisor(n);
    ll ans1 = n-1, ans2 = n-1;
    ll d = v.size();
    for (int i = 0; i < d; ++i) {
        for (int j = i; j < d && v[i]*v[j] <= n; ++j) {
            for (int k = j; k < d && v[i]*v[j]*v[k] <= n; ++k) {
                if(v[i]*v[j]*v[k] == n) ans2 = min(ans2, v[i]+v[j]+v[k]-3);
            }
        }
    }
    cout << ans2 << " " << ans1 << "\n";
    return 0;
}