#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    ll a, b, k, l, m;
    cin >> a >> b >> k >> l;
    m = k/l;
    cout << min(m*b+(k-m*l)*a, (m+1)*b) << "\n";
    return 0;
}
