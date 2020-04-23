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
using u32 = unsigned;
using u64 = unsigned long long;
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

template<class T>
vector<T> prime_factor(T n){
    vector<T> res;
    for (auto &&i : primes) {
        while (i.divide(n)){
            res.emplace_back(i.val);
            n /= i.val;
        }
    }
    if(n != 1) res.emplace_back(n);
    return res;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        scanf("%d", &n);
        auto v = prime_factor(n);
        int ans1 = 1, ans2 = 1, ans3 = 1, cur = 0;
        for (int i = 0; i < v.size(); ++i) {
            if(cur == 0){
                ans1 *= v[i];
                cur++;
            }else if(cur == 1){
                ans2 *= v[i];
                if(ans1 != ans2) cur++;
            }else {
                ans3 *= v[i];
            }
        }
        if(min({ans1, ans2, ans3}) == 1 || ans1 == ans2 || ans2 == ans3 || ans3 == ans1){
            puts("NO");
        }else {
            puts("YES");
            printf("%d %d %d\n", ans1, ans2, ans3);
        }
    }
    return 0;
}