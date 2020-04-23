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

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lld", &i);
    sort(v.begin(),v.end(), greater<>());
    ll ok = 0, ng = 2*INF<int>;
    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        ll S = 0;
        for (int i = 0; i < (n+1)/2; ++i) {
            S += max(0LL, mid-v[i]);
        }
        if(S <= k) ok = mid;
        else ng = mid;
    }
    cout << ok << "\n";
    return 0;
}