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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> ans(n);
    for (int i = 0; i < q; ++i) {
        int x;
        scanf("%d", &x);
        ans[x-1]++;
    }
    for (int i = 0; i < n; ++i) {
        puts(ans[i]-q+k > 0 ? "Yes" : "No");
    }
    return 0;
}