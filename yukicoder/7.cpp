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
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;


vector<int> get_prime(int n) {
    if(n <= 1) return vector<int>{};
    vector<bool> prime(static_cast<unsigned int>(n + 1), true);
    vector<int> res;
    prime[0] = false; prime[1] = false;
    for(int i = 2; i * i <= n; i++){
        if(prime[i]) for(int j = i << 1; j <= n; j += i) prime[j] = false;
    }
    for (int i = 2; i <= n; ++i) {
        if(prime[i]) res.emplace_back(i);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> v = get_prime(n);
    vector<int> dp(n+1, 0);
    dp[0] = 1; dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (auto &&j : v) {
            if(i - j < 0) break;
            if(dp[i-j] == 0) {
                dp[i] = 1;
                break;
            }
        }
    }
    puts(dp[n] ? "Win" : "Lose");
    return 0;
}
