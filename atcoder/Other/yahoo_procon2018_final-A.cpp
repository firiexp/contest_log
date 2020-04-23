#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;




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
const auto p = get_prime(320);
template<class T>
vector<T> prime_factor(T n, int d = 0){
    vector<T> a, res;
    for (auto &&i : p) {
        while (n % i == 0){
            res.emplace_back(i);
            n /= i;
        }
    }
    if(n != 1) res.emplace_back(n);
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
}

vector<ll> divisor(ll n){
    vector<ll> ret;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return(ret);
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(100001);
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        auto x = divisor(a);
        for (auto &&j : x) {
            v[j]++;
        }
    }
    for (int i = 1; i <= m; ++i) {
        auto x = prime_factor(i);
        int ans = 0;
        for (int j = 1; j < (1<<(x.size())); ++j) {
            int y = __builtin_popcount(j), mul = 1;
            for (int k = 0; k < x.size(); ++k) {
                if(j & (1<<k)) mul *= x[k];
            }
            if(y&1) ans += v[mul];
            else ans -= v[mul];
        }
        cout << n-ans << "\n";
    }
    return 0;
}
