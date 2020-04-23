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

template <class T>
T pow_ (T x, T n){
    uint64_t u = 1, xx = x;
    while (n > 0){
        if (n&1) u = u * xx;
        xx = xx * xx;
        n >>= 1;

    }
    return static_cast<T>(u);
};


int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> cnt(100001);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    int M = 100000;
    vector<int> mindivisor(M+1);
    for (int i = 2; i <= M; ++i) {
        if(!mindivisor[i]) {
            mindivisor[i] = i;
            for (int j = i*2; j <= M; j += i) {
                if(!mindivisor[j]) mindivisor[j] = i;
            }
        }
    }
    vector<ll> kproduct(M+1);
    for (ll i = 1; i <= M; ++i) {
        kproduct[i] = 1;
        for (int j = 0; j < k; ++j) {
            kproduct[i] *= i;
            if(kproduct[i] >= 1000000000) break;
        }
    }
    ll ans = 0;
    map<int, int> m;
    int aa = 0;
    for (int i = 1; i <= M; ++i) {
        int cur = i;
        while(mindivisor[cur]){
            m[mindivisor[cur]]++;
            cur /= mindivisor[cur];
        }
        ll a = 1;
        int ok = 1;
        for (auto &&j : m) {
            for (int l = 0; (j.second+l)%k != 0; ++l) {
                a *= j.first;
                if(a > M) {
                    ok = 0;
                    break;
                }
            }
            if(!ok) break;
        }
        if(!ok) continue;

        for (ll j = 1; a*kproduct[j] <= i; ++j) {
            cout << i << " " << a*kproduct[j] << "\n";
            aa++;
        }
        m.clear();
    }
    cout << aa << "\n";
    return 0;
}