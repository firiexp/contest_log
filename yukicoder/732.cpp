#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

vector< bool > get_prime(int n){
    vector< bool > prime( n + 1, true);

    if(n >= 0) prime[0] = false;
    if(n >= 1) prime[1] = false;

    for(int i = 2; i * i <= n; i++){
        if(prime[i]){
            for(int j = i + i; j <= n; j += i) prime[j] = false;
        }
    }

    return(prime);
}
int main() {
    int n;
    cin >> n;
    vector<bool> is_prime = get_prime(3*n);
    vector<int> primes;
    for (int i = 3; i <= n; ++i) {
        if(is_prime[i]){
            primes.emplace_back(i);
        }
    }
    vector<vector<ll>> dp(4, vector<ll>(3*n+1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        
    }
    return 0;
}
