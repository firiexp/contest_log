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
    int n, t;
    cin >> n >> t;
    int s = 0;
    for (int i = 0; i < n-1; ++i) {
        int x;
        cin >> x;
        s += x;
    }
    cout << (s+t-1)/t << "\n";
    return 0;
}
