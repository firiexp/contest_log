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
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

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
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1), b(n+1);
    a[1] = 0;
    vector<int> fac = get_min_factor(n);
    int m = 0, ans = 0;
    for (int i = 2; i <= n; ++i) {
        int j = i;
        while(j != 1){
            a[i]++;
            j /= fac[j];
        }
    }
    b[1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            b[j]++;
        }
    }
    for (int i = 2; i < n; ++i) {
        if(a[__gcd(i, n)] >= k && m < b[i]){
            m = b[i], ans = i;
        }
    }
    cout << ans << "\n";
    return 0;
}
