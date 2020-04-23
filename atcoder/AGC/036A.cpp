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
    ll s;
    cin >> s;

    cout << "0 0 ";
    ll k = 1000000000;
    if(s == k*k){
        cout << k << " " << 0 << " " << 0 << " " << k << "\n";
        return 0;
    }
    ll l = k-s%k;
    ll m = (s+k)/k;
    cout << k << " " << 1 << " " << l << " " << m << "\n";
    return 0;
}