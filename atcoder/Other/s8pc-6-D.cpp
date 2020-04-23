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
    int n;
    cin >> n;
    vector<long double> x(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> r[i];
    }
    for (int j = 1; j <= 100; j += 1) {
        long double sum = 0;
        long double k = j;
        for (int i = 0; i < n; ++i) {
            k += i;
        }
    }
    return 0;
}
