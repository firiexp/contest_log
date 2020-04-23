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
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lld", &i);
    sort(v.begin(),v.end());
    if(v.front() == v.back()){
        puts("1");
        return 0;
    }
    vector<ll> dp(n, 0);
    ll s = 0, t = 0;
    for (int i = 0; i < n-1; ++i) {
        s += v[i];
        int j = i/2;
        if((i%2) == 0) t += v[j];
        dp[i+1] = (v[j]*(j+1)-t)+((s-t)-v[j]*(i-j));
    }
    s = 0, t = 0;
    for (int i = n-1; i >= 0; --i) {
        s += v[i];
        int j = i+(n-i)/2;
        if((n-i)%2) t += v[j];
        dp[i] += (v[j]*(j-i)-(s-t))+(t-v[j]*(n-j));
    }
    cout << *min_element(dp.begin(),dp.end()) << "\n";
    return 0;
}