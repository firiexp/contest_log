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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lld", &i);
    for (int i = 0; i < n; ++i) {
        if(v[i] == 0){
            puts("0");
            return 0;
        }
    }
    ll val = 1;
    for (int i = 0; i < n; ++i) {
        (val *= v[i]%9) %= 9;
    }
    cout << (val+8)%9+1 << "\n";
    return 0;
}