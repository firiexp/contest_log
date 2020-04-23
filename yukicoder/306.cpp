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
    long double a, b, p, q;
    cin >> a >> b >> p >> q;
    cout << setprecision(15) << b+a*(q-b)/(p+a) << "\n";
    return 0;
}
