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

vector<int> get_prime(int n){
    if(n <= 1) return vector<int>();
    vector<bool> is_prime(n+1, true);
    vector<int> prime;
    is_prime[0] = is_prime[1] = 0;
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
const auto primes = get_prime(1000000);

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
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> u;
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
        cnt += v[i];
    }
    auto x = prime_factor(cnt);
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    ll ret = INF<ll>;
    vector<ll> vv(n), vvv(n);
    for (auto &&p : x) {
        copy(v.begin(),v.end(), vv.begin());
        ll cur = 0, ans = 0;
        while(cur < n) {
            ll curr = cur, currr = -1, sum = 0;
            if(vv[curr] > p){
                vv[curr] %= p;
            }
            while(sum < p){
                ll k = min<ll>(p-sum, vv[curr]);
                sum += k;
                vv[curr] -= k;
                vvv[curr] = k;
                if(currr == -1 && sum >= (p+1)/2){
                    currr = curr;
                }
                curr++;
            }
            for (int i = cur; i < curr; ++i) {
                ans += vvv[i]*abs(i-currr);
            }
            cur = curr;
            if(cur < n && cur > 0 && vv[cur-1]) cur--;
        }
        ret = min(ret, ans);
    }
    if(ret == INF<ll>) puts("-1");
    else cout << ret << "\n";
    return 0;
}