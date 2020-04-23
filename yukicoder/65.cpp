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
    int k;
    cin >> k;
    array<double, 50> v{};
    v[k] = 0;
    for (int i = k-1; i >= 0; --i) {
        v[i] = 1;
        for (int j = 1; j < 7; ++j) {
            v[i] += v[i+j]/6;
        }
    }
    cout << v[0] << "\n";
    return 0;
}
