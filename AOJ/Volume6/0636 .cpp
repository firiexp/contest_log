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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, q, a, b;
    cin >> n >> q >> a >> b;
    a = -a; b = -b;

    vector<ll> v(n+2), S(n+1);
    ll T = 0;
    auto f = [&](ll y){return y > 0 ? y*a : y*b; };
    for (int i = 0; i < n+1; ++i) {
        scanf("%li", &S[i]);
        if(i) {
            v[i] = S[i] - S[i-1];
            T += f(v[i]);
        }
    }
    for (int i = 0; i < q; ++i) {
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        r++;
        ll dT = f(v[l]+x) -  f(v[l]);
        v[l] += x;
        if(r <= n) {
            dT += f(v[r]-x)-f(v[r]);
            v[r] -= x;
        }
        T += dT;
        cout << T << "\n";
    }
    return 0;
}
