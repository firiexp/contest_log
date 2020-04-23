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
    vector<int> v(m);
    for (auto &&j : v) scanf("%d", &j), j--;
    vector<ll> S(n+1), T(n+1);
    for (int i = 0; i+1 < m; ++i) {
        ll a = v[i], b = v[i+1];
        if(a == b) continue;
        tie(a, b) = minmax({a, b});
        S[0] += abs(a-b);
        S[a+1]--;
        S[b]++;
        T[a] += a;
        T[b] += 2*a+1-b;
    }
    partial_sum(S.begin(),S.end(), S.begin());
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%lld", S[i]+T[i]);
    }
    puts("");
    return 0;
}