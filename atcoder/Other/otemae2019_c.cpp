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


array<int, 100001> A{}, B{};
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int ans = INF<int>;
    for (int i = 0; i < n; ++i) {
        int b; scanf("%d", &b);
        B[b]++;
    }
    for (int i = 0; i < n; ++i) {
        A[v[i]]++;
        ans = min(ans, B[v[i]]/A[v[i]]);
        printf("%d\n", ans);
    }
    return 0;
}