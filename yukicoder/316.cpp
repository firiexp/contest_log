#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

ll lcm_(ll a, ll b){
    return a/__gcd(a, b)*b;
}


int main() {
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    cout << n/a+n/b+n/c-n/(lcm_(a, b))-n/(lcm_(b,c))-n/(lcm_(c,a))+n/(lcm_(a, lcm_(b, c)));
    return 0;
}
