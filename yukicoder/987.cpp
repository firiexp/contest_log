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
    int n, m;
    cin >> n >> m;
    char c;
    cin >> c;
    vector<ll> v(m), u(n);
    for (auto &&i : v) scanf("%lld", &i);
    for (auto &&j : u) scanf("%lld", &j);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(j) printf(" ");
            printf("%lld", (c == '+' ? u[i]+v[j] : u[i]*v[j]));
        }
        puts("");
    }
    return 0;
}