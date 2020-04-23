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

template<typename T>
T mod_inv(T x, T M){
    T u = 1, t = 1, v = 0, s = 0, m = M;
    while (x) { T q = m/x; swap(s -= q*u, u); swap(t -= q*v, v); swap(m -= q*x, x); }
    if(s < 0) s += M;
    return s;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    deque<int> Q;
    stack<int> s;
    int cnt = 0;
    vector<int> visited(n, 0), num(n);
    s.emplace(0);
    vector<int> nump(n);
    while(!s.empty()){
        int a = s.top(); s.pop();
        visited[a]++;
        num[a] = cnt++;
        Q.emplace_front(a);
        for (auto &&i : G[a]) {
            if(!visited[i]) {
                nump[i] += nump[a]+1;
                s.emplace(i);
            }
        }
    }

    ll ans = 0;
    Factorial<ll> f(n, MOD);
    for (int i = 0; i < n; ++i) {
        (ans += f[n]*mod_inv(nump[i]+1,MOD)) %= MOD;
    }

    cout << ans << "\n";
    return 0;
}