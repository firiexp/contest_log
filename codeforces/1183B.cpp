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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int l = -INF<int>, r = INF<int>;
    for (int i = 0; i < n; ++i) {
        l = max(l, v[i]-k);
        r = min(r, v[i]+k);
    }
    if(l > r) puts("-1");
    else cout << r << "\n";
}

int main() {
    int q;
    cin >> q;
    while(q--){
        solve();
    }
    return 0;
}