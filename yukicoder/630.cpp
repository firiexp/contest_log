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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    ll n, m;
    cin >> n >> m;
    ll l = (n + 1) / 2, r = n - l;
    if (m < n - 1 || l * r < m) {
        puts("NO");
        return 0;
    }
    puts("YES");
    vector<int> val(n);
    int cnt = 1;
    for (int i = 0; i < n; i += 2) {
        val[i] = cnt++;
    }
    for (int i = 1; i < n; i += 2) {
        val[i] = cnt++;
    }
    for (int i = 0; i < n; ++i) {
        if (i) printf(" ");
        printf("%d", val[i]);
    }
    puts("");
    for (int i = 0; i < n - 1; ++i) {
        printf("%d %d\n", i + 1, i + 2);
    }
    m -= n - 1;
    for (int i = 1; i <= n; i += 2) {
        for (int j = 2; j <= n; j += 2) {
            if (!m) {
                i = n + 1, j = n + 1;
            } else if (abs(i-j) == 1) {
            } else {
                printf("%d %d\n", i, j);
                m--;
            }
        }
    }
    return 0;
}