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

vector<int> get_prime(int n) {
    if(n <= 1) return vector<int>{};
    vector<bool> is_composite(n+1);
    vector<int> prime;
    for (int i = 2; i <= n; ++i) {
        if(!is_composite[i]) prime.push_back(i);
        for (auto &&j : prime) {
            if((ll)i*j > n) continue;
            is_composite[i*j] = true;
            if(i % j == 0) break;
        }
    }
    return prime;
}
const auto primes = get_prime(65535);

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
    int n, k, m;
    cin >> n >> k >> m;
    auto p = prime_factor(n);
    map<int, ll> v;
    for (auto &&i : p) {
        v[i]++;
    }
    for (auto &&j : v) {
        j.second *= k;
    }
    vector<pair<int, ll>> u(v.begin(),v.end());

    vector<ll> ans{1};
    for (int i = 0; i < u.size(); ++i) {
        ll val = 1;
        vector<ll> ans2, tmp;
        for (int j = 0; j <= u[i].second; ++j) {
            if(val > m) break;
            tmp.emplace_back(val);
            val *= u[i].first;
        }
        for (auto &&j : ans) {
            for (auto &&l : tmp) {
                if(j <= m && l <= m && j*l <= m) ans2.emplace_back(j*l);
            }
        }
        ans.swap(ans2);
    }
    cout << ans.size() << "\n";
    return 0;
}