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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;


using u32 = uint32_t;

template<typename T>
struct ExactDiv {
    T t, i, val;
    ExactDiv() {}
    ExactDiv(T n) : t(T(-1) / n), i(mul_inv(n)) , val(n) {};
    T mul_inv(T n) {
        T x = n;
        for (int i = 0; i < 5; ++i) x *= 2 - n * x;
        return x;
    }
    bool divide(T n) const {
        if(val == 2) return !(n & 1);
        return n * this->i <= this->t;
    }
};

vector<ExactDiv<u32>> get_prime(int n){
    if(n <= 1) return vector<ExactDiv<u32>>();
    vector<bool> is_prime(n+1, true);
    vector<ExactDiv<u32>> prime;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if(is_prime[i]) prime.emplace_back(i);
        for (auto &&j : prime){
            if(i*j.val > n) break;
            is_prime[i*j.val] = false;
            if(j.divide(i)) break;
        }
    }
    return prime;
}
const auto primes = get_prime(32000);

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

int main() {
    int n, k;
    cin >> n >> k;
    vector<u32> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> cnt(n);
    ll ans = 1;
    for (auto &&j : primes) {
        fill(cnt.begin(),cnt.end(), 0);
        for (int i = 0; i < n; ++i) {
            while(j.divide(v[i])){
                v[i] /= j.val;
                cnt[i]++;
            }
        }
        nth_element(cnt.begin(),cnt.begin()+k, cnt.end(), greater<>());
        int val = 0;
        for (int i = 0; i < k; ++i) {
            val += cnt[i];
        }
        (ans *= pow_<u32>(j.val, val, MOD)) %= MOD;
    }
    sort(v.begin(),v.end());
    vector<pair<int, int>> len;
    len.emplace_back(1, v[0]);
    for (int i = 1; i < n; ++i) {
        if(len.back().second == v[i]){
            len.back().first++;
        }else len.emplace_back(1, v[i]);
    }
    for (auto &&l : len) {
        (ans *= pow_(l.second, min(k, l.first), MOD)) %= MOD;
    }
    cout << ans << "\n";
    return 0;
}