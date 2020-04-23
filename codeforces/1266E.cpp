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
    for (auto &&i : v) scanf("%d", &i);
    ll ans = accumulate(v.begin(),v.end(), 0LL);
    vector<map<int, int>> m(n);
    int q;
    cin >> q;
    while(q--){
        int s, t, u;
        scanf("%d %d %d", &s, &t, &u);
        s--; t--; u--;
        if(m[s].count(t)){
            v[m[s][t]]++;
            if(v[m[s][t]] > 0) ans++;
            m[s].erase(t);
        }
        if(u != -1){
            m[s][t] = u;
            v[u]--;
            if(v[u] >= 0) ans--;
        }
        printf("%lld\n", ans);
    }
    return 0;
}