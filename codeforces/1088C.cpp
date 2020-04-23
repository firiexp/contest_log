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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i), i += 500000;
    printf("%d\n", n);
    printf("%d %d %d\n", 1, n, 500000);
    for (int i = 0; i < n-1; ++i) {
        printf("%d %d %d\n", 2, i+1, v[i]-i);
    }
    return 0;
}