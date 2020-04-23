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

vector<int> get_prime(int n){
    if(n <= 1) return vector<int>();
    vector<bool> is_prime(n+1, true);
    vector<int> prime;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if(is_prime[i]) prime.emplace_back(i);
        for (auto &&j : prime){
            if(i*j > n) break;
            is_prime[i*j] = false;
            if(i % j == 0) break;
        }
    }
    return prime;
}
const auto primes = get_prime(32000);

template<class T>
vector<T> prime_factor(T n){
    vector<T> res;
    for (auto &&i : primes) {
        while (n % i == 0){
            res.emplace_back(i);
            n /= i;
        }
    }
    if(n != 1) res.emplace_back(n);
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
}

int main() {
    ll n, k;
    cin >> n >> k;
    auto f = [](ll n, ll k){
        auto v = prime_factor(k); ll m = v.size();
        ll ans = 0;
        for (int i = 0; i < (1<<m); ++i) {
            ll x = 1;
            for (int j = 0; j < m; ++j) {
                if(i & (1 << j)) x *= v[j];
            }
            if(__builtin_popcount(i)&1){
                (ans += (MOD-(n/x)*(n/x+1)/2%MOD*x%MOD)) %= MOD;
            }else {
                (ans += ((n/x)*(n/x+1)/2%MOD*x%MOD)) %= MOD;
            }
        }
        return ans;
    };
    ll ans = 0;
    for (auto &&i : divisor(k)) {
        (ans += f(n/i, k/i)) %= MOD;
    }
    cout << ans*k%MOD << "\n";
    return 0;
}