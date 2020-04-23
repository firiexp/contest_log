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
    for (int i = 1; i <= n-1; ++i) {
        if(k > i){
            k -= i;
        }else {
            string ans(n, 'a');
            ans[n-i-1] = 'b';
            ans[n-k] = 'b';
            cout << ans << "\n";
            return;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}