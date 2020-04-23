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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;


int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> A(n), B(m);
    for (auto &&i : A) scanf("%d", &i);
    for (auto &&j : B) scanf("%d", &j);
    vector<ll> val(m-n+1);
    ll T = 0;
    {
        ll S = 0;
        for (int i = 0; i < n; ++i) {
            if(i&1) S -= B[i], T -= A[i];
            else S += B[i], T += A[i];
        }
        val[0] = S;
    }
    for (int i = 0; i+n < m; ++i) {
        val[i+1] = -val[i];
        val[i+1] += B[i];
        if(n&1) val[i+1] += B[i+n];
        else val[i+1] -= B[i+n];
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    vector<int> S(n+1);
    for (int i = 0; i < n; ++i) {
        S[i+1] = (i&1 ? 0 : 1);
    }
    auto f = [&](){
        auto itr = lower_bound(val.begin(),val.end(), T);
        ll ans = INF<ll>;
        if(itr != val.end()) ans = min(ans, abs(*itr-T));
        if(itr != val.begin()) ans = min(ans, abs(*(itr-1)-T));
        printf("%lld\n", ans);
    };
    f();
    while(q--){
        int l, r; ll x;
        scanf("%d %d %lld", &l, &r, &x);
        l--;
        T += (S[r]-S[l])*x;
        f();
    }

    return 0;
}