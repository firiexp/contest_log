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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    vector<int> a(3), b(3), c(3);
    for (auto &&i : a) scanf("%d", &i);
    for (auto &&j : b) scanf("%d", &j);
    c[0] = (a[0]+a[1])*2, c[1] = (a[1]+a[2])*2, c[2] = (a[2]+a[0])*2;
    sort(b.begin(), b.end());
    sort(c.begin(), c.end(), greater<>());
    cout << inner_product(b.begin(), b.end(), c.begin(), 0) << "\n";
    return 0;
}
