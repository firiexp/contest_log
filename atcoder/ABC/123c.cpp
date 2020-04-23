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
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    ll n;
    cin >> n;
    vector<ll> ans(6), v(5);
    for (auto &&j : v) scanf("%lli", &j);
    ll ansa = *min_element(v.begin(), v.end());
    cout << (n+ansa-1)/ansa+4 << "\n";
    return 0;
}
