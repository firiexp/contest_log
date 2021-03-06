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
T pow_ (T x, T n, T M){
    uint64_t u = 1, xx = x;
    while (n > 0){
        if (n&1) u = u * xx % M;
        xx = xx * xx % M;
        n >>= 1;
    }
    return static_cast<T>(u);
};

template <class T> class Factorial {
    T mod;
    vector<uint64_t> facts, factinv;

public:
    Factorial(int n, T mod) : facts(static_cast<u32>(n+1)), factinv(static_cast<u32>(n+1)), mod(mod) {
        facts[0] = 1;
        for (int i = 1; i < n+1; ++i) facts[i] = facts[i-1]*i % mod;
        factinv[n] = pow_(facts[n], static_cast<uint64_t>(mod - 2), static_cast<uint64_t>(mod));
        for (int i = n-1; i >= 0; --i) factinv[i] = factinv[i+1] * (i+1) % mod;
    }

    T fact(int k) const {
        if(k >= 0) return static_cast<T>(facts[k]);
        else return static_cast<T>(factinv[-k]);
    }

    T operator[](const int &k) const {
        if(k >= 0) return static_cast<T>(facts[k]);
        else return static_cast<T>(factinv[-k]);
    }

    T C(int p, int q) const {
        if(q < 0 || p < q) return 0;
        return static_cast<T>(facts[p]*  factinv[q] % mod * factinv[p-q] % mod);
    }

    T P(int p, int q) const {
        if(q < 0 || p < q) return 0;
        return static_cast<T>((facts[p] * factinv[p-q]) % mod);
    }

    T H(int p, int q) const {
        if(p < 0 || q < 0) return 0;
        return static_cast<T>(q == 0 ? 1 : C(p+q-1, q));
    }
};

int main() {
    string s; int a;
    cin >> s >> a;
    ll w = a, f = s.size()-a;
    for (auto &&i : s) {
        if(i == 'W') w--;
        else if(i == 'F') f--;
    }
    Factorial<ll> fact(s.size(), MOD);
    ll ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        ll k = 0;
        array<int, 3> cnt{};
        for (int j = i; j <= i+1; ++j) {
            if(s[j%s.size()] == 'W') cnt[0]++;
            else if(s[j%s.size()] == 'F') cnt[1]++;
            else cnt[2]++;
        }
        if(cnt[2] == 2){
            k = fact.C(w+f-2, w-1)*2;
        }else if(cnt[0] && cnt[2]){
            k = fact.C(w+f-1, w);
        }else if(cnt[1] && cnt[2]){
            k = fact.C(w+f-1, w-1);
        }else if(cnt[0] && cnt[1]){
            k = fact.C(w+f, w);
        }
        (ans += k) %= MOD;
    }
    cout << ans << "\n";
    return 0;
}