#include <iostream>
#include <algorithm>
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

int main() {
    int M = 1000000;
    vector<bool> is_prime(M+1, true);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= M; ++i) {
        if(!is_prime[i]) continue;
        for (int j = i*2; j <= M; j += i) {
            is_prime[j] = false;
        }
    }
    int n, x;
    while(cin >> n >> x, n){
        vector<char> dp(x+1);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            int a; cin >> a;
            for (int j = 0; j+a <= x; ++j) {
                dp[j+a] |= dp[j];
            }
        }
        int ok = 0;
        for (int i = x; i >= 2; --i) {
            if(is_prime[i] && dp[i]){
                cout << i << "\n";
                ok = 1;
                break;
            }
        }
        if(!ok) puts("NA");

    }
    return 0;
}