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
    ll p = 2LL*(n+k);
    for (ll i = 0; i <= 100000; ++i) {
        if(i * (i+3) == p){
            cout << n-i << "\n";
            return 0;
        }
    }
    return 0;
}