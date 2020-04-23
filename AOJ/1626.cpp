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

void solve(int n){
    int l = 0, r = 0;
    for (ll i = 1; i*(i+1)/2 <= n; ++i) {
        ll x = n-i*(i+1)/2;
        if(x%i == 0){
            l = x/i, r = i;
        }
    }
    cout << l+1 << " " << r << "\n";
}

int main() {
    int n;
    while(cin >> n, n){
        solve(n);
    }
    return 0;
}