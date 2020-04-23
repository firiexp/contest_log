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

void solve(){
    int n;
    scanf("%d", &n);
    vector<int> v(n), u(n);
    for (auto &&i : v) scanf("%d", &i);
    for (auto &&j : u) scanf("%d", &j);
    reverse(u.begin(),u.end());
    vector<int> S(n+1), T(n+1);
    map<int, int> m;
    m[0] = n;
    for (int i = 0; i < n; ++i) {
        if(v[i] == 1) S[i+1] = S[i] + 1;
        else S[i+1] = S[i] - 1;
        m[S[i+1]] = n-i-1;
        if(u[i] == 1) T[i+1] = T[i] + 1;
        else T[i+1] = T[i] - 1;
    }
    int ans = INF<int>;
    for (int i = 0; i <= n; ++i) {
        if(m.count(-T[i])){
            ans = min(ans, n-i+m[-T[i]]);
        }
    }
    printf("%d\n", ans);
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}