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
    int n, k;
    cin >> n >> k;
    auto v = prime_factor(n);
    if(v.size() < k){
        puts("-1");
        return 0;
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < k-1; ++i) {
        if(i) cout << " ";
        cout << v[i];
    }
    int a = 1;
    for (int i = k-1; i < v.size(); ++i) {
        a *= v[i];
    }
    cout << " " << a << "\n";
    return 0;
}