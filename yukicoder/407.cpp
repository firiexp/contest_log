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
    ll n, l;
    cin >> n >> l;
    auto v = get_prime(l);
    ll ans = 0;
    for (auto &&p : v) {
        if(l+1 <= p*(n-1)) break;
        ans += l-p*(n-1)+1;
    }
    cout << ans << "\n";
    return 0;
}
