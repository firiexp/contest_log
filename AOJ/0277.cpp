#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int a[] = {0, 6000, 4000, 3000, 2000};
    for (int i = 0; i < 4; ++i) {
        int t, n;
        cin >> t >> n;
        cout << a[t]*n << "\n";
    }
    return 0;
}