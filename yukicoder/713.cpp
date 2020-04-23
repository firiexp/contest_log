#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

vector<bool> get_prime(int n) {
    if(n <= 1) return vector<bool>{false, false};
    vector<bool> prime(static_cast<unsigned int>(n + 1), true);
    prime[0] = false; prime[1] = false;
    for(int i = 2; i * i <= n; i++){
        if(prime[i]) for(int j = i << 1; j <= n; j += i) prime[j] = false;
    }
    return(prime);
}
int main() {
    int n;
    cin >> n;
    int ans = 0;
    auto v = get_prime(n);
    for (int i = 0; i <= n; ++i) {
        if(v[i]) ans += i;
    }
    cout << ans << "\n";
    return 0;
}
