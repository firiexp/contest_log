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
    int n;
    cin >> n;
    auto v = prime_factor(n);
    vector<pair<int, int>> u;
    u.emplace_back(v[0], 1);
    for (int i = 1; i < v.size(); ++i) {
        if(u.back().first == v[i]) u.back().second++;
        else u.emplace_back(v[i], 1);
    }
    int ans = 0;
    for (auto &&i : u) ans ^= i.second;
    puts(ans ? "Alice" : "Bob");
    return 0;
}