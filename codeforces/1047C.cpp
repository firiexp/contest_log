#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <set>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

vector<int> get_min_factor(int n) {
    if(n <= 1) return vector<int>{0, 1};
    vector<bool> prime(static_cast<unsigned int>(n + 1), true);
    vector<int> min_factor(static_cast<u32>(n+1), 0);
    min_factor[0] = 0, min_factor[1] = 1;
    prime[0] = false; prime[1] = false;
    for(ll i = 2; i <= n; i++){
        if(prime[i]) {
            min_factor[i] = (int)i;
            for(ll j = i << 1; j <= n; j += i) {
                prime[j] = false;
                if(min_factor[j] == 0) min_factor[j] = (int)i;
            }
        }
    }
    return(min_factor);
}

int main() {
    int n;
    cin >> n;
    int a;
    cin >> a;
    int p = a;
    bool flag = true;
    vector<int> v;
    v.emplace_back(a);
    for (int i = 0; i < n-1; ++i) {
        int k;
        scanf("%d", &k);
        if(k != a) flag = false;
        p = __gcd(k, p);
        v.emplace_back(k);
    }
    if(flag){
        cout << -1 << "\n";
        return 0;
    }
    vector<int> v2(15000001, 0);
    auto min_factors = get_min_factor(15000000);
    for (auto &&x : v) x /= p;
    for (auto &&x : v) {
        set<int> u = {};
        while (x > 1){
            u.insert(min_factors[x]);
            x /= min_factors[x];
        }
        for (auto &&y : u) {
            v2[y]++;
        }
    }
    int ans = INF<int>;
    for (int i = 2; i < 15000000; ++i) {
        if(min_factors[i] == i){
            ans = min(ans, n-v2[i]);
        }
    }
    cout << ans << "\n";
    return 0;
}
