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

bool f(ll a, ll n, ll k){
    ll sum = 0;
    for (int i = 0; i < n && sum <= k && a; ++i) {
        sum += a;
        a /= 2;
    }
    return sum <= k;
}

int main() {
    ll n, k;
    cin >> n >> k;
    ll ok = 0, ng = k+1;
    while(ng-ok > 1){
        ll mid = ok + (ng-ok)/2;
        if(f(mid, n, k)) ok = mid;
        else ng = mid;
    }
    cout << ok << "\n";
    return 0;
}