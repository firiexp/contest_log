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
    ll n, a, b;
    cin >> n >> a >> b;
    n %= 12;
    for (int i = 0; i < n; ++i) {
        if(i&1) b += a;
        else a -= b;
    }
    cout << a << " " << b << "\n";
    return 0;
}