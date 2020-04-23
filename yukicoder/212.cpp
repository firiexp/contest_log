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
    int p, c;
    long double ans = 1;
    cin >> p >> c;
    for (int i = 0; i < p; ++i) {
        ans = ans*41/6;
    }
    for (int i = 0; i < c; ++i) {
        ans = ans*49/6;
    }
    cout << setprecision(15) << ans << "\n";
    return 0;
}
