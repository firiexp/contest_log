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
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;



vector<int> get_prime(int n) {
    if(n <= 1) return vector<int>{};
    vector<bool> is_composite(n);
    vector<int> prime;
    for (int i = 2; i <= n; ++i) {
        if(!is_composite[i]) prime.push_back(i);
        for (auto &&j : prime) {
            if(i*j > n) continue;
            is_composite[i*j] = true;
            if(i % j == 0) break;
        }
    }
    return prime;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n+1);
    for (int i = 0; i <= n; ++i) {
        scanf("%d", &v[i]);
    }
    auto primes = get_prime(32000);
    vector<int> can;
    int M = abs(v.front());
    for (auto &&prime : primes) {
        if(prime <= n || M % prime == 0){
            can.emplace_back(prime);
            while(M % prime == 0) M /= prime;
        }
    }
    if(M != 1) can.emplace_back(M);
    vector<int> ans;
    for (auto &&p : can) {
        auto u = v;
        int valid = 1;
        for (int i = 0; i <= n; ++i) {
            if(i+p-1 < n) u[i+p-1] += u[i];
            else if((u[i]%p+p)%p != 0) valid = 0;
        }
        if(valid) ans.emplace_back(p);
    }
    for (auto &&p : ans) {
        printf("%d\n", p);
    }
    return 0;
}
