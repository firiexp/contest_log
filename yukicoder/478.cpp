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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n-k; ++i) v[i] = ((i&1) == 0 ? i/2+3 : i/2+1);
    for (int i = n-k; i < n; ++i) v[i] = (((n-k-1)&1) == 0 ? (n-k-1)/2+3 : (n-k-1)/2+1);
    for (int i = 0; i < n; ++i) {
        cout << v[i] << "\n";
    }
    return 0;
}
