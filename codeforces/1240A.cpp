#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int q;
    cin >> q;
    while(q--){
        int n; scanf("%d", &n);
        vector<int> v(n);
        for (auto &&i : v) scanf("%d", &i);
        int x, a, y, b; ll k;
        scanf("%d %d %d %d %lld", &x, &a, &y, &b, &k);
        ll o = 0, p = 0;
        for (int i = a-1; i < n; i += a) {
            o += v[i]/100*x;
        }
        for (int i = b-1; i < n; i += b) {
            p += v[i]/100*y;
        }

    }
    return 0;
}