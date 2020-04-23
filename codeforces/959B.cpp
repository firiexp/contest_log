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
    int k, n, m;
    cin >> n >> k >> m;
    vector<string> S(n);
    vector<int> v(n);
    for(auto &&i : S) cin >> i;
    for (auto &&j : v) scanf("%d", &j);
    for (int i = 0; i < k; ++i) {
        int x;
        scanf("%d", &x);
        vector<int> A(x);
        int val = INF<int>;
        for (auto &&l : A) scanf("%d", &l), val = min(val, v[l-1]);
        for (int j = 0; j < x; ++j) {
            v[A[j]-1] = val;
        }
    }
    map<string, int> A;
    for (int i = 0; i < n; ++i) {
        A[S[i]] = v[i];
    }
    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        ans += A[s];
    }
    cout << ans << "\n";
    return 0;
}