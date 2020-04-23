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
    auto v = get_prime(10000);
    vector<int> ans;
    for (int i = 0; i+1 < v.size(); ++i) {
        if(v[i+1] - v[i] == 2){
            ans.emplace_back(v[i]+2);
        }
    }
    int n;
    while(cin >> n, n){
        auto x = *--upper_bound(ans.begin(),ans.end(), n);
        printf("%d %d\n", x-2, x);
    }
    return 0;
}