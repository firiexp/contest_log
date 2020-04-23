#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    ll n, x, a, b;
    cin >> n >> x >> a >> b;
    ll m = (1LL << (n-1));
    cout << min((x+a-1)/a, (m-x+b-1)/b) << "\n";
    return 0;
}
