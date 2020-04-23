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

ll solve(){
    int n, m;
    cin >> n >> m;
    vector<int> v(n), u(m);
    for (auto &&i : v) scanf("%d", &i), i--;
    for (auto &&j : u) scanf("%d", &j), j--;
    ll ans = 0;
    int cur = 0;
    vector<int> del(n);
    for (int i = 0; i < m; ++i) {
        if(del[u[i]]) {
            ans++;
            continue;
        }
        while(u[i] != v[cur]){
            del[v[cur]]++;
            cur++;
        }
        ans += 2*(cur-i)+1;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        cout << solve() << "\n";
    }
    return 0;
}