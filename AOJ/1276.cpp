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
    vector<bool> is_prime(n+1, true);
    vector<int> prime;
    for (int i = 2; i <= n; ++i) {
        if(!is_prime[i]) continue;
        prime.emplace_back(i);
        for (int j = i*2; j <= n; j += i) {
            is_prime[j] = false;
        }
    }
    return prime;
}

int main() {
    const auto primes = get_prime(1300000);
    set<int> s;
    for (auto &&i : primes) s.insert(i);
    int n;
    while(cin >> n, n){
        if(s.count(n)){
            puts("0");
            continue;
        }
        auto ub = s.lower_bound(n);
        auto lb = ub;
        lb--;
        printf("%d\n", (*ub)-(*lb));
    }
    return 0;
}