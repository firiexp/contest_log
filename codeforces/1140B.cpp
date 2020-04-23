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
    int n; string s;
    cin >> n >> s;
    int ans = INF<int>;
    for (int i = 0; i < n; ++i) {
        if(s[i] == '>') ans = min(ans, i);
    }
    for (int i = n-1; i >= 0; --i) {
        if(s[i] == '<') ans = min(ans, n-1-i);
    }
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}