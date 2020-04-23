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
    ll w, h, n;
    cin >> w >> h >> n;
    map<int, int> a, b;
    for (int i = 0; i < n; ++i) {
        int p, q;
        cin >> p >> q;
        a[p]++;
        b[q]++;
    }
    cout << w*h-(w-a.size())*(h-b.size())-n << "\n";
    return 0;
}
