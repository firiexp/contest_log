#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long double> fact(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i-1]+log10(i);
    }
    long double ans = fact[n]-log10(m)*n;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        ans -= fact[x];
    }
    cout << ceil(-ans) << "\n";
    return 0;
}
