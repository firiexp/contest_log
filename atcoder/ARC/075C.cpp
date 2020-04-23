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
template<class T>
class BIT {
    vector<T> bit;


public:
    BIT(int n): bit(vector<T>(n+1, 0)){}

    T sum(int k){
        T ret = 0;
        for (++k; k > 0; k -= (k & -k)) ret += bit[k];
        return ret;
    }

    void add(int k, T x){
        for (++k; k < bit.size(); k  += (k & -k)) bit[k] += x;
    }
};


int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> v(n), v2(n);
    vector<int> used(n, 0);
    ll sum = 0;
    ll ans = (ll)n*(n+1)/2;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        sum += x-k;
        v2[i] = v[i] = sum;
        ans -= (v[i] < 0);
    }
    BIT<int> dp(n);
    sort(v2.begin(), v2.end());
    for (int i = 0; i < n; ++i) {
        int x = static_cast<int>(lower_bound(v2.begin(), v2.end(), v[i]) - v2.begin());
        dp.add(x+used[x], 1);
        ans += dp.sum(x+used[x])-i-1;
        used[x]++;
    }
    cout << ans << "\n";
    return 0;
}
